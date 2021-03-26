#include "header.h"

void	load_image(t_all *all, int *texture, char *path)
{
	all->key.w2 = 64;
	all->key.h2 = 64;
	if (!(all->img.img = mlx_xpm_file_to_image(all->img.mlx, path, &all->key.w2, &all->key.h2)))
		return ;
	all->img.addr = (int *)mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel,
											 &all->img.line_length,
											 &all->img.endian);
	for (int y = 0; y < all->key.h2; y++)
	{
		for (int x = 0; x < all->key.w2; x++)
		{
			texture[all->key.w2 * y + x] = all->img.addr[all->key.w2 * y + x];
		}
	}
	mlx_destroy_image(all->img.mlx, all->img.img);
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
	all->gr.bufer = (int **)malloc(sizeof(int *) * all->key.h);
	for (int i = 0; i < all->key.h; i++)
	{
		all->gr.bufer[i] = (int *)malloc(sizeof(int) * all->key.w);
	}

	for (int i = 0; i < all->key.h; i++)
	{
		for (int j = 0; j < all->key.w; j++)
		{
			all->gr.bufer[i][j] = 0;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (!(all->gr.texture[i] = (int *)malloc(sizeof(int) * (TEXTUREH * TEXTUREW))))
			return ;
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < TEXTUREH * TEXTUREW; j++)
		{
			all->gr.texture[i][j] = 0;
		}
	}
	load_textures(all);
}