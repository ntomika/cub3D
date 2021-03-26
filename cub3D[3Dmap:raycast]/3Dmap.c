#include "header.h"

void 	print_column(t_all *all, int x)
{
	int y = -1;
	int pixel = (h - all->textures.Wall) / 2;
	while (++y < h)
	{
		if (y < pixel)
			my_mlx_pixel_put(all, x, y, 0x00FFFFFFF);
		if (y >= pixel && y < (h - pixel))
			my_mlx_pixel_put(all, x, y, 0x0000000FF);
		if (y > (h - pixel))
			my_mlx_pixel_put(all, x, y, 0x00FFFFFFF);
	}
}

void	map_3d(t_all *all)
{

	all->textures.x = all->plr.player_x;
	all->textures.y = all->plr.player_y;
	all->textures.dir = all->plr.player_a;
	all->textures.start = all->textures.dir - M_PI_4; // начало веера лучей [ \| ]
	all->textures.end = all->textures.dir + M_PI_4; // край веера лучей [ |/ ]
	int x = -1;

	while (all->textures.start <= all->textures.end)
	{
		all->textures.x = all->plr.player_x; // каждый раз возвращаемся в точку начала
		all->textures.y = all->plr.player_y;
		while (all->map[(int)(all->textures.y / SCALE)][(int)(all->textures.x / SCALE)] != '1' &&
			   all->map[(int)(all->textures.y / SCALE)][(int)(all->textures.x / SCALE)] != '2')
		{
			all->textures.x += cos(all->textures.start);
			all->textures.y += sin(all->textures.start);
		}

		all->textures.LenRay = hypotf(all->textures.x - all->plr.player_x, all->textures.y - all->plr.player_y) 
				* cosf(all->textures.start - all->plr.player_a);
		all->textures.Wall = (h / all->textures.LenRay) * SCALE;

		// printf("%f\n", all->textures.Wall);

		print_column(all, ++x);

		all->textures.start += (PI / 2) / h;
	}
}