#include "header.h"

void identef_key(t_all *all)
{
	all->key.h = 0;
	all->key.w = 0;
	all->color.red = 0;
	all->color.green = 0;
	all->color.blue = 0;
}

int check_valid(t_all *all)
{
	int i = 0;

	identef_key(all);
	if (!(check_R(all)) || !(check_F(all)) || !(check_C(all)) || \
		!(check_S(all)) || !(check_NO(all)) || !(check_SO(all)) || \
		!(check_WE(all)) || !(check_EA(all)))
	{
		get_error("Invalid configurations");
		return (0);
	}
	i = all->size - all->sizemap;
	if (all->conf[i][0] == ' ' || all->conf[i][0] == '1')
	{
		if (!(all->map = (char **)malloc(sizeof(char *) * (all->sizemap + 1))))
		{
			get_error("Failed to allocate memory");
			return (0);
		}
		if (!(check_map(all, &i)))
		{
			get_free_conf(all);
			return (0);
		}
	}
	else
	{
		get_error("Invalid configuration file");
		return (0);
	}

	int k = -1;
	printf("map : \n");
	while (all->map[++k] != 0)
		printf("%s\n", all->map[k]);
	return (1);
}