#include "header.h"
void get_free_conf(t_all *all)
{
	while (all->size >= 0)
		free((void *)all->conf[--all->size]);
	free(all->conf);
}
void get_free_map(t_all *all)
{
	while (all->sizemap >= 0)
		free((void *)all->map[--all->sizemap]);
	free(all->map);
	//	get_error("Incomplete set of identifier settings");
	return;
}
