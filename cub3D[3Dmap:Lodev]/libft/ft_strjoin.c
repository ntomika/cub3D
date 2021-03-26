/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 00:39:33 by ntomika           #+#    #+#             */
/*   Updated: 2020/11/20 20:11:21 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l1;
	size_t	l2;
	int		p;
	char	*k;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	p = l1 + l2;
	k = (char *)malloc(sizeof(char) * (p + 1));
	if (k == NULL)
		return (NULL);
	ft_memcpy(k, s1, l1);
	ft_memmove(&k[l1], s2, l2);
	k[l1 + l2] = '\0';
	return (k);
}
