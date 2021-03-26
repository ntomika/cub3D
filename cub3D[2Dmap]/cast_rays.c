/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <ntomika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 20:12:27 by ntomika           #+#    #+#             */
/*   Updated: 2021/03/10 18:12:10 by dasharazumova    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_cast_ray(t_all *all)
{
	all->ray.x = all->plr.player_x;
	all->ray.y = all->plr.player_y;		// координаты луча равные координатам игрока
	all->ray.dir = all->plr.player_a;	// направление взгляда в зависимости от заданного начального направления взгляда
	while (all->map[(int)(all->ray.y / SCALE)][(int)(all->ray.x / SCALE)] != '1')
	{
		all->ray.x += cos(all->ray.dir);
		all->ray.y += sin(all->ray.dir);
		my_mlx_pixel_put(all, all->ray.x, all->ray.y, 0xEEFF0000);
	}
}

void	ft_cast_rays(t_all *all)
{
	//t_plr	ray = *all->plr; // задаем координаты и направление луча равные координатам игрока
	all->ray.x = all->plr.player_x;
	all->ray.y = all->plr.player_y;
	all->ray.dir = all->plr.player_a;
	float start = all->ray.dir - M_PI_4; // начало веера лучей [ \| ]
	float end = all->ray.dir + M_PI_4; // край веера лучей [ |/ ]
	while (start <= end)
	{
		all->ray.x = all->plr.player_x; // каждый раз возвращаемся в точку начала
		all->ray.y = all->plr.player_y;
		while (all->map[(int)(all->ray.y / SCALE)][(int)(all->ray.x / SCALE)] != '1' &&
				all->map[(int)(all->ray.y / SCALE)][(int)(all->ray.x / SCALE)] != '2')
		{
			all->ray.x += cos(start);
			all->ray.y += sin(start);
			my_mlx_pixel_put(all, all->ray.x, all->ray.y, 0x00F0F000);
		}
		start += (PI / 2) / 1080;
	}
}
