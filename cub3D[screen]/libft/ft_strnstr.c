/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 00:46:55 by ntomika           #+#    #+#             */
/*   Updated: 2020/11/21 20:16:04 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hs, const char *ns, size_t len)
{
	size_t ln;
	size_t lh;

	ln = ft_strlen(ns);
	if (!ln)
		return ((char *)hs);
	lh = ft_strlen(hs);
	if (lh < ln || len < ln)
		return (NULL);
	while (*hs != '\0' && len >= ln)
	{
		if (ft_strncmp(hs, ns, ln) == 0)
			return ((char *)hs);
		hs++;
		len--;
	}
	return (NULL);
}
