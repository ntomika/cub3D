/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <ntomika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:45:51 by ntomika           #+#    #+#             */
/*   Updated: 2021/03/26 21:34:31 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	poz_N(t_all *all)
{
	if (all->plr.poz == 'N')
	{
		all->gr.dirX = -1.0;
		all->gr.dirY = 0.0;
		all->gr.planeX = 0.0;
		all->gr.planeY = 0.66;
	}
}

void	poz_S(t_all *all)
{
	if (all->plr.poz == 'S')
	{
		all->gr.dirX = 1.0;
		all->gr.dirY = 0.0;
		all->gr.planeX = 0.0;
		all->gr.planeY = -0.66;
	}
}

void	poz_W(t_all *all)
{
	if (all->plr.poz == 'W')
	{
		all->gr.dirX = 0.0;
		all->gr.dirY = -1.0;
		all->gr.planeX = -0.66;
		all->gr.planeY = 0.0;
	}
}

void	poz_E(t_all *all)
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
	poz_N(all);
	poz_S(all);
	poz_W(all);
	poz_E(all);
}
