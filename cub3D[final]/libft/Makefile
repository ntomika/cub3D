# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntomika <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/10 00:47:42 by ntomika           #+#    #+#              #
#    Updated: 2021/04/09 01:05:23 by ntomika          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

CFLAGS		= -Wall -Wextra -Werror

SRCS		= ft_bzero.c \
				ft_calloc.c \
				ft_memcmp.c \
				ft_strchr.c \
				ft_strdup.c \
				ft_strlen.c 

OBJS		= $(SRCS:.c=.o)

RM			= rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

$(.c=.o):	gcc $(CFLAGS) -I. -c $< -o $(<:.c=.o)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
