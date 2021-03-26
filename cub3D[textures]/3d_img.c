#include "header.h"

void init_plr(t_all *all)
{
	all->gr.posX = all->plr.player_x;
	all->gr.posY = all->plr.player_y;
}

void	print(t_all *all, int x)
{
	int y = -1;
	while (++y <= all->key.h)
	{
		if (y < all->gr.drawStart)
			all->img.addr[y * all->key.w + x] = all->color.ceiling;
		if (y > all->gr.drawStart && y < all->gr.drawEnd)
			all->img.addr[y * all->key.w + x] = all->gr.bufer[y][x];
		if (y >= all->gr.drawEnd && y < all->key.h)
			all->img.addr[y * all->key.w + x] = all->color.floor;
	}
}

void 	img_3d(t_all *all)
{
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

		if (all->gr.rayDirX < 0)
		{
			all->gr.stepX = -1;
			all->gr.sideDistX = (all->gr.posX - all->gr.mapX) * all->gr.deltaDistX;
		}
		else
		{
			all->gr.stepX = 1;
			all->gr.sideDistX = (all->gr.mapX + 1.0 - all->gr.posX) * all->gr.deltaDistX;
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

		// printf("all->gr.sideDistX = %f\n", all->gr.sideDistX);
		// printf("all->gr.sideDistY = %f\n", all->gr.sideDistY);

		int hit = 0;
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
			if (all->map[all->gr.mapX][all->gr.mapY] != '0')
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
		all->gr.drawEnd = all->gr.lineHeight / 2 + all->key.h / 2;
		if (all->gr.drawEnd >= all->key.h)
			all->gr.drawEnd = all->key.h - 1;

		if (all->gr.side == 0)
			all->gr.WallX = all->gr.posY + all->gr.perpWallDist * all->gr.rayDirY;
		else
			all->gr.WallX = all->gr.posX + all->gr.perpWallDist * all->gr.rayDirX;
		all->gr.WallX -= floor(all->gr.WallX);

		all->gr.texX = (int)(all->gr.WallX * (float)TEXTUREW);

		// if (all->gr.side == 0 && all->gr.rayDirX > 0)
		// 	all->gr.texX = TEXTUREW - all->gr.texX - 1;
		// if (all->gr.side == 1 && all->gr.rayDirY < 0)
		// 	all->gr.texX = TEXTUREW - all->gr.texX - 1;

		if (all->gr.side == 0 && all->gr.rayDirX > 0)
			all->gr.index = 0;
		if (all->gr.side == 0 && all->gr.rayDirX < 0)
			all->gr.index = 1;
		if (all->gr.side == 1 && all->gr.rayDirY > 0)
			all->gr.index = 2;
		if (all->gr.side == 1 && all->gr.rayDirY < 0)
			all->gr.index = 3;

		all->gr.step = 1.0 * TEXTUREH / all->gr.lineHeight;

		all->gr.texPos = (all->gr.drawStart - all->key.h / 2 + all->gr.lineHeight / 2) * all->gr.step;

		int y = all->gr.drawStart;
		while (y < all->gr.drawEnd)
		{
			all->gr.texY = (int)all->gr.texPos & (TEXTUREH - 1);
			all->gr.texPos += all->gr.step;
			int color = 0;
			// int color = all->gr.texture[all->gr.texN][TEXTUREH * all->gr.texY + all->gr.texX];
			if (all->gr.index == 0)
				color = all->gr.texture[all->gr.index][TEXTUREH * all->gr.texY + all->gr.texX];
			else if (all->gr.index == 1)
				color = all->gr.texture[all->gr.index][TEXTUREH * all->gr.texY + all->gr.texX];
			else if (all->gr.index == 2)
				color = all->gr.texture[all->gr.index][TEXTUREH * all->gr.texY + all->gr.texX];
			else if (all->gr.index == 3)
				color = all->gr.texture[all->gr.index][TEXTUREH * all->gr.texY + all->gr.texX];
			all->gr.bufer[y][x] = color;
			y++;
		}
		print(all, x);
		x++;
	}
}

int		counting(t_all *all)
{
	img_3d(all);
	// print(all);
	mlx_put_image_to_window(all->img.mlx, all->img.win, all->img.img, 0, 0);
	return (0);
}