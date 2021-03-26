NAME		= cub3D

CFLAGS		= -Wall -Wextra -Werror

MLX			= libmlx.dylib -framework OpenGL -framework AppKit



SRCS		= readmap.c \
				drow_map.c \
				cast_rays.c \
				get_next_line.c \
				get_next_line_utils.c \
				get_error.c \
				check_valid.c 


OBJS		= $(SRCS:.c=.o)

RM			= rm -f

$(NAME):	$(OBJS)
			rm -rf cub3D
			$(MAKE) -C ./libft
			gcc $(OBJS) -I.header.h $(CFLAGS) $(MLX) ./libft/libft.a -o $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJS)
			$(MAKE) clean -C ./libft

fclean:		clean
			$(RM) $(NAME)
			$(MAKE) fclean -C ./libft

re:			fclean all
