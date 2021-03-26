# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntomika <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/10 00:47:42 by ntomika           #+#    #+#              #
#    Updated: 2020/11/24 19:24:04 by ntomika          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

CFLAGS		= -Wall -Wextra -Werror

SRCS		= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
			ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
			ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
			ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c \
			ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
			ft_strnstr.c ft_strrchr.c ft_substr.c ft_tolower.c \
			ft_toupper.c ft_strjoin.c ft_itoa.c ft_putchar_fd.c\
			ft_putstr_fd.c ft_putnbr_fd.c ft_strmapi.c ft_putendl_fd.c \
			ft_strtrim.c ft_split.c

BONUS		= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		  	ft_lstadd_back.c ft_lstdelone.c ft_lstiter.c

BONUS_OBJS	= $(BONUS:.c=.o)

OBJS		= $(SRCS:.c=.o)

RM			= rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

bonus:		$(OBJS) $(BONUS_OBJS)
			ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

$(.c=.o):	gcc $(CFLAGS) -I. -c $< -o $(<:.c=.o)

clean:
			$(RM) $(OBJS) $(BONUS_OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
