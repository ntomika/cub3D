/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <ntomika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:59:04 by ntomika           #+#    #+#             */
/*   Updated: 2021/04/08 20:03:03 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	my_mlx_pixel_put(t_all *all, int x, int y, long long color)
{
	int	*dst;

	dst = all->img.addr + (y * all->img.line_length + x *
			(all->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		quit(t_all *all)
{
	mlx_destroy_window(all->img.mlx, all->img.win);
	exit(0);
}
