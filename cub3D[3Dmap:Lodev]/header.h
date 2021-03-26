#ifndef HEADER_H
#define HEADER_H
#define BUFFER_SIZE 1
#define PI 3.1415926535
#define SCALE 30
#define FOV PI/3
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
//#include <mlx.h>
#include <math.h>
#include "minilibx_opengl_20191021/mlx.h"
#include "minilibx_mms_20200219/mlx.h"
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

typedef struct	s_3d
{
	float		posX;
	float		posY;
	float		dirX;
	float		dirY;
	float		planeX;
	float 		oldPlaneX;
	float		planeY;
	float		time;
	float		oldTime;
	float		cameraX;
	float 		rayDirX;
	float 		oldDirX;
	float 		rayDirY;
	int			mapX;
	int			mapY;
	float		deltaDistX;
	float		deltaDistY;
	float		perpWallDist;
	float		sideDistX;
	float		sideDistY;
	int			stepX;
	int			stepY;
	int			side;
	int			lineHeight;
	int			drawStart;
	int			drawEnd;
	float		frameTime;
	float		moveSpeed;
	float 		rotSpeed;

}				t_3d;

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
	float 		LenR;
}				  t_ray;

typedef struct		s_key
{
	int				h;
	int 			w;
	int				img_S_h;
	int 			img_S_w;
	int				img_NO_h;
	int 			img_NO_w;
	int				img_SO_h;
	int 			img_SO_w;
	int				img_WE_h;
	int 			img_WE_w;
	int				img_EA_h;
	int 			img_EA_w;
	char			*NO_texture;
	char			*SO_texture;
	char			*WE_texture;
	char			*EA_texture;
	char			*S_texture;
	void			*img_NO;
	void 			*img_SO;
	void			*img_WE;
	void 			*img_EA;
	void			*img_S;
}					t_key;

typedef struct 		s_color
{
	int 			red;
	int 			green;
	int				blue;
	int				floor;
	int 			ceiling;
}					t_color;

typedef struct 		s_all
{
	t_player 		plr;
	t_data 			img;
	t_ray			ray;
	t_3d			gr;
	t_textures		textures;
	t_key			key;
	t_color			color;
	int				sizemap;
	int 			size;
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

int		check_valid(t_all *all);
void	identef_key(t_all *all);

int		valid_map(t_all *all);
int		valid_start_end(int *i, int *j, t_all *all);
int 	check_map(t_all *all, int *i);
int		map_angle(int *i, int *j, t_all *all);

int 	check_R(t_all *all);
int 	check_F(t_all *all);
int 	check_C(t_all *all);

int		check_NO(t_all *all);
int		check_SO(t_all *all);
int		check_WE(t_all *all);
int		check_EA(t_all *all);
int		check_S(t_all *all);

void	get_free_map(t_all *all);
void	get_free_conf(t_all *all);

int 	open_r_key(char *s, t_all *all);
int		w_and_h(t_all *all, int *i, char *s);
void	check_wh(t_all *all);
int		check_input_val(t_all *all);
void 	init_RGB(t_all *all);

int 	open_f_key(char *s, t_all *all);
int		open_c_key(char *s, t_all *all);
int 	color_conversion(char *c, int *clr);
int		create_trgb(int t, int r, int g, int b);
int		valid_color(t_all *all, int *i, char *s);

int		open_NO(char *s, t_all *all);
int		open_SO(char *s, t_all *all);
int		open_WE(char *s, t_all *all);
int		open_EA(char *s, t_all *all);
int		open_S(char *s, t_all *all);
int		open_img(t_all *all);

void	get_error(char *message);

int		img_3d(t_all *all);
int		key_press(int key, t_all *all);
void	print_column(t_all *all, int x, int y1, int y2, long color);
void	init_plr(t_all *all);
void	left_right(int *key, t_all *all);


#endif