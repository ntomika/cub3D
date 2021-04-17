#include "header.h"

void	left_right(t_all *all)
{
	if (all->keycap.k_l)
	{
		all->gr.oldDirX = all->gr.dirX;
		all->gr.dirX = all->gr.dirX * cos(RS) - all->gr.dirY * sin(RS);
		all->gr.dirY = all->gr.oldDirX * sin(RS) + all->gr.dirY * cos(RS);
		all->gr.oldPlaneX = all->gr.planeX;
		all->gr.planeX = all->gr.planeX * cos(RS)
			- all->gr.planeY * sin(RS);
		all->gr.planeY = all->gr.oldPlaneX * sin(RS)
			+ all->gr.planeY * cos(RS);
	}
	if (all->keycap.k_r)
	{
		all->gr.oldDirX = all->gr.dirX;
		all->gr.dirX = all->gr.dirX * cos(-RS) - all->gr.dirY * sin(-RS);
		all->gr.dirY = all->gr.oldDirX * sin(-RS) + all->gr.dirY * cos(-RS);
		all->gr.oldPlaneX = all->gr.planeX;
		all->gr.planeX = all->gr.planeX * cos(-RS)
			- all->gr.planeY * sin(-RS);
		all->gr.planeY = all->gr.oldPlaneX * sin(-RS)
			+ all->gr.planeY * cos(-RS);
	}
}

void	key_a_and_d(t_all *all)
{
	if (all->keycap.k_a)
	{
		if (all->map[(int)(all->gr.posX - 0.5 - all->gr.planeX * MS)]
				[(int)(all->gr.posY - 0.5)] != '1')
			all->gr.posX -= all->gr.planeX * MS;
		if (all->map[(int)(all->gr.posX - 0.5)]
				[(int)(all->gr.posY - 0.5 - all->gr.planeY * MS)] != '1')
			all->gr.posY -= all->gr.planeY * MS;
	}
	if (all->keycap.k_d)
	{
		if (all->map[(int)(all->gr.posX + 0.5 + all->gr.planeX * MS)]
				[(int)(all->gr.posY + 0.5)] != '1')
			all->gr.posX += all->gr.planeX * MS;
		if (all->map[(int)(all->gr.posX + 0.5)]
				[(int)(all->gr.posY + 0.5 + all->gr.planeY * MS)] != '1')
			all->gr.posY += all->gr.planeY * MS;
	}
}

void	key_update(t_all *all)
{
	if (all->keycap.k_w)
	{
		if (all->map[(int)(all->gr.posX + all->gr.dirX * MS)]
				[(int)(all->gr.posY)] != '1')
			all->gr.posX += all->gr.dirX * MS;
		if (all->map[(int)(all->gr.posX)]
				[(int)(all->gr.posY + all->gr.dirY * MS)] != '1')
			all->gr.posY += all->gr.dirY * MS;
	}
	if (all->keycap.k_s)
	{
		if (all->map[(int)(all->gr.posX - all->gr.dirX * MS)]
				[(int)(all->gr.posY)] != '1')
			all->gr.posX -= all->gr.dirX * MS;
		if (all->map[(int)(all->gr.posX)]
				[(int)(all->gr.posY - all->gr.dirY * MS)] != '1')
			all->gr.posY -= all->gr.dirY * MS;
	}
	if (all->keycap.k_esc)
		exit(0);
	left_right(all);
	key_a_and_d(all);
}

int	key_press(int key, t_all *all)
{
	if (key == 53)
		quit(all);
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

int	key_release(int key, t_all *all)
{
	if (key == 53)
		quit(all);
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
