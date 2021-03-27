#include "header.h"

void	left_right(t_all *all)
{
	if (all->keycap.k_l)
	{
		all->gr.oldDirX = all->gr.dirX;
		all->gr.dirX = all->gr.dirX * cos(rotSpeed) - all->gr.dirY * sin(rotSpeed);
		all->gr.dirY = all->gr.oldDirX * sin(rotSpeed) + all->gr.dirY * cos(rotSpeed);
		all->gr.oldPlaneX = all->gr.planeX;
		all->gr.planeX = all->gr.planeX * cos(rotSpeed) - all->gr.planeY * sin(rotSpeed);
		all->gr.planeY = all->gr.oldPlaneX * sin(rotSpeed) + all->gr.planeY * cos(rotSpeed);
	}
	if (all->keycap.k_r)
	{
		all->gr.oldDirX = all->gr.dirX;
		all->gr.dirX = all->gr.dirX * cos(-rotSpeed) - all->gr.dirY * sin(-rotSpeed);
		all->gr.dirY = all->gr.oldDirX * sin(-rotSpeed) + all->gr.dirY * cos(-rotSpeed);
		all->gr.oldPlaneX = all->gr.planeX;
		all->gr.planeX = all->gr.planeX * cos(-rotSpeed) - all->gr.planeY * sin(-rotSpeed);
		all->gr.planeY = all->gr.oldPlaneX * sin(-rotSpeed) + all->gr.planeY * cos(-rotSpeed);
	}
}

void	key_A_and_D(t_all *all)
{
	if (all->keycap.k_a)		// A
	{
		if (all->map[(int)(all->gr.posX - all->gr.dirX * moveSpeed)][(int)(all->gr.posY)] != '1')
			all->gr.posX -= all->gr.planeX * moveSpeed;
		if (all->map[(int)(all->gr.posX)][(int)(all->gr.posY - all->gr.dirY * moveSpeed)] != '1')
			all->gr.posY -= all->gr.planeY * moveSpeed;
	}
	if (all->keycap.k_d)		// D
	{
		if (all->map[(int)(all->gr.posX + all->gr.dirX * moveSpeed)][(int)(all->gr.posY)] != '1')
			all->gr.posX += all->gr.planeX * moveSpeed;
		if (all->map[(int)(all->gr.posX)][(int)(all->gr.posY + all->gr.dirY * moveSpeed)] != '1')
			all->gr.posY += all->gr.planeY * moveSpeed;
	}
}

void		key_update(t_all *all)
{
	if (all->keycap.k_w)		// W
	{
		if (all->map[(int)(all->gr.posX + all->gr.dirX * moveSpeed)][(int)(all->gr.posY)] != '1')
			all->gr.posX += all->gr.dirX * moveSpeed;
		if (all->map[(int)(all->gr.posX)][(int)(all->gr.posY + all->gr.dirY * moveSpeed)] != '1')
			all->gr.posY += all->gr.dirY * moveSpeed;
	}
	if (all->keycap.k_s)		// S
	{
		if (all->map[(int)(all->gr.posX - all->gr.dirX * moveSpeed)][(int)(all->gr.posY)] != '1')
			all->gr.posX -= all->gr.dirX * moveSpeed;
		if (all->map[(int)(all->gr.posX)][(int)(all->gr.posY - all->gr.dirY * moveSpeed)] != '1')
			all->gr.posY -= all->gr.dirY * moveSpeed;
	}
	if (all->keycap.k_esc)
		exit(0);
	left_right(all);
	key_A_and_D(all);
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