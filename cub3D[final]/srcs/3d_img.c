#include "header.h"

void	print(t_all *all)
{
	int	y;
	int	x;

	y = -1;
	while (++y < all->key.h)
	{
		x = -1;
		while (++x < all->key.w)
			all->img.addr[y * all->key.w + x] = all->gr.bufer[y][x];
	}
	mlx_put_image_to_window(all->img.mlx, all->img.win, all->img.img, 0, 0);
}

void	drow_ceiling(t_all *all, int x, int *y)
{
	long	color;

	while (*y < all->gr.drawStart)
	{
		color = all->color.ceiling;
		all->gr.bufer[*y][x] = color;
		*y += 1;
	}
}

void	drow_floor(t_all *all, int x, int *y)
{
	long	color;

	while (*y >= all->gr.drawEnd && *y < all->key.h)
	{
		color = all->color.floor;
		all->gr.bufer[*y][x] = color;
		*y += 1;
	}
}

void	screen_buf(t_all *all, int x)
{
	int		y;
	long	color;

	y = 0;
	drow_ceiling(all, x, &y);
	while (y++ < all->gr.drawEnd)
	{
		all->gr.texY = (int)all->gr.texPos & (TEXTUREH - 1);
		all->gr.texPos += all->gr.step;
		if (all->gr.index == 0)
			color = all->gr.texture[all->gr.index][TEXTUREH
				* all->gr.texY + all->gr.texX];
		else if (all->gr.index == 1)
			color = all->gr.texture[all->gr.index][TEXTUREH
				* all->gr.texY + all->gr.texX];
		else if (all->gr.index == 2)
			color = all->gr.texture[all->gr.index][TEXTUREH
				* all->gr.texY + all->gr.texX];
		else if (all->gr.index == 3)
			color = all->gr.texture[all->gr.index][TEXTUREH
				* all->gr.texY + all->gr.texX];
		all->gr.bufer[y][x] = color;
	}
	drow_floor(all, x, &y);
}

void 	img_3d(t_all *all)
{
	int	x;

	x = -1;
	while (++x < all->key.w)
	{
		all->gr.cameraX = 2 * x / (float)all->key.w - 1;
		all->gr.rayDirX = all->gr.dirX + all->gr.planeX * all->gr.cameraX;
		all->gr.rayDirY = all->gr.dirY + all->gr.planeY * all->gr.cameraX;
		all->gr.mapX = (int)all->gr.posX;
		all->gr.mapY = (int)all->gr.posY;
		all->gr.deltaDistX = fabs(1 / all->gr.rayDirX);
		all->gr.deltaDistY = fabs(1 / all->gr.rayDirY);
		step_and_side(all);
		dda(all);
		calc_wall(all);
		texture(all);
		screen_buf(all, x);
		all->gr.zBuffer[x] = all->gr.perpWallDist;
	}
	get_sprite(all);
}
