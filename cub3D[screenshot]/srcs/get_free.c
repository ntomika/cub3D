#include "header.h"
void	get_free_conf(t_all *all)
{
	int	c;

	c = all->size;
	while (c-- > 0)
		free(all->conf[c]);
	free(all->conf);
}

void	get_free_map(t_all *all)
{
	int	c;

	c = all->sizemap;
	while (c-- > 0)
		free(all->map[c]);
	free(all->map);
}

void	get_free_bufer(t_all *all)
{
	int	h;

	h = all->key.h;
	while (h-- > 0)
		free(all->gr.bufer[h]);
	free(all->gr.bufer);
}

void	get_free_textures(t_all *all)
{
	int i;

	i = 5;
	while (i-- > 0)
		free(all->gr.texture[i]);
}
