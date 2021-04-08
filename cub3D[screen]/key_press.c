/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <ntomika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:12:35 by ntomika           #+#    #+#             */
/*   Updated: 2021/04/01 17:21:59 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	left_right(t_all *all)
{
	if (all->keycap.k_l)
	{
		all->gr.oldDirX = all->gr.dirX;
		all->gr.dirX = all->gr.dirX * cos(rotS) - all->gr.dirY * sin(rotS);
		all->gr.dirY = all->gr.oldDirX * sin(rotS) + all->gr.dirY * cos(rotS);
		all->gr.oldPlaneX = all->gr.planeX;
		all->gr.planeX = all->gr.planeX * cos(rotS) -
			all->gr.planeY * sin(rotS);
		all->gr.planeY = all->gr.oldPlaneX * sin(rotS) +
			all->gr.planeY * cos(rotS);
	}
	if (all->keycap.k_r)
	{
		all->gr.oldDirX = all->gr.dirX;
		all->gr.dirX = all->gr.dirX * cos(-rotS) - all->gr.dirY * sin(-rotS);
		all->gr.dirY = all->gr.oldDirX * sin(-rotS) + all->gr.dirY * cos(-rotS);
		all->gr.oldPlaneX = all->gr.planeX;
		all->gr.planeX = all->gr.planeX * cos(-rotS) -
			all->gr.planeY * sin(-rotS);
		all->gr.planeY = all->gr.oldPlaneX * sin(-rotS) +
			all->gr.planeY * cos(-rotS);
	}
}

void	key_a_and_d(t_all *all)
{
	if (all->keycap.k_a)
	{
		if (all->map[(int)(all->gr.posX - all->gr.dirX * moveS)]
		[(int)(all->gr.posY)] != '1')
			all->gr.posX -= all->gr.planeX * moveS;
		if (all->map[(int)(all->gr.posX)]
		[(int)(all->gr.posY - all->gr.dirY * moveS)] != '1')
			all->gr.posY -= all->gr.planeY * moveS;
	}
	if (all->keycap.k_d)
	{
		if (all->map[(int)(all->gr.posX + all->gr.dirX * moveS)]
		[(int)(all->gr.posY)] != '1')
			all->gr.posX += all->gr.planeX * moveS;
		if (all->map[(int)(all->gr.posX)]
		[(int)(all->gr.posY + all->gr.dirY * moveS)] != '1')
			all->gr.posY += all->gr.planeY * moveS;
	}
}

void	key_update(t_all *all)
{
	if (all->keycap.k_w)
	{
		if (all->map[(int)(all->gr.posX + all->gr.dirX * moveS)]
		[(int)(all->gr.posY)] != '1')
			all->gr.posX += all->gr.dirX * moveS;
		if (all->map[(int)(all->gr.posX)]
		[(int)(all->gr.posY + all->gr.dirY * moveS)] != '1')
			all->gr.posY += all->gr.dirY * moveS;
	}
	if (all->keycap.k_s)
	{
		if (all->map[(int)(all->gr.posX - all->gr.dirX * moveS)]
		[(int)(all->gr.posY)] != '1')
			all->gr.posX -= all->gr.dirX * moveS;
		if (all->map[(int)(all->gr.posX)]
		[(int)(all->gr.posY - all->gr.dirY * moveS)] != '1')
			all->gr.posY -= all->gr.dirY * moveS;
	}
	if (all->keycap.k_esc)
		exit(0);
	left_right(all);
	key_a_and_d(all);
}

int		key_press(int key, t_all *all)
{
	if (key == 53)
		exit(0);
	else if (key == 13)
		all->keycap.k_w = 1;
	else if (key == 0)
		all->keycap.k_a = 1;
	else if (key == 1)
		all->keycap.k_s = 1;
	else if (key == 2)
		all->keycap.k_d = 1;
	else if (key == 123)
		all->keycap.k_l = 1;
	else if (key == 124)
		all->keycap.k_r = 1;
	return (0);
}

int		key_release(int key, t_all *all)
{
	if (key == 53)
		exit(0);
	else if (key == 13)
		all->keycap.k_w = 0;
	else if (key == 0)
		all->keycap.k_a = 0;
	else if (key == 1)
		all->keycap.k_s = 0;
	else if (key == 2)
		all->keycap.k_d = 0;
	else if (key == 123)
		all->keycap.k_l = 0;
	else if (key == 124)
		all->keycap.k_r = 0;
	return (0);
}
