/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 20:14:05 by ntomika           #+#    #+#             */
/*   Updated: 2020/11/24 18:24:32 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_search(char const *set, char s1)
{
	int j;

	j = 0;
	while (set[j])
	{
		if (set[j] == s1)
			return (1);
		j++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	int		i;
	int		end;

	if (!s1)
		return (NULL);
	i = 0;
	while (s1[i] && ft_search(set, s1[i]) != 0)
		i++;
	end = ft_strlen(s1);
	while (end && ft_search(set, s1[end - 1]) != 0)
		end--;
	if (i >= end)
		return (ft_strdup(""));
	s2 = ft_substr(s1, i, end - i);
	return (s2);
}
