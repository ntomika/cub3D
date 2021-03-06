/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <ntomika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:45:14 by ntomika           #+#    #+#             */
/*   Updated: 2021/03/27 21:19:00 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int get_conf(char **argv, int argc, t_all *all)
{
	int fd;
	int i;
	char *line;

	line = NULL;
	i = 0;
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

	all.img.mlx = mlx_init();
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

	if (!plr_bihavior(&all))
	{
		get_free_map(&all);
		get_free_conf(&all);
		return (0);
	}
	init_plr(&all);
	search_sprites(&all);
	all.img.win = mlx_new_window(all.img.mlx, all.key.w, all.key.h, "cub3D");
	init_buf(&all);
	init_key(&all);
	all.img.img = mlx_new_image(all.img.mlx, all.key.w, all.key.h);
	all.img.addr = (int *)mlx_get_data_addr(all.img.img, &all.img.bits_per_pixel,
											 &all.img.line_length,
											 &all.img.endian);
	mlx_loop_hook(all.img.mlx, &counting, &all);
	mlx_hook(all.img.win, 2, 1L << 0, &key_press, &all);
	mlx_hook(all.img.win, 3, 1L << 1, &key_release, &all);
	// mlx_hook(all.img.win, 3, 1L << 1, &key_release, &all);
	// mlx_hook(all.img.win, 17, 1L << 0, &quit, &all);
	mlx_loop(all.img.mlx);
	return (1);
}