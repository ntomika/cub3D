#include "header.h"

void	left_right(int *key, t_all *all)
{
	if (*key == 123)
	{
		all->gr.oldDirX = all->gr.dirX;
		all->gr.dirX = all->gr.dirX * cos(rotSpeed) - all->gr.dirY * sin(rotSpeed);
		all->gr.dirY = all->gr.oldDirX * sin(rotSpeed) + all->gr.dirY * cos(rotSpeed);
		all->gr.oldPlaneX = all->gr.planeX;
		all->gr.planeX = all->gr.planeX * cos(rotSpeed) - all->gr.planeY * sin(rotSpeed);
		all->gr.planeY = all->gr.oldPlaneX * sin(rotSpeed) + all->gr.planeY * cos(rotSpeed);
	}
	if (*key == 124)
	{
		all->gr.oldDirX = all->gr.dirX;
		all->gr.dirX = all->gr.dirX * cos(-rotSpeed) - all->gr.dirY * sin(-rotSpeed);
		all->gr.dirY = all->gr.oldDirX * sin(-rotSpeed) + all->gr.dirY * cos(-rotSpeed);
		all->gr.oldPlaneX = all->gr.planeX;
		all->gr.planeX = all->gr.planeX * cos(-rotSpeed) - all->gr.planeY * sin(-rotSpeed);
		all->gr.planeY = all->gr.oldPlaneX * sin(-rotSpeed) + all->gr.planeY * cos(-rotSpeed);
	}
}

void	key_A_and_D(int *key, t_all *all)
{
	if (*key == 0)		// A
	{
		if (all->map[(int)(all->gr.posX - all->gr.dirX * moveSpeed)][(int)(all->gr.posY)] != '1')
			all->gr.posX -= all->gr.planeX * moveSpeed;
		if (all->map[(int)(all->gr.posX)][(int)(all->gr.posY - all->gr.dirY * moveSpeed)] != '1')
			all->gr.posY -= all->gr.planeY * moveSpeed;
	}
	if (*key == 2)		// D
	{
		if (all->map[(int)(all->gr.posX + all->gr.dirX * moveSpeed)][(int)(all->gr.posY)] != '1')
			all->gr.posX += all->gr.planeX * moveSpeed;
		if (all->map[(int)(all->gr.posX)][(int)(all->gr.posY + all->gr.dirY * moveSpeed)] != '1')
			all->gr.posY += all->gr.planeY * moveSpeed;
	}
}

int		key_press(int key, t_all *all)
{
	if (key == 13)		// W
	{
		if (all->map[(int)(all->gr.posX + all->gr.dirX * moveSpeed)][(int)(all->gr.posY)] != '1')
			all->gr.posX += all->gr.dirX * moveSpeed;
		if (all->map[(int)(all->gr.posX)][(int)(all->gr.posY + all->gr.dirY * moveSpeed)] != '1')
			all->gr.posY += all->gr.dirY * moveSpeed;
	}
	if (key == 1)		// S
	{
		if (all->map[(int)(all->gr.posX - all->gr.dirX * moveSpeed)][(int)(all->gr.posY)] != '1')
			all->gr.posX -= all->gr.dirX * moveSpeed;
		if (all->map[(int)(all->gr.posX)][(int)(all->gr.posY - all->gr.dirY * moveSpeed)] != '1')
			all->gr.posY -= all->gr.dirY * moveSpeed;
	}
	if (key == 53)
		exit(0);
	left_right(&key, all);
	key_A_and_D(&key, all);
	return (1);
}