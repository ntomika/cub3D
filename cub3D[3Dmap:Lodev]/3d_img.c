#include "header.h"

void	my_mlx_pixel_put(t_all *all, int x, int y, long long color)
{
	char	*dst;

	dst = all->img.addr + (y * all->img.line_length + x * (all->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void init_plr(t_all *all)
{
	all->gr.posX = all->plr.player_x;
	all->gr.posY = all->plr.player_y;
	all->gr.dirX = -1;
	all->gr.dirY = 0;
	all->gr.planeX = 0;
	all->gr.planeY = 0.66;
	all->gr.moveSpeed = 0.1;
	all->gr.rotSpeed = 0.1;
}

void	print_column(t_all *all, int x, int y1, int y2, long color)
{
	int	y = 0;

//	y = y1;
	while (y <= all->key.h)
	{
		if (y < y1)
			my_mlx_pixel_put(all, x, y, all->color.ceiling);
		if (y >= y1 && y < y2)
			my_mlx_pixel_put(all, x, y, color);
//		if (y > y2)
//			my_mlx_pixel_put(all, x, y, all->color.floor);
		y++;
	}
}

int 	img_3d(t_all *all)
{
	all->img.img = mlx_new_image(all->img.mlx, all->key.w, all->key.h);
	all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel,
									  &all->img.line_length,
									  &all->img.endian);
	int x = 0;

	while (x < all->key.w)
	{
		all->gr.cameraX = 2 * x / (float)all->key.w - 1;
		all->gr.rayDirX = all->gr.dirX + all->gr.planeX * all->gr.cameraX;
		all->gr.rayDirY = all->gr.dirY + all->gr.planeY * all->gr.cameraX;

		all->gr.mapX = (int)all->gr.posX;
		all->gr.mapY = (int)all->gr.posY;

		all->gr.deltaDistX = fabs(1 / all->gr.rayDirX);
		all->gr.deltaDistY = fabs(1 / all->gr.rayDirY);

		int hit = 0;

		if (all->gr.rayDirX < 0)
		{
			all->gr.stepX = -1;
			all->gr.sideDistX = (all->gr.posX - all->gr.mapX) * all->gr.deltaDistX;
		}
		else
		{
			all->gr.stepX = 1;
			all->gr.sideDistX = (all->gr.mapX + 1 - all->gr.posX) * all->gr.deltaDistX;
		}
		if (all->gr.rayDirY < 0)
		{
			all->gr.stepY = -1;
			all->gr.sideDistY = (all->gr.posY - all->gr.mapY) * all->gr.deltaDistY;
		}
		else
		{
			all->gr.stepY = 1;
			all->gr.sideDistY = (all->gr.mapY + 1.0 - all->gr.posY) * all->gr.deltaDistY;
		}

		while (hit == 0)
		{
			if (all->gr.sideDistX < all->gr.sideDistY)
			{
				all->gr.sideDistX += all->gr.deltaDistX;
				all->gr.mapX += all->gr.stepX;
				all->gr.side = 0;
			}
			else
			{
				all->gr.sideDistY += all->gr.deltaDistY;
				all->gr.mapY += all->gr.stepY;
				all->gr.side = 1;
			}
			if (all->map[all->gr.mapX][all->gr.mapY] > '0')
				hit = 1;
		}
		if (all->gr.side == 0)
			all->gr.perpWallDist = (all->gr.mapX - all->gr.posX + (1 - all->gr.stepX) / 2) / all->gr.rayDirX;
		else
			all->gr.perpWallDist = (all->gr.mapY - all->gr.posY + (1 - all->gr.stepY) / 2) / all->gr.rayDirY;

		all->gr.lineHeight = (int)(all->key.h / all->gr.perpWallDist);

		all->gr.drawStart = -all->gr.lineHeight / 2 + all->key.h / 2;
		if (all->gr.drawStart < 0)
			all->gr.drawStart = 0;
		all->gr.drawEnd = all->gr.lineHeight /2 + all->key.h / 2;
		if (all->gr.drawEnd >= all->key.h)
			all->gr.drawEnd = all->key.h - 1;

		int color;

		if (all->map[all->gr.mapX][all->gr.mapY] == '1')
			color = 0x00FF0000;
//		else if (all->map[all->gr.mapX][all->gr.mapY] == '2')
//			color = 0x0000FF00;

		if (all->gr.side == 1)
			color = color / 3;

		print_column(all, x, all->gr.drawStart, all->gr.drawEnd, color);

		x++;
	}
	mlx_put_image_to_window(all->img.mlx, all->img.win, all->img.img, 0, 0);
	return(1);
}

void	left_right(int *key, t_all *all)
{
	if (*key == 123)
	{
		all->gr.oldDirX = all->gr.dirX;
		all->gr.dirX = all->gr.dirX * cos(all->gr.rotSpeed) - all->gr.dirY * sin(all->gr.rotSpeed);
		all->gr.dirY = all->gr.oldDirX * sin(all->gr.rotSpeed) + all->gr.dirY * cos(all->gr.rotSpeed);
		all->gr.oldPlaneX = all->gr.planeX;
		all->gr.planeX = all->gr.planeX * cos(all->gr.rotSpeed) - all->gr.planeY * sin(all->gr.rotSpeed);
		all->gr.planeY = all->gr.oldPlaneX * sin(all->gr.rotSpeed) + all->gr.planeY * cos(all->gr.rotSpeed);
	}
	if (*key == 124)
	{
		all->gr.oldDirX = all->gr.dirX;
		all->gr.dirX = all->gr.dirX * cos(-all->gr.rotSpeed) - all->gr.dirY * sin(-all->gr.rotSpeed);
		all->gr.dirY = all->gr.oldDirX * sin(-all->gr.rotSpeed) + all->gr.dirY * cos(-all->gr.rotSpeed);
		all->gr.oldPlaneX = all->gr.planeX;
		all->gr.planeX = all->gr.planeX * cos(-all->gr.rotSpeed) - all->gr.planeY * sin(-all->gr.rotSpeed);
		all->gr.planeY = all->gr.oldPlaneX * sin(-all->gr.rotSpeed) + all->gr.planeY * cos(-all->gr.rotSpeed);
	}
}

int		key_press(int key, t_all *all)
{
	if (key == 13)		// W
	{
		if (all->map[(int)(all->gr.posX + all->gr.dirX * all->gr.moveSpeed)][(int)(all->gr.posY)] != '1')
			all->gr.posX += all->gr.dirX * all->gr.moveSpeed;
		if (all->map[(int)(all->gr.posX)][(int)(all->gr.posY + all->gr.dirY * all->gr.moveSpeed)] != '1')
			all->gr.posY += all->gr.dirY * all->gr.moveSpeed;
	}
	if (key == 1)		// S
	{
		if (all->map[(int)(all->gr.posX - all->gr.dirX * all->gr.moveSpeed)][(int)(all->gr.posY)] != '1')
			all->gr.posX -= all->gr.dirX * all->gr.moveSpeed;
		if (all->map[(int)(all->gr.posX)][(int)(all->gr.posY - all->gr.dirY * all->gr.moveSpeed)] != '1')
			all->gr.posY -= all->gr.dirY * all->gr.moveSpeed;
	}
//	if (key == 0)		// A
//	{
//		if (all->map[(int)(all->gr.posX - all->gr.dirX * all->gr.moveSpeed)][(int)(all->gr.posY)] != '1')
//			all->gr.posX -= (all->gr.dirX + M_PI_2) * all->gr.moveSpeed;
//		if (all->map[(int)(all->gr.posX)][(int)(all->gr.posY - all->gr.dirY * all->gr.moveSpeed)] != '1')
//			all->gr.posY -= (all->gr.dirY + M_PI_2) * all->gr.moveSpeed;
//	}
//	if (key == 2)		// D
//	{
//		if (all->map[(int)(all->gr.posX + all->gr.dirX * all->gr.moveSpeed)][(int)(all->gr.posY)] != '1')
//			all->gr.posX += (all->gr.dirX + M_PI_2) * all->gr.moveSpeed;
//		if (all->map[(int)(all->gr.posX)][(int)(all->gr.posY + all->gr.dirY * all->gr.moveSpeed)] != '1')
//			all->gr.posY += (all->gr.dirY + M_PI_2) * all->gr.moveSpeed;
//	}
	if (key == 53)
		exit(0);
	left_right(&key, all);
	return (1);
}