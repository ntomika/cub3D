NAME		= cub3D

CFLAGS		= -g -Wall -Wextra -Werror
#CFLAGS		= -g -Wall -Wextra -Werror -fsanitize=address

MLX			= libmlx.a -framework OpenGL -framework AppKit



SRCS		= readmap.c \
				get_next_line.c \
				get_next_line_utils.c \
				get_error.c \
				check_valid.c \
				get_free.c \
				C_F_keys.c \
				valid_RFC.c \
				R_key_and_input.c \
				valid_texture.c \
				textures_keys.c \
				check_map.c \
				3d_img.c


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
