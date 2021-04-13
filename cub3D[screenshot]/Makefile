NAME		= cub3D

CFLAGS		= -g -Wall -Wextra -Werror
#CFLAGS		= -g -Wall -Wextra -Werror -fsanitize=address

MLX			= -framework OpenGL -framework AppKit

LIB			= ./mlx/libmlx.a ./libft/libft.a

SRCS		= srcs/read_configs.c \
				srcs/search.c \
				srcs/check_player.c \
				srcs/get_error.c \
				srcs/check_valid.c \
				srcs/get_free.c \
				srcs/C_F_keys.c \
				srcs/valid_RFC.c \
				srcs/R_key_and_input.c \
				srcs/valid_texture.c \
				srcs/textures_keys.c \
				srcs/check_map.c \
				srcs/3d_img.c \
				srcs/initbuf_textures.c \
				srcs/key_press.c \
				srcs/func_mlx.c \
				srcs/get_screen.c \
				srcs/sprites.c \
				srcs/sprites_2.c \
				gnl/get_next_line.c \
				gnl/get_next_line_utils.c


OBJS		= $(SRCS:.c=.o)

RM			= rm -f

$(NAME):	$(OBJS)
			@rm -rf cub3D
			$(MAKE) -C ./libft
			$(MAKE) -C ./mlx
			gcc $(OBJS) -I.srcs/header.h $(CFLAGS) \
			$(MLX) $(LIB) -o $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJS)
			$(MAKE) clean -C ./libft

fclean:		clean
			$(RM) $(NAME)
			$(MAKE) fclean -C ./libft
			$(MAKE) clean -C ./mlx

re:			fclean all
