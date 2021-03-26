/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 00:45:25 by ntomika           #+#    #+#             */
/*   Updated: 2021/03/09 16:35:30 by dasharazumova    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_new(size_t n)
{
	char	*a;
	size_t	i;

	i = 0;
	if (!(a = (char *)malloc(n + 1)))
		return (NULL);
	while (i < n)
	{
		a[i] = '\0';
		i++;
	}
	a[i] = '\0';
	return (a);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		l;
	char	*src2;

	l = ft_strlen(src);
	src2 = (char *)malloc(sizeof(char) * (l + 1));
	if (src2 == NULL)
		return (NULL);
	i = 0;
	while (i < l)
	{
		src2[i] = src[i];
		i++;
	}
	src2[i] = '\0';
	return (src2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		l1;
	int		l2;
	int		i;
	int		j;
	char	*k;

	i = 0;
	j = 0;
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (!(k = (char *)malloc(sizeof(char) * (l1 + l2 + 1))))
		return (NULL);
	while (i < l1)
	{
		k[i] = s1[i];
		i++;
	}
	while (j < l2)
	{
		k[i] = s2[j];
		i++;
		j++;
	}
	k[i] = '\0';
	return (k);
}
