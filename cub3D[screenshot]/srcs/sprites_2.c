/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <ntomika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 23:00:43 by ntomika           #+#    #+#             */
/*   Updated: 2021/04/14 00:00:25 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	transform(t_all *all)
{
	all->spr.invDet = 1.0 / (all->gr.planeX * all->gr.dirY - all->gr.dirX
			* all->gr.planeY);
	all->spr.transformX = all->spr.invDet * (all->gr.dirY * all->spr.spriteX
			- all->gr.dirX * all->spr.spriteY);
	all->spr.transformY = all->spr.invDet * (-all->gr.planeY
			* all->spr.spriteX + all->gr.planeX * all->spr.spriteY);
	all->spr.spriteScreenX = (int)((all->key.w / 2)
			* (1 + all->spr.transformX / all->spr.transformY));
	all->spr.vMoveScreen = (int)(VMOVE / all->spr.transformY);
}

void	lowest_highest_width(t_all *all)
{
	all->spr.spriteHeight = (int)(fabs((all->key.h / all->spr.transformY))
			/ VDIV);
	all->spr.drawStartY = -all->spr.spriteHeight / 2 + all->key.h / 2
		+ all->spr.vMoveScreen;
	if (all->spr.drawStartY < 0)
		all->spr.drawStartY = 0;
	all->spr.drawEndY = all->spr.spriteHeight / 2 + all->key.h / 2
		+ all->spr.vMoveScreen;
	if (all->spr.drawEndY >= all->key.h)
		all->spr.drawEndY = all->key.h - 1;
	all->spr.spriteWidth = (int)(fabs((all->key.h / all->spr.transformY))
			/ UDIV);
	all->spr.drawStartX = -all->spr.spriteWidth / 2 + all->spr.spriteScreenX;
	if (all->spr.drawStartX < 0)
		all->spr.drawStartX = 0;
	all->spr.drawEndX = all->spr.spriteWidth / 2 + all->spr.spriteScreenX;
	if (all->spr.drawEndX >= all->key.w)
		all->spr.drawEndX = all->key.w - 1;
}

void	loop_vertical_stripe(t_all *all, int y, int d, int color)
{
	int	stripe;

	stripe = all->spr.drawStartX;
	while (stripe++ < all->spr.drawEndX - 1)
	{
		all->spr.texspriteX = (int )((256 * (stripe - (-all->spr.spriteWidth / 2
							+ all->spr.spriteScreenX))
					* TEXTUREW / all->spr.spriteWidth)) / 256;
		if (all->spr.transformY > 0 && stripe > 0 && stripe < all->key.w
			&& all->spr.transformY < all->gr.zBuffer[stripe])
		{
			y = all->spr.drawStartY;
			while (y++ < all->spr.drawEndY - 1)
			{
				d = (y - all->spr.vMoveScreen) * 256 - all->key.h
					* 128 + all->spr.spriteHeight * 128;
				all->spr.texspriteY = ((d * TEXTUREH)
						/ all->spr.spriteHeight) / 256;
				color = all->gr.texture[4][TEXTUREW * all->spr.texspriteY
					+ all->spr.texspriteX];
				if ((color & 0x00FFFFFF) != 0)
					all->gr.bufer[y][stripe] = color;
			}
		}
	}
}
