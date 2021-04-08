/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 20:29:13 by ntomika           #+#    #+#             */
/*   Updated: 2020/11/20 20:15:54 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long m;

	m = n;
	if (m < 0)
	{
		ft_putchar_fd('-', fd);
		m = m * (-1);
	}
	if (m > 9)
	{
		ft_putnbr_fd(m / 10, fd);
		ft_putchar_fd(m % 10 + '0', fd);
	}
	if (m < 10)
		ft_putchar_fd(m % 10 + '0', fd);
}
