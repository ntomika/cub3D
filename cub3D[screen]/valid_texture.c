#include "header.h"

int		check_S(t_all *all)
{
	int	i = -1;
	int	s = 0;

	while (++i < all->size - all->sizemap)
	{
		if (all->conf[i][0] == 'S' && all->conf[i][1] == ' ')
		{
			if (!(open_S(all->conf[i], all)))
				return (0);
			s++;
		}
	}
	if (s == 0 || s > 1)
		return (0);
	return (1);
}

int		check_NO(t_all *all)
{
	int i = -1;
	int no = 0;

	while (++i < all->size - all->sizemap)
	{
		if (all->conf[i][0] == 'N' && all->conf[i][1] == 'O')
		{
			if (!(open_NO(all->conf[i], all)))
				return (0);
			no++;
		}
	}
	if (no == 0 || no > 1)
		return (0);
	return (1);
}

int		check_SO(t_all *all)
{
	int	i = -1;
	int	so = 0;

	while (++i < all->size - all->sizemap)
	{
		if (all->conf[i][0] == 'S' && all->conf[i][1] == 'O')
		{
			if (!(open_SO(all->conf[i], all)))
				return (0);
			so++;
		}
	}
	if (so == 0 || so > 1)
		return (0);
	return (1);
}

int		check_WE(t_all *all)
{
	int	i = -1;
	int	we = 0;

	while (++i < all->size - all->sizemap)
	{
		if (all->conf[i][0] == 'W' && all->conf[i][1] == 'E')
		{
			if (!(open_WE(all->conf[i], all)))
				return (0);
			we++;
		}
	}
	if (we == 0 || we > 1)
		return (0);
	return (1);
}

int		check_EA(t_all *all)
{
	int	i = -1;
	int	ea = 0;

	while (++i < all->size - all->sizemap)
	{
		if (all->conf[i][0] == 'E' && all->conf[i][1] == 'A')
		{
			if (!(open_EA(all->conf[i], all)))
				return (0);
			ea++;
		}
	}
	if (ea == 0 || ea > 1)
		return (0);
	return (1);
}
