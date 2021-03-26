/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 00:45:36 by ntomika           #+#    #+#             */
/*   Updated: 2020/11/20 20:14:22 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	int		r;
	char	*str;

	r = count * size;
	str = (char *)malloc(r);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, r);
	return (str);
}
