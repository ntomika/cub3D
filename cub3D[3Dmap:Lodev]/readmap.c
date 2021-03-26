#include "header.h"

void check_player(t_all *all)
{
	if (all->plr.poz == 'N')
		all->plr.player_a = 3 * M_PI_2;
	if (all->plr.poz == 'S')
		all->plr.player_a = M_PI_2;
	if (all->plr.poz == 'E')
		all->plr.player_a = M_2_PI;
	if (all->plr.poz == 'W')
		all->plr.player_a = M_PI;
}

int plr_bihavior(t_all *all)
{
	int i = -1;
	int flag = 0;
	while (all->map[++i])
	{
		int j = -1;
		while (all->map[i][++j])
		{
			if (ft_strchr("NSWE", all->map[i][j]))
			{
				all->plr.player_x = i;
				all->plr.player_y = j;
				all->plr.poz = all->map[i][j];
				check_player(all);
				flag++;
				all->map[i][j] = '0';
			}
		}
	}
	if (flag > 1 || flag == 0)
	{
		get_error("The map must contain one player");
		return (0);
	}
	return (1);
}

int get_conf(char **argv, int argc, t_all *all)
{
	int fd;
	int i = 0;
	char *line = NULL;

	all->size = 1;
	all->sizemap = 1;
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
	{
		get_error("Invalid argument \"*.cub\"");
		exit(0);
	}
	while (get_next_line(fd, &line))
	{
		if (*line == ' ' || *line == '1')
			all->sizemap++;
		all->size++;
		line = NULL;
	}
	close(fd);
	fd = open(argv[1], O_RDONLY);
	if (!(all->conf = (char **)malloc(sizeof(char *) * (all->size + 1))))
	{
		get_error("Failed to allocate memory");
		return (0);
	}
	while (i < all->size)
	{
		get_next_line(fd, &all->conf[i]);
		i++;
	}
	get_next_line(fd, &all->conf[i]);
	close(fd);

	//	i = -1;
	//	printf("conf :\n");
	//	while (all->conf[++i])
	//		printf("%s\n", all->conf[i]);
	//	write(1, "\n", 1);

	return (1);
}

int main(int argc, char **argv)
{
	t_all all;

	if (!(get_conf(argv, argc, &all)))
	{
		get_free_conf(&all);
		return (0);
	}
	if (!(check_valid(&all)))
	{
		// get_free_map(&all);
		// get_free_conf(&all);
		return (0);
	}
	all.img.mlx = mlx_init();
	all.img.win = mlx_new_window(all.img.mlx, all.key.w, all.key.h, "cub3D");

	if (!plr_bihavior(&all))
	{
		get_free_map(&all);
		get_free_conf(&all);
		return (0);
	}
//	img_3d(&all);
	init_plr(&all);
	mlx_loop_hook(all.img.mlx, &img_3d, &all);
	mlx_hook(all.img.win, 2, 1L << 0, &key_press, &all);
	mlx_loop(all.img.mlx);
	return (1);
}