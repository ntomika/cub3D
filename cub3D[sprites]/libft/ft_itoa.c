/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 21:34:41 by ntomika           #+#    #+#             */
/*   Updated: 2020/11/20 20:12:05 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nlen(int s)
{
	int		j;

	j = 0;
	if (s < 0)
		s = s * (-1);
	if (s == 0)
		return (1);
	while (s != 0)
	{
		j++;
		s = s / 10;
	}
	return (j);
}

static int	ft_znak(int num)
{
	if (num < 0)
		return (2);
	else
		return (1);
}

char		*ft_itoa(int n)
{
	char		*c;
	int			l;
	long int	nl;

	nl = n;
	l = ft_nlen(nl) + ft_znak(nl);
	c = (char *)malloc(l);
	if (!c)
		return (NULL);
	if (nl == 0)
		c[0] = '0';
	if (nl < 0)
	{
		c[0] = '-';
		nl = nl * (-1);
	}
	while (nl != 0)
	{
		l--;
		c[l - 1] = (nl % 10) + '0';
		nl = nl / 10;
	}
	l = ft_nlen(n) + ft_znak(n);
	c[l - 1] = '\0';
	return (c);
}
