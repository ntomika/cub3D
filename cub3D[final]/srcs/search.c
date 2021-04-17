#include "header.h"

void	write_coordinates(t_all *all)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = 0;
	y = 0;
	i = -1;
	while (++i < all->sizemap)
	{
		j = -1;
		while (all->map[i][++j])
		{
			if (all->map[i][j] == '2')
			{
				all->spr.poz_sprite_x[x] = (float)i + 0.5;
				all->spr.poz_sprite_y[y] = (float)j + 0.5;
				x++;
				y++;
			}
		}
	}
}

int	init_char_sprt(t_all *all)
{
	all->spr.poz_sprite_x = (float *)malloc(sizeof(float)
			* all->key.numSprites + 1);
	if (!all->spr.poz_sprite_x)
	{
		get_error("Failed to allocate memory");
		return (0);
	}
	all->spr.poz_sprite_y = (float *)malloc(sizeof(float)
			* all->key.numSprites + 1);
	if (!all->spr.poz_sprite_y)
	{
		get_error("Failed to allocate memory");
		return (0);
	}
	all->spr.poz_sprite_x[all->key.numSprites - 1] = '\0';
	all->spr.poz_sprite_y[all->key.numSprites -1] = '\0';
	return (1);
}

int	search_sprites(t_all *all)
{
	int	j;
	int	i;

	i = -1;
	while (++i < all->sizemap)
	{
		j = -1;
		while (all->map[i][++j])
		{
			if (all->map[i][j] == '2')
				all->key.numSprites++;
		}
	}
	if (!init_char_sprt(all))
		return (0);
	write_coordinates(all);
	return (1);
}

void	search_plr(t_all *all, int *flag, int *i, int *j)
{
	if (ft_strchr("NSWE", all->map[*i][*j]))
	{
		all->gr.posX = *i + 0.5;
		all->gr.posY = *j + 0.5;
		all->plr.poz = all->map[*i][*j];
		check_player(all);
		*flag += 1;
		all->map[*i][*j] = '0';
	}
}

int	plr_bihavior(t_all *all)
{
	int	i;
	int	j;
	int	flag;

	all->key.numSprites = 0;
	i = -1;
	flag = 0;
	while (++i < all->sizemap)
	{
		j = -1;
		while (all->map[i][++j])
			search_plr(all, &flag, &i, &j);
	}
	if (flag > 1 || flag == 0)
	{
		get_error("The map must contain one player");
		exit(-1);
	}
	return (1);
}
