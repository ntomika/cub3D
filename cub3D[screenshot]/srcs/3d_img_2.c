#include "header.h"

int	counting(t_all *all)
{
	img_3d(all);
	print(all);
	key_update(all);
	return (1);
}

void	step_and_side(t_all *all)
{
	if (all->gr.rayDirX < 0)
	{
		all->gr.stepX = -1;
		all->gr.sideDistX = (all->gr.posX - all->gr.mapX)
			* all->gr.deltaDistX;
	}
	else
	{
		all->gr.stepX = 1;
		all->gr.sideDistX = (all->gr.mapX + 1.0 - all->gr.posX)
			* all->gr.deltaDistX;
	}
	if (all->gr.rayDirY < 0)
	{
		all->gr.stepY = -1;
		all->gr.sideDistY = (all->gr.posY - all->gr.mapY)
			* all->gr.deltaDistY;
	}
	else
	{
		all->gr.stepY = 1;
		all->gr.sideDistY = (all->gr.mapY + 1.0 - all->gr.posY)
			* all->gr.deltaDistY;
	}
}

void	dda(t_all *all)
{
	int	hit;

	hit = 0;
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
		if (all->map[all->gr.mapX][all->gr.mapY] == '1')
			hit = 1;
	}
}

void	calc_wall(t_all *all)
{
	if (all->gr.side == 0)
		all->gr.perpWallDist = (all->gr.mapX - all->gr.posX
				+ (1 - all->gr.stepX) / 2) / all->gr.rayDirX;
	else
		all->gr.perpWallDist = (all->gr.mapY - all->gr.posY
				+ (1 - all->gr.stepY) / 2) / all->gr.rayDirY;
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
}

void	texture(t_all *all)
{
	all->gr.texX = (int)(all->gr.WallX * (float)TEXTUREW);
	if (all->gr.side == 0 && all->gr.rayDirX > 0)
		all->gr.index = 0;
	if (all->gr.side == 0 && all->gr.rayDirX < 0)
		all->gr.index = 1;
	if (all->gr.side == 1 && all->gr.rayDirY > 0)
		all->gr.index = 2;
	if (all->gr.side == 1 && all->gr.rayDirY < 0)
		all->gr.index = 3;
	all->gr.step = 1.0 * TEXTUREH / all->gr.lineHeight;
	all->gr.texPos = (all->gr.drawStart - all->key.h
			/ 2 + all->gr.lineHeight / 2) * all->gr.step;
}
