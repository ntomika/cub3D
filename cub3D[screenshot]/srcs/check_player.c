#include "header.h"

void	poz_n(t_all *all)
{
	if (all->plr.poz == 'N')
	{
		all->gr.dirX = -1.0;
		all->gr.dirY = 0.0;
		all->gr.planeX = 0.0;
		all->gr.planeY = 0.66;
	}
}

void	poz_s(t_all *all)
{
	if (all->plr.poz == 'S')
	{
		all->gr.dirX = 1.0;
		all->gr.dirY = 0.0;
		all->gr.planeX = 0.0;
		all->gr.planeY = -0.66;
	}
}

void	poz_w(t_all *all)
{
	if (all->plr.poz == 'W')
	{
		all->gr.dirX = 0.0;
		all->gr.dirY = -1.0;
		all->gr.planeX = -0.66;
		all->gr.planeY = 0.0;
	}
}

void	poz_e(t_all *all)
{
	if (all->plr.poz == 'E')
	{
		all->gr.dirX = 0.0;
		all->gr.dirY = 1.0;
		all->gr.planeX = 0.66;
		all->gr.planeY = 0.0;
	}
}

void	check_player(t_all *all)
{
	poz_n(all);
	poz_s(all);
	poz_w(all);
	poz_e(all);
}
