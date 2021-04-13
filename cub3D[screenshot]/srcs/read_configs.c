#include "header.h"

void	init_key(t_all *all)
{
	all->keycap.k_a = 0;
	all->keycap.k_s = 0;
	all->keycap.k_d = 0;
	all->keycap.k_w = 0;
	all->keycap.k_esc = 0;
	all->keycap.k_l = 0;
	all->keycap.k_r = 0;
}

int	get_conf_2(t_all *all, char **argv, int argc)
{
	int	fd;
	int	i;

	fd = open(argv[1], O_RDONLY);
	all->conf = (char **)malloc(sizeof(char *) * (all->size + 1));
	if (!all->conf)
	{
		get_error("Failed to allocate memory");
		return (0);
	}
	i = -1;
	while (++i < all->size)
		get_next_line(fd, &all->conf[i]);
	get_next_line(fd, &all->conf[i]);
	close(fd);
	if (argc == 3)
		get_screen(all, argv);
	return (1);
}

int	get_conf(char **argv, int argc, t_all *all)
{
	int		fd;
	char	*line;

	if (argc == 2 || argc == 3)
		fd = open(argv[1], O_RDONLY);
	else
	{
		get_error("Invalid \"*.cub\" arguments");
		exit(0);
	}
	line = NULL;
	while (get_next_line(fd, &line))
	{
		if (*line == ' ' || *line == '1')
			all->sizemap++;
		all->size++;
		free(line);
		line = NULL;
	}
	free(line);
	close(fd);
	if (!get_conf_2(all, argv, argc))
		return (0);
	return (1);
}

int	general(t_all *all)
{
	all->img.mlx = mlx_init();
	if (!(check_valid(all)))
		return (0);
	if (!plr_bihavior(all))
		return (0);
	if (!search_sprites(all))
		return (0);
	all->img.win = mlx_new_window(all->img.mlx,
			all->key.w, all->key.h, "cub3D");
	if (!init_buf(all))
	{
		get_error("Failed to allocate memory");
		return (0);
	}
	init_key(all);
	all->img.img = mlx_new_image(all->img.mlx,
			all->key.w, all->key.h);
	all->img.addr = (int *)mlx_get_data_addr(all->img.img,
			&all->img.bits_per_pixel,
			&all->img.line_length,
			&all->img.endian);
	return (1);
}

int	main(int argc, char **argv)
{
	t_all	all;

	all.size = 1;
	all.sizemap = 1;
	if (!(get_conf(argv, argc, &all)))
		return (0);
	if (!general(&all))
		return (0);
	mlx_loop_hook(all.img.mlx, &counting, &all);
	mlx_hook(all.img.win, 2, 1L << 0, &key_press, &all);
	mlx_hook(all.img.win, 3, 1L << 1, &key_release, &all);
	mlx_hook(all.img.win, 17, 1L << 0, &quit, &all);
	mlx_loop(all.img.mlx);
	return (1);
}
