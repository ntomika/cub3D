/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_img_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <ntomika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 19:10:53 by ntomika           #+#    #+#             */
/*   Updated: 2021/04/07 21:36:04 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	load_image(t_all *all, int *texture, char *path)
{
	int x;
	int y;

	all->key.w2 = 0;
	all->key.h2 = 0;
	if (!(all->img.img = mlx_xpm_file_to_image(all->img.mlx, path, &all->key.w2,
											&all->key.h2)))
		return (0);
	all->img.addr = (int *)mlx_get_data_addr(all->img.img,
											&all->img.bits_per_pixel,
											&all->img.line_length,
											&all->img.endian);
	y = -1;
	while (++y < all->key.h2)
	{
		x = -1;
		while (++x < all->key.w2)
			texture[all->key.w2 * y + x] = all->img.addr[all->key.w2 * y + x];
	}
	mlx_destroy_image(all->img.mlx, all->img.img);
	return (1);
}

void	load_textures(t_all *all)
{
	load_image(all, all->gr.texture[0], all->key.NO_texture);
	load_image(all, all->gr.texture[1], all->key.SO_texture);
	load_image(all, all->gr.texture[2], all->key.WE_texture);
	load_image(all, all->gr.texture[3], all->key.EA_texture);
	load_image(all, all->gr.texture[4], all->key.S_texture);
}

void	init_buf(t_all *all)
{
	int i;
	int j;

	i = -1;
	all->gr.bufer = (int **)malloc(sizeof(int *) * all->key.h);
	while (++i < all->key.h)
		all->gr.bufer[i] = (int *)malloc(sizeof(int) * all->key.w);
	i = -1;
	while (++i < all->key.h)
	{
		j = -1;
		while (++j < all->key.w)
			all->gr.bufer[i][j] = 0;
	}
	for (int i = 0; i < 5; i++)
	{
		if (!(all->gr.texture[i] = (int *)malloc(sizeof(int) * (TEXTUREH * TEXTUREW))))
			return ;
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < TEXTUREH * TEXTUREW; j++)
		{
			all->gr.texture[i][j] = 0;
		}
	}
	all->gr.zBuffer = (float *)malloc(sizeof(float) * all->key.w);
	load_textures(all);
}
