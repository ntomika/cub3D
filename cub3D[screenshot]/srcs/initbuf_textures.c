#include "header.h"

void	load_image(t_all *all, int *texture, char *path)
{
	int	x;
	int	y;

	all->img.img = mlx_xpm_file_to_image(all->img.mlx, path, &all->key.w2,
			&all->key.h2);
	if (!all->img.img)
		return (0);
	if (all->key.w2 > 64 || all->key.h2 > 64)
	{
		get_error("Textures error");
		quit(all);
	}
	all->img.addr = (int *)mlx_get_data_addr(all->img.img,
			&all->img.bits_per_pixel,
			&all->img.line_length,
			&all->img.endian);
	y = -1;
	while (++y < all->key.h2)
	{
		x = -1;
		while (++x < all->key.w2)
			texture[all->key.w2 * y + x]
				= all->img.addr[all->key.w2 * y + x];
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
	free(all->key.NO_texture);
	free(all->key.SO_texture);
	free(all->key.WE_texture);
	free(all->key.EA_texture);
	free(all->key.S_texture);
}

int	init_bufer(t_all *all)
{
	int	i;
	int	j;

	all->gr.bufer = (int **)malloc(sizeof(int *) * all->key.h);
	if (!all->gr.bufer)
		return (0);
	i = -1;
	while (++i < all->key.h)
	{
		all->gr.bufer[i] = (int *)malloc(sizeof(int) * all->key.w);
		if (!all->gr.bufer[i])
			return (0);
	}
	i = -1;
	while (++i < all->key.h)
	{
		j = -1;
		ft_bzero(all->gr.bufer[i], all->key.w);
	}
	return (1);
}

int	init_buf(t_all *all)
{
	int	i;
	int	j;

	if (!init_bufer(all))
		return (0);
	i = -1;
	while (++i < 5)
	{
		all->gr.texture[i] = (int *)malloc(sizeof(int)
				* (TEXTUREH * TEXTUREW));
		if (!all->gr.texture[i])
			return (0);
	}
	i = -1;
	while (++i < 5)
	{
		j = -1;
		while (++j < TEXTUREH * TEXTUREW)
			all->gr.texture[i][j] = 0;
	}
	all->gr.zBuffer = (float *)malloc(sizeof(float) * all->key.w);
	if (!all->gr.zBuffer)
		return (0);
	load_textures(all);
	return (1);
}
