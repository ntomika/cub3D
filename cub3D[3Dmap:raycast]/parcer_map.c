#include "header.h"

void	my_mlx_pixel_put(t_all *all, int x, int y, long long color)
{
	char    *dst;

	dst = all->img.addr + (y * all->img.line_length + x * (all->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int print_square(t_all *all, int k, int l, unsigned int color)
{
	int i;
	int j = -1;

	while (++j < SCALE)
	{
		i = -1;
		while (++i < SCALE)
			my_mlx_pixel_put(all, j + k * SCALE, i + l * SCALE, color);
	}
	return (0);
}

int		key_hook(int keycode, t_all *all)
{
	if (keycode == 53) // Esc
		exit(0);
	if (keycode == 13) // 'W'
	{
		all->plr.player_x += cos(all->plr.player_a) * 2;
		all->plr.player_y += sin(all->plr.player_a) * 2;
	}
	if (keycode == 1) // 'S'
	{
		all->plr.player_x -= cos(all->plr.player_a) * 2;
		all->plr.player_y -= sin(all->plr.player_a) * 2;
	}
	if (keycode == 0) // 'A'
	{
		all->plr.player_x -= sin(all->plr.player_a) * 2;
		all->plr.player_y -= cos(all->plr.player_a) * 2;
	}
	if (keycode == 2) // 'D'
	{
		all->plr.player_x += sin(all->plr.player_a) * 2;
		all->plr.player_y += cos(all->plr.player_a) * 2;
	}
	if (keycode == 123)
		all->plr.player_a -= 0.1;
	if (keycode == 124)
		all->plr.player_a += 0.1;
	print_map(all);
	map_3d(all);
	return (0);
}

void check_player(t_all *all)
{
	if (all->plr.poz == 'N')
		all->plr.player_a = (3 * PI) / 2;
	if (all->plr.poz == 'S')
		all->plr.player_a = PI / 2;
	if (all->plr.poz == 'E')
		all->plr.player_a = 0;
	if (all->plr.poz == 'W')
		all->plr.player_a = PI;
}

void 		drow_map(t_all *all)
{
	int i = -1;
	while (all->map[++i])
	{
		int j = -1;
		while (all->map[i][++j])
		{
			if (all->map[i][j] == '1')
				print_square(all, j, i, 0x00FFFFFF);
			if (all->map[i][j] == '2')
				print_square(all, j, i, 0x0000FFF0);
		}
	}
	ft_cast_rays(all);
}

void print_map(t_all *all)
{
	all->img.img = mlx_new_image(all->img.mlx, w, h);
	all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel,
								  &all->img.line_length,
								  &all->img.endian);
	drow_map(all);

	mlx_put_image_to_window(all->img.mlx, all->img.win, all->img.img, 0, 0);
}
