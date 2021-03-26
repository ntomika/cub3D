/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 18:55:54 by ntomika           #+#    #+#             */
/*   Updated: 2020/11/24 21:57:02 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nwords(char const *str, char c)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i])
			n++;
		while (str[i] != c && str[i])
			i++;
	}
	return (n);
}

static int	ft_lenword(char const *str, char c)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static char	**ft_delete(char **ms, int m)
{
	while (m >= 0)
		free(ms[m--]);
	free(ms);
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	char	**ms;
	size_t	i;
	size_t	m;
	size_t	k;

	i = 0;
	m = 0;
	if (!s || !(ms = (char **)malloc(sizeof(char *) * (ft_nwords(s, c) + 1))))
		return (NULL);
	while ((k = 0) || s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			if (!(ms[m] = (char *)malloc(sizeof(char) *
						(ft_lenword(&s[i], c) + 1))))
				return (ft_delete(ms, m));
			while (s[i] && s[i] != c)
				ms[m][k++] = s[i++];
			ms[m++][k] = '\0';
		}
	}
	ms[m] = 0;
	return (ms);
}
