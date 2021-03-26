#include "header.h"

//int	map_angle(int *i, int *j, t_all *all)
//{
////	if (all->map[*i += 1][*j] == ' ' || all->map[*i -= 1][*j] == ' ' ||
////		all->map[*i][*j += 1] == ' ' || all->map[*i][*j -= 1] == ' ')
////		return (0);
//	if (all->map[*i -= 1][*j] == ' ')
//		return (0);
//	return (1);
//}

int	valid_start_end(int *i, int *j, t_all *all)
{
	if ((*i == 0 || *i == all->sizemap))
	{
		while (all->map[*i][*j] == ' ')
			*j += 1;
		if (all->map[*i][*j] == '1')
		{
			while (all->map[*i][*j] == '1')
				*j += 1;
			if (all->map[*i][*j] == '\0')
				return (1);
		}
		else
			return (0);
	}
	return (1);
}

int valid_map(t_all *all)
{
	int i = -1;

	if (all->sizemap < 3)
		return (0);
	while (all->map[++i])
	{
		int j = -1;
		while (all->map[i][++j])
		{
			if (!valid_start_end(&i, &j, all))
				return (0);
			if (all->map[i][j] == '\0')
			{
				i++;
				break ;
			}
			if (i > 0 && i < all->sizemap)
			{
				while (all->map[i][j] == ' ')
					j++;
				if (all->map[i][j] != '1' && all->map[i][ft_strlen(all->map[i]) - 1] != '1')
					return (0);
//				if (!map_angle(&i, &j, all))
//					return (0);
			}
		}
	}
	return (1);
}

int check_map(t_all *all, int *i)
{
	int k = 0;
	int j;
	int l;

	while (*i < all->size)
	{
		j = -1;
		l = -1;
		if (!(all->map[k] = (char *)malloc(sizeof(char) * (ft_strlen(all->conf[*i]) + 1))))
		{
			get_error("Failed to allocate memory");
			return (0);
		}
		while (all->conf[*i][++j])
			all->map[k][++l] = all->conf[*i][j];
		all->map[k][++l] = '\0';
		k++;
		*i += 1;
	}
	k = -1;
	while (all->map[++k])
		printf("%s\n", all->map[k]);
	if (!valid_map(all))
	{
		get_error("Invalid map");
		return (0);
	}
	return (1);
}