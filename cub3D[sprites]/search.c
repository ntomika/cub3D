/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <ntomika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 21:06:31 by ntomika           #+#    #+#             */
/*   Updated: 2021/03/27 21:10:22 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	write_coordinates(t_all *all)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = 0;
	y = 0;
	all->spr.poz_sprite_x = (float*)malloc(sizeof(float) * all->key.numSprites);
	all->spr.poz_sprite_y = (float*)malloc(sizeof(float) * all->key.numSprites);
	i = -1;
	while (all->map[++i])
	{
		j = -1;
		while (all->map[i][++j])
		{
			if (all->map[i][j] == '2')
			{
				all->spr.poz_sprite_x[x] = (float)i;
				all->spr.poz_sprite_y[y] = (float)j;
				x++;
				y++;
			}
		}
	}
}

void	search_sprites(t_all *all)
{
	int	j;
	int	i;

	i = -1;
	while (all->map[++i])
	{
		j = -1;
		while (all->map[i][++j])
		{
			if (all->map[i][j] == '2')
				all->key.numSprites++;
		}
	}
	write_coordinates(all);
}

void	search_plr(t_all *all, int *flag, int *i, int *j)
{
	if (ft_strchr("NSWE", all->map[*i][*j]))
	{
		all->plr.player_x = *i;
		all->plr.player_y = *j;
		all->plr.poz = all->map[*i][*j];
		check_player(all);
		*flag += 1;
		all->map[*i][*j] = '0';
	}
}

int		plr_bihavior(t_all *all)
{
	int	i;
	int	j;
	int	flag;

	all->key.numSprites = 0;
	i = -1;
	flag = 0;
	while (all->map[++i])
	{
		j = -1;
		while (all->map[i][++j])
			search_plr(all, &flag, &i, &j);
	}
	if (flag > 1 || flag == 0)
	{
		get_error("The map must contain one player");
		return (0);
	}
	return (1);
}
