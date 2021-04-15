#include "header.h"

int	map_angle(int i, int j, t_all *all)
{
	if (all->map[i][j] == '0' || all->map[i][j] == '2'
		|| all->map[i][j] == 'N' || all->map[i][j] == 'S'
		|| all->map[i][j] == 'W' || all->map[i][j] == 'E')
	{
		if (all->map[i + 1][j] == ' ' || all->map[i - 1][j] == ' ' ||
		all->map[i][j + 1] == ' ' || all->map[i][j - 1] == ' ')
			return (0);
	}
	else if (all->map[i][j] == ' ')
	{
		if (all->map[i][j + 1] != ' ' && all->map[i][j + 1] != '1')
			return (0);
		if (all->map[i][j - 1] != ' ' && all->map[i][j - 1] != '1')
			return (0);
		if (all->map[i + 1][j] != ' ' && all->map[i + 1][j] != '1')
			return (0);
		if (all->map[i - 1][j] != ' ' && all->map[i - 1][j] != '1')
			return (0);
	}
	else if (all->map[i][j] == '1')
		return (1);
	else
		return (0);
	return (1);
}

int	valid_start_end(t_all *all, int *i, int *j)
{
	if ((*i == 0 || *i == all->sizemap - 1))
	{
		*j = 0;
		while (all->map[*i][*j] != '\0')
		{
			while (all->map[*i][*j] == ' ')
				*j += 1;
			while (all->map[*i][*j] == '1')
				*j += 1;
			if (all->map[*i][*j] == '\0')
				break ;
			else if (all->map[*i][*j] != '1' && all->map[*i][*j] != ' ')
				return (0);
			*j += 1;
		}
	}
	return (1);
}

int	valid_map(t_all *all)
{
	int	i;
	int	j;

	i = -1;
	while (++i < all->sizemap)
	{
		if (!valid_start_end(all, &i, &j))
			return (0);
		if (i > 0 && i < all->sizemap - 1)
		{
			j = 0;
			while (all->map[i][j] == ' ')
				j++;
			if (all->map[i][j] != '1' ||
					all->map[i][ft_strlen(all->map[i]) - 1] != '1')
				return (0);
			while (all->map[i][++j] != '\0')
			{
				if (!map_angle(i, j, all))
					return (0);
			}
		}
	}
	return (1);
}

int	check_map(t_all *all, int *i)
{
	int	k;
	int	j;

	k = 0;
	while (*i < all->size)
	{
		all->map[k] = (char *)malloc(sizeof(char)
				* (ft_strlen(all->conf[*i]) + 1));
		if (!all->map[k])
		{
			get_error("Failed to allocate memory");
			return (0);
		}
		j = -1;
		while (all->conf[*i][++j])
			all->map[k][j] = all->conf[*i][j];
		all->map[k++][j] = '\0';
		*i += 1;
	}
	if (!valid_map(all))
	{
		get_error("Invalid map");
		return (0);
	}
	return (1);
}
