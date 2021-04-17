#include "header.h"

void	identef_key(t_all *all)
{
	all->key.h = 0;
	all->key.w = 0;
	all->color.red = 0;
	all->color.green = 0;
	all->color.blue = 0;
	all->key.w2 = 0;
	all->key.h2 = 0;
}

int	keys(t_all *all)
{
	if (!(check_R(all)) || !(check_F(all)) || !(check_C(all))
		|| !(check_S(all)) || !(check_NO(all)) || !(check_SO(all))
		|| !(check_WE(all)) || !(check_EA(all)))
	{
		get_error("Invalid configurations");
		exit(-1);
	}
	return (1);
}

int	check_valid(t_all *all)
{
	int	i;

	identef_key(all);
	keys(all);
	i = all->size - all->sizemap;
	if (all->conf[i][0] == ' ' || all->conf[i][0] == '1')
	{
		all->map = (char **)malloc(sizeof(char *) * (all->sizemap + 1));
		if (!all->map)
		{
			get_error("Failed to allocate memory");
			exit(-1);
		}
		if (!(check_map(all, &i)))
			exit(-1);
	}
	else
	{
		get_error("Invalid configuration file");
		exit(-1);
	}
	return (1);
}

int	check_argv(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != '.')
	{
		if (argv[i] == '/')
		{
			get_error("Invalid argument name");
			exit(0);
		}
		i++;
	}
	if (argv[i] == '.')
		i++;
	else
	{
		get_error("Invalid argument name");
		exit(0);
	}
	if ((ft_memcmp("cub", &argv[i], 3)) != 0)
	{
		get_error("Invalid argument name");
		exit(0);
	}
	return (1);
}
