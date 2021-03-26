#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
// #include <mlx.h>
#include <math.h>
//#include "minilibx_opengl_20191021/mlx.h"
#include "minilibx_mms_20200219/mlx.h"
#include "./gnl/get_next_line.h"
#include "./libft/libft.h"

#define TEXTUREH 64
#define TEXTUREW 64
#define wd 900
#define hg 900
#define moveSpeed 0.3
#define rotSpeed 0.15

typedef struct  s_player
{
	char 		poz;
	float 		player_x;
	float 		player_y;
}				t_player;

typedef struct  s_data
{
	void        *img;
	void    	*mlx;
	void    	*win;
	int        	*addr;
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
	float		step;
	int			texY;
	int			texX;
	float		WallX;
	float		texPos;
	int			index;
	int 		*texture[5];
	int 		**bufer;

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

typedef struct 		s_floor
{
	float rayDirX0;
	float rayDirY0;
	float rayDirX1;
	float rayDirY1;
}					t_floor;

typedef struct		s_key
{
	int				h;
	int 			w;
	int				w2;
	int 			h2;
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
	t_3d			gr;
	t_textures		textures;
	t_key			key;
	t_color			color;
	t_floor			flr;
	int				sizemap;
	int 			size;
	char 			**map;
	char			**conf;
}					t_all;

void	my_mlx_pixel_put(t_all *all, int x, int y, long long color);
int		quit(t_all *all);

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

int		counting(t_all *all);
void	img_3d(t_all *all);
void	print(t_all *all, int x);
void	init_plr(t_all *all);

void	init_buf(t_all *all);
void	load_textures(t_all *all);
void	load_image(t_all *all, int *texture, char *path);

int		key_press(int key, t_all *all);
void	left_right(int *key, t_all *all);
void	key_A_and_D(int *key, t_all *all);

void	check_player(t_all *all);
void	poz_N(t_all *all);
void	poz_S(t_all *all);
void	poz_W(t_all *all);
void	poz_E(t_all *all);

#endif