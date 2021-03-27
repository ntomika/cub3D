#include "header.h"

int check_R(t_all *all)
{
	int i = -1;
	int r = 0;

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

int check_F(t_all *all)
{
	int i = -1;
	int f = 0;

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

int check_C(t_all *all)
{
	int i = -1;
	int c = 0;

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
