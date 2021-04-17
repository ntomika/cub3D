#include "header.h"

int	check_R(t_all *all)
{
	int	i;
	int	r;

	i = -1;
	r = 0;
	while (++i < all->size - all->sizemap)
	{
		if (all->conf[i][0] == 'R' && all->conf[i][1] == ' ')
		{
			if (!(open_r_key(all->conf[i], all)))
				return (0);
			r++;
		}
	}
	if (r == 0 || r > 1)
		return (0);
	return (1);
}

int	check_F(t_all *all)
{
	int	i;
	int	f;

	i = -1;
	f = 0;
	while (++i < all->size - all->sizemap)
	{
		if (all->conf[i][0] == 'F' && all->conf[i][1] == ' ')
		{
			if (!(open_f_key(all->conf[i], all)))
				return (0);
			f++;
		}
	}
	if (f == 0 || f > 1)
		return (0);
	return (1);
}

int	check_C(t_all *all)
{
	int	i;
	int	c;

	i = -1;
	c = 0;
	while (++i < all->size - all->sizemap)
	{
		if (all->conf[i][0] == 'C' && all->conf[i][1] == ' ')
		{
			if (!(open_c_key(all->conf[i], all)))
				return (0);
			c++;
		}
	}
	if (c == 0 || c > 1)
		return (0);
	return (1);
}

int	overflow(long key)
{
	int	i;

	i = 0;
	while (key > 0)
	{
		key /= 10;
		i++;
	}
	if (i > 8)
		return (0);
	return (1);
}
