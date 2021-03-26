/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 00:47:04 by ntomika           #+#    #+#             */
/*   Updated: 2020/11/24 18:29:56 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	l;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	l = ft_strlen(s);
	if (len + start > l)
		len = l - start;
	if (start >= l)
		return (ft_strdup(""));
	if ((p = (char *)malloc(len + 1)) == NULL)
		return (NULL);
	while (len--)
	{
		p[i] = s[start];
		i++;
		start++;
	}
	p[i] = '\0';
	return (p);
}
