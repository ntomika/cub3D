/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 00:47:00 by ntomika           #+#    #+#             */
/*   Updated: 2020/11/20 20:12:51 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ni;
	int		i;
	int		len;

	i = 0;
	ni = 0;
	len = ft_strlen(s);
	if (!s)
		return (NULL);
	if (ft_isascii(c) == 0)
		return (NULL);
	while (s[i] && i != len)
	{
		if (s[i] == c)
			ni = (char *)&s[i];
		i++;
	}
	if (s[i] == c)
		ni = (char *)&s[i];
	if (ni == 0)
		return (NULL);
	return (ni);
}
