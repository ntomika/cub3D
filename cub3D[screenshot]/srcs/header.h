#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "../mlx/mlx.h"
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"

# define SCALE 1

# define TEXTUREH 64
# define TEXTUREW 64

# define MS 0.07
# define RS 0.05

# define UDIV 1
# define VDIV 1
# define VMOVE 0.0

# define FILE_HEADER_SIZE 14
# define INFO_HEADER_SIZE 40

typedef struct s_keycap
{
	int			k_a;
	int			k_s;
	int			k_d;
	int			k_w;
	int			k_esc;
	int			k_l;
	int			k_r;
}				t_keycap;

typedef struct s_player
{
	char		poz;
	float		player_x;
	float		player_y;
}				t_player;

typedef struct s_data
{
	void		*img;
	void		*mlx;
	void		*win;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_3d
{
	float		posX;
	float		posY;
	float		dirX;
	float		dirY;
	float		planeX;
	float		oldPlaneX;
	float		planeY;
	float		cameraX;
	float		rayDirX;
	float		oldDirX;
	float		rayDirY;
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
	int			*texture[5];
	int			**bufer;
	float		*zBuffer;

}				t_3d;

typedef struct s_key
{
	int			h;
	int			w;
	int			w2;
	int			h2;
	char		*NO_texture;
	char		*SO_texture;
	char		*WE_texture;
	char		*EA_texture;
	char		*S_texture;
	int			numSprites;
}				t_key;

typedef struct s_color
{
	int			red;
	int			green;
	int			blue;
	long		floor;
	long		ceiling;
}				t_color;

typedef struct s_pair
{
	float		first;
	int			second;
}				t_pair;

typedef struct s_spr
{
	float		spriteX;
	float		spriteY;
	float		invDet;
	float		transformX;
	float		transformY;
	int			spriteScreenX;
	int			spriteWidth;
	int			spriteHeight;
	int			texspriteX;
	int			texspriteY;
	int			vMoveScreen;
	int			drawStartX;
	int			drawStartY;
	int			drawEndX;
	int			drawEndY;
	int			*spriteOrder;
	float		*spriteDistance;
	float		*poz_sprite_x;
	float		*poz_sprite_y;
}				t_spr;

typedef struct s_all
{
	t_player	plr;
	t_data		img;
	t_3d		gr;
	t_key		key;
	t_color		color;
	t_spr		spr;
	t_keycap	keycap;
	int			sizemap;
	int			size;
	char		**map;
	char		**conf;
}				t_all;

int		general(t_all *all);

void	check_player(t_all *all);
void	poz_n(t_all *all);
void	poz_s(t_all *all);
void	poz_w(t_all *all);
void	poz_e(t_all *all);

int		plr_bihavior(t_all *all);
void	search_plr(t_all *all, int *flag, int *i, int *j);
int		search_sprites(t_all *all);
int		init_char_sprt(t_all *all);
void	write_coordinates(t_all *all);

void	my_mlx_pixel_put(t_all *all, int x, int y, long long color);
int		quit(t_all *all);

int		check_valid(t_all *all);
void	identef_key(t_all *all);
int		keys(t_all *all);

int		valid_map(t_all *all);
int		valid_start_end(t_all *all, int *i, int *j);
int		check_map(t_all *all, int *i);
int		map_angle(int i, int j, t_all *all);

int		check_R(t_all *all);
int		check_F(t_all *all);
int		check_C(t_all *all);
int		overflow(long key);

int		check_NO(t_all *all);
int		check_SO(t_all *all);
int		check_WE(t_all *all);
int		check_EA(t_all *all);
int		check_S(t_all *all);

void	get_free_map(t_all *all);
void	get_free_conf(t_all *all);
void	get_free_bufer(t_all *all);

int		open_r_key(char *s, t_all *all);
int		w_and_h(t_all *all, int *i, char *s);
void	check_wh(t_all *all);
int		check_input_val(t_all *all);
void	init_rgb(t_all *all);

int		open_f_key(char *s, t_all *all);
int		open_c_key(char *s, t_all *all);
int		color_conversion(char *c, int *clr);
int		create_trgb(int t, int r, int g, int b);
int		valid_color(t_all *all, int *i, char *s);

int		open_NO(char *s, t_all *all);
int		open_SO(char *s, t_all *all);
int		open_WE(char *s, t_all *all);
int		open_EA(char *s, t_all *all);
int		open_S(char *s, t_all *all);

void	get_error(char *message);

void	img_3d(t_all *all);
void	screen_buf(t_all *all, int x);
void	drow_ceiling(t_all *all, int x, int *y);
void	drow_floor(t_all *all, int x, int *y);
void	print(t_all *all);

int		counting(t_all *all);
void	step_and_side(t_all *all);
void	dda(t_all *all);
void	calc_wall(t_all *all);
void	texture(t_all *all);

void	sort_order(t_pair *orders, int amount);
void	sortSprites(int *order, float *dist, int amount);
void	get_sprite(t_all *all);
void	init_sprite(t_all *all);

void	transform(t_all *all);
void	lowest_highest_width(t_all *all);
void	loop_vertical_stripe(t_all *all, int y, int d, int color);

int		init_buf(t_all *all);
int		init_bufer(t_all *all);
void	load_textures(t_all *all);
int		load_image(t_all *all, int *texture, char *path);

void	key_update(t_all *all);
void	left_right(t_all *all);
void	key_a_and_d(t_all *all);
int		key_press(int key, t_all *all);
int		key_release(int key, t_all *all);

void	get_screen(t_all *all, char **argv);
void	file_header(t_all *all, int fd);
void	info_header(t_all *all, int fd);
void	get_bmp(t_all *all, int fd);

#endif