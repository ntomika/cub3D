#ifndef HEADER_H
#define HEADER_H
#define BUFFER_SIZE 1
#define PI 3.1415926535
#define SCALE 30
#define h 1080
#define w 1080
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
//#include <mlx.h>
#include <math.h>
//#include "minilibx_mms_20200219/mlx.h"
#include "minilibx_opengl_20191021/mlx.h"
#include "./libft/libft.h"

typedef struct  s_player
{
	char 		poz;
	float 		player_x;
	float 		player_y;
	float 		player_a;
	float 		delta_x;
	float 		delta_y;
}				t_player;

typedef struct  s_data
{
	void        *img;
	void    	*mlx;
	void    	*win;
	char        *addr;
	int         bits_per_pixel;
	int         line_length;
	int         endian;
}               t_data;

typedef struct 		s_textures
{
	float 			start;
	float 			end;
	float			dir;
	float			x;
	float			y;
	float			LenRay;
	float			Wall;
}					t_textures;

typedef struct	s_ray //структура для игрока и луча
{
	float		x;
	float		y;
	float		dir;
}				  t_ray;

typedef struct		s_key
{
	char 			*Rkey;
	char 			*Skey;
	char 			*Fkey;
	char 			*Ckey;
	char 			*NOkey;
	char 			*SOkey;
	char 			*WEkey;
	char 			*EAkey;
}					t_key;

typedef struct 		s_all
{
	t_player 		plr;
	t_data 			img;
	t_ray			ray;
	t_textures		textures;
	t_key			key;
	int				sizemap;
	char 			**map;
	char			**conf;
}					t_all;

int		get_next_line(int fd, char **line);

void	my_mlx_pixel_put(t_all *all, int x, int y, long long color);
int		print_square(t_all *all, int k, int l, unsigned int color);
int		key_hook(int keycode, t_all *all);
void	check_player(t_all *all);
void 	drow_map(t_all *all);
void	print_map(t_all *all);

void	ft_cast_ray(t_all *all);
void	ft_cast_rays(t_all *all);

void	check_valid(t_all *all);

void	get_error(char *message);

void	map_3d(t_all *all);
void 	print_column(t_all *all, int x);

#endif