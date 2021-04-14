#include "header.h"

void	sort_order(t_pair *orders, int amount)
{
	t_pair	tmp;
	int		i;
	int		j;

	i = -1;
	while (++i < amount)
	{
		j = -1;
		while (++j < amount - 1)
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
	t_pair	*sprites;
	int		i;

	i = -1;
	sprites = (t_pair *)malloc(sizeof(t_pair) * amount);
	while (++i < amount)
	{
		sprites[i].first = dist[i];
		sprites[i].second = order[i];
	}
	sort_order(sprites, amount);
	i = -1;
	while (++i < amount)
	{
		dist[i] = sprites[amount - i - 1].first;
		order[i] = sprites[amount - i - 1].second;
	}
	free(sprites);
}

void	init_sprite(t_all *all)
{
	int	i;

	i = -1;
	all->spr.spriteOrder = (int *)malloc(sizeof(int) * all->key.numSprites);
	all->spr.spriteDistance = (float *)malloc(sizeof(float)
			* all->key.numSprites);
	i = -1;
	while (++i < all->key.numSprites)
	{
		all->spr.spriteOrder[i] = i;
		all->spr.spriteDistance[i] = ((all->gr.posX - all->spr.poz_sprite_x[i])
				* (all->gr.posX - all->spr.poz_sprite_x[i])
				+ (all->gr.posY - all->spr.poz_sprite_y[i])
				* (all->gr.posY - all->spr.poz_sprite_y[i]));
	}
	sortSprites(all->spr.spriteOrder, all->spr.spriteDistance,
		all->key.numSprites);
}

void	get_sprite(t_all *all)
{
	int	i;
	int	y;
	int	d;
	int	color;

	color = 0;
	d = 0;
	y = 0;
	init_sprite(all);
	i = -1;
	while (++i < all->key.numSprites)
	{
		all->spr.spriteX = all->spr.poz_sprite_x[all->spr.spriteOrder[i]]
			- all->gr.posX;
		all->spr.spriteY = all->spr.poz_sprite_y[all->spr.spriteOrder[i]]
			- all->gr.posY;
		transform(all);
		lowest_highest_width(all);
		loop_vertical_stripe(all, y, d, color);
	}
	free(all->spr.spriteOrder);
	free(all->spr.spriteDistance);
}
