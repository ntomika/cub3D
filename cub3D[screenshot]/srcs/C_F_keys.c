#include "header.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	color_conversion(char *c, int *clr)
{
	int	i;

	i = 0;
	while (c[i] >= '0' && c[i] <= '9')
	{
		*clr = *clr * 10 + (c[i] - '0');
		i++;
	}
	return (*clr);
}

int	valid_color(t_all *all, int *i, char *s)
{
	all->color.red = color_conversion(&s[*i], &all->color.red);
	while (s[*i] >= '0' && s[*i] <= '9')
		*i += 1;
	if (s[*i] == ',')
		*i += 1;
	else
		return (0);
	all->color.green = color_conversion(&s[*i], &all->color.green);
	while (s[*i] >= '0' && s[*i] <= '9')
		*i += 1;
	if (s[*i] == ',')
		*i += 1;
	else
		return (0);
	all->color.blue = color_conversion(&s[*i], &all->color.blue);
	return (1);
}

int	open_c_key(char *s, t_all *all)
{
	int	i;

	i = 0;
	init_rgb(all);
	i++;
	while (s[i] == ' ')
		i++;
	if (s[i] >= '0' && s[i] <= '9')
	{
		if (!(valid_color(all, &i, s)))
			return (0);
	}
	else
		return (0);
	if (!(check_input_val(all)))
		return (0);
	all->color.ceiling = create_trgb(0, all->color.red,
			all->color.green, all->color.blue);
	return (1);
}

int	open_f_key(char *s, t_all *all)
{
	int	i;

	i = 0;
	init_rgb(all);
	i++;
	while (s[i] == ' ')
		i++;
	if (s[i] >= '0' && s[i] <= '9')
	{
		if (!(valid_color(all, &i, s)))
			return (0);
	}
	else
		return (0);
	if (!(check_input_val(all)))
		return (0);
	all->color.floor = create_trgb(0, all->color.red,
			all->color.green, all->color.blue);
	return (1);
}
