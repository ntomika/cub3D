/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 19:11:48 by ntomika           #+#    #+#             */
/*   Updated: 2020/11/23 19:11:54 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*nlst;

	nlst = lst;
	size = 0;
	while (nlst)
	{
		size++;
		nlst = nlst->next;
	}
	return (size);
}
