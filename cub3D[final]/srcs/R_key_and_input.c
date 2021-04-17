#include "header.h"

int	w_and_h(t_all *all, int *i, char *s)
{
	while (s[*i] >= '0' && s[*i] <= '9')
	{
		all->key.w = all->key.w * 10 + (s[*i] - '0');
		*i += 1;
		if (overflow(all->key.w) == 0)
		{
			while (s[*i] != ' ')
				*i += 1;
			break ;
		}
	}
	while (s[*i] == ' ')
		*i += 1;
	while (s[*i] >= '0' && s[*i] <= '9')
	{
		all->key.h = all->key.h * 10 + (s[*i] - '0');
		*i += 1;
		if (overflow(all->key.h) == 0)
			break ;
	}
	if (all->key.w == 0 || all->key.h == 0)
		return (0);
	if (s[*i] != '\0')
		return (0);
	return (1);
}

void	check_wh(t_all *all)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	mlx_get_screen_size(&all, &width, &height);
	if (all->key.w > width)
		all->key.w = width;
	if (all->key.h > height)
		all->key.h = height;
}

int	open_r_key(char *s, t_all *all)
{
	int	i;

	i = 1;
	while (s[i] == ' ')
		i++;
	if (s[i] >= '0' && s[i] <= '9')
	{
		if (!(w_and_h(all, &i, s)))
			return (0);
	}
	else
		return (0);
	check_wh(all);
	return (1);
}

int	check_input_val(t_all *all)
{
	if (all->color.red > 255 || all->color.red < 0)
		return (0);
	if (all->color.green > 255 || all->color.green < 0)
		return (0);
	if (all->color.blue > 255 || all->color.blue < 0)
		return (0);
	return (1);
}

void	init_rgb(t_all *all)
{
	all->color.red = 0;
	all->color.green = 0;
	all->color.blue = 0;
}
