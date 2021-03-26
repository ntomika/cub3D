/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 00:46:01 by ntomika           #+#    #+#             */
/*   Updated: 2020/11/10 20:20:56 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	i = 0;
	d = (char *)dst;
	s = (char *)src;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		*&d[i] = *&s[i];
		if (s[i] == (char)c)
			return ((char *)&dst[i] + 1);
		i++;
	}
	return (NULL);
}
