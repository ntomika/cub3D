#include "header.h"

void	my_mlx_pixel_put(t_all *all, int x, int y, long long color)
{
	int	*dst;

	dst = all->img.addr + (y * all->img.line_length + x
			* (all->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	quit(t_all *all)
{
	get_free_map(all);
	get_free_conf(all);
	get_free_bufer(all);
	get_free_textures(all);
	free(all->spr.poz_sprite_x);
	free(all->spr.poz_sprite_y);
	free(all->gr.zBuffer);
	mlx_destroy_window(all->img.mlx, all->img.win);
	exit(0);
}
