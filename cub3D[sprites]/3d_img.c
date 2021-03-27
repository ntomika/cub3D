#include "header.h"

void init_plr(t_all *all)
{
	all->gr.posX = all->plr.player_x;
	all->gr.posY = all->plr.player_y;
}

void	print(t_all *all)
{
	int y = -1;
	while (++y < all->key.h)
	{
		int x = -1;
		while (++x <= all->key.w)
			all->img.addr[y * all->key.w + x] = all->gr.bufer[y][x];
	}
	mlx_put_image_to_window(all->img.mlx, all->img.win, all->img.img, 0, 0);
}

void	sort_order(t_pair *orders, int amount)
{
	t_pair	tmp;

	for (int i = 0; i < amount; i++)
	{
		for (int j = 0; j < amount - 1; j++)
		{
			if (orders[j].first > orders[j + 1].first)
			{
				tmp.first = orders[j].first;
				tmp.second = orders[j].second;
				orders[j].first = orders[j + 1].first;
				orders[j].second = orders[j + 1].second;
				orders[j + 1].first = tmp.first;
				orders[j + 1].second = tmp.second;
			}
		}
	}
}

void	sortSprites(int *order, float *dist, int amount)
{
	t_pair *sprites;

	sprites = (t_pair*)malloc(sizeof(t_pair) * amount);
	for (int i = 0; i < amount; i++)
	{
		sprites[i].first = dist[i];
		sprites[i].second = order[i];
	}
	sort_order(sprites, amount);
	for (int i = 0; i < amount; i++)
	{
		dist[i] = sprites[amount - i - 1].first;
		order[i] = sprites[amount - i - 1].second;
	}
	free(sprites);
}

void 	img_3d(t_all *all)
{
	int x = -1;

	while (++x < all->key.w)
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
			if (all->map[all->gr.mapX][all->gr.mapY] == '1')
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


		int y = 0;
		long color;
		while (y++ < all->gr.drawStart)
		{
			color = all->color.ceiling;
			all->gr.bufer[y][x] = color;
		}
		y = all->gr.drawStart;
		while (y < all->gr.drawEnd)
		{
			all->gr.texY = (int)all->gr.texPos & (TEXTUREH - 1);
			all->gr.texPos += all->gr.step;
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
		while (y >= all->gr.drawEnd && y < all->key.h)
		{
			color = all->color.floor;
			all->gr.bufer[y][x] = color;
			y++;
		}
		all->gr.zBuffer[x] = all->gr.perpWallDist;
	}


	int		spriteOrder[all->key.numSprites];
	float	spriteDistance[all->key.numSprites];
	int		i;

	i = -1;
	while (++i < all->key.numSprites)
	{
			spriteOrder[i] = i;
			spriteDistance[i] = ((all->gr.posX - all->spr.poz_sprite_x[i]) * (all->gr.posX - all->spr.poz_sprite_x[i]) + 
				(all->gr.posY - all->spr.poz_sprite_y[i]) * (all->gr.posY - all->spr.poz_sprite_y[i]));
	}
	sortSprites(spriteOrder, spriteDistance, all->key.numSprites);

	i = -1;
	while (++i < all->key.numSprites)
	{
		all->spr.spriteX = all->spr.poz_sprite_x[spriteOrder[i]] - all->gr.posX;
		all->spr.spriteY = all->spr.poz_sprite_y[spriteOrder[i]]  - all->gr.posY;

		all->spr.invDet = 1.0 / (all->gr.planeX * all->gr.dirY - all->gr.dirX * all->gr.planeY);

		all->spr.transformX = all->spr.invDet * (all->gr.dirY * all->spr.spriteX - all->gr.dirX * all->spr.spriteY);
		all->spr.transformY = all->spr.invDet * (-all->gr.planeY * all->spr.spriteX + all->gr.planeX * all->spr.spriteY);
		
		all->spr.spriteScreenX = (int)((all->key.w / 2) * (1 + all->spr.transformX / all->spr.transformY));

		int vMoveScreen = (int)(vMove / all->spr.transformY);

		all->spr.spriteHeight = (int)(fabs((all->key.h / all->spr.transformY)) / vDiv);
		int drawStartY = -all->spr.spriteHeight / 2 + all->key.h / 2 + vMoveScreen;
		if(drawStartY < 0)
			drawStartY = 0;
		int drawEndY = all->spr.spriteHeight / 2 + all->key.h / 2 + vMoveScreen;
		if(drawEndY >= all->key.h)
			drawEndY = all->key.h - 1;

		all->spr.spriteWidth = (int)(fabs((all->key.h  / all->spr.transformY)) / uDiv);
		int drawStartX = -all->spr.spriteWidth / 2 + all->spr.spriteScreenX;
		if(drawStartX < 0)
			drawStartX = 0;
		int drawEndX = all->spr.spriteWidth / 2 + all->spr.spriteScreenX;
		if(drawEndX >= all->key.w)
			drawEndX = all->key.w - 1;

		for(int stripe = drawStartX; stripe < drawEndX; stripe++)
		{
			all->spr.texspriteX = (int)((256 * (stripe - (-all->spr.spriteWidth / 2 + all->spr.spriteScreenX)) * TEXTUREW / all->spr.spriteWidth)) / 256;
			if (all->spr.transformY > 0 && stripe > 0 && stripe < all->key.w && all->spr.transformY < all->gr.zBuffer[stripe])
			{
				for(int y = drawStartY; y < drawEndY; y++)
				{
					int d = (y - vMoveScreen) * 256 - all->key.h * 128 + all->spr.spriteHeight * 128;
					all->spr.texspriteY = ((d * TEXTUREH) / all->spr.spriteHeight) / 256;
					int color = all->gr.texture[4][TEXTUREW * all->spr.texspriteY + all->spr.texspriteX];
					if((color & 0x00FFFFFF) != 0) 
						all->gr.bufer[y][stripe] = color;
				}
			}
		}
	}
}

int		counting(t_all *all)
{
	img_3d(all);
	print(all);
	key_update(all);
	return (0);
} 