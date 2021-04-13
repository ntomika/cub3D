#include "header.h"

int		print_square(t_all *all, int k, int l, unsigned int color)
{
	int i;
	int j = -1;

	while (++j < SCALE)
	{
		i = -1;
		while (++i < SCALE)
			my_mlx_pixel_put(all, j + k * SCALE, i + l * SCALE, color);
			// all->gr.bufer[i + l][j + k] = color;
	}
	return (0);
}

void 	drow_map(t_all *all)
{
	int i = -1;
	while (++i < all->sizemap)
	{
		int j = -1;
		while (all->map[i][++j])
		{
			if (all->map[i][j] == '1')
				print_square(all, j, i, 0x00FFFFFF);
			if (all->map[i][j] == '2')
				print_square(all, j, i, 0x0000FFF0);
		}
	}
	mlx_put_image_to_window(all->img.mlx, all->img.win, all->img.img, 0, 0);
}