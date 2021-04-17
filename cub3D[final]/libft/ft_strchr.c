/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 00:46:39 by ntomika           #+#    #+#             */
/*   Updated: 2020/11/10 00:46:40 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*ni;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			ni = (char *)&s[i];
			return (ni);
		}
		i++;
	}
	if (s[i] == c)
	{
		ni = (char *)&s[i];
		return (ni);
	}
	return (NULL);
}
