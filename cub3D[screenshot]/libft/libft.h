/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <ntomika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 00:47:26 by ntomika           #+#    #+#             */
/*   Updated: 2021/04/14 16:59:10 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strdup(char *src);
char				*ft_strchr(const char *s, int c);
void				*ft_memchr(const void *s, int c, size_t n);
void				ft_bzero(void *b, size_t n);
void				*ft_calloc(size_t count, size_t size);
size_t				ft_strlen(const char *str);

#endif
