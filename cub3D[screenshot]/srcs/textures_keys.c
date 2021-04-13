#include "header.h"

int	open_NO(char *s, t_all *all)
{
	int	fd;
	int	i;
	int	j;

	i = 2;
	j = 0;
	while (s[i] == ' ')
		i++;
	all->key.NO_texture = (char *)malloc(sizeof(char)
			* ((ft_strlen(s) - i) + 1));
	if (!all->key.NO_texture)
		return (0);
	while (s[i] && s[i] != ' ')
		all->key.NO_texture[j++] = s[i++];
	all->key.NO_texture[j] = '\0';
	if (!all->key.NO_texture)
		return (0);
	fd = open(all->key.NO_texture, O_RDONLY);
	if (fd == -1)
		return (0);
	else
		close(fd);
	return (1);
}

int	open_SO(char *s, t_all *all)
{
	int	fd;
	int	i;
	int	j;

	i = 2;
	j = 0;
	while (s[i] == ' ')
		i++;
	all->key.SO_texture = (char *)malloc(sizeof(char)
			* ((ft_strlen(s) - i) + 1));
	if (!all->key.SO_texture)
		return (0);
	while (s[i] && s[i] != ' ')
		all->key.SO_texture[j++] = s[i++];
	all->key.SO_texture[j] = '\0';
	if (!all->key.SO_texture)
		return (0);
	fd = open(all->key.SO_texture, O_RDONLY);
	if (fd == -1)
		return (0);
	else
		close(fd);
	return (1);
}

int	open_WE(char *s, t_all *all)
{
	int	fd;
	int	i;
	int	j;

	i = 2;
	j = 0;
	while (s[i] == ' ')
		i++;
	all->key.WE_texture = (char *)malloc(sizeof(char)
			* ((ft_strlen(s) -i) + 1));
	if (!all->key.WE_texture)
		return (0);
	while (s[i] && s[i] != ' ')
		all->key.WE_texture[j++] = s[i++];
	all->key.WE_texture[j] = '\0';
	if (!all->key.WE_texture)
		return (0);
	fd = open(all->key.WE_texture, O_RDONLY);
	if (fd == -1)
		return (0);
	else
		close(fd);
	return (1);
}

int	open_EA(char *s, t_all *all)
{
	int	fd;
	int	i;
	int	j;

	i = 2;
	j = 0;
	while (s[i] == ' ')
		i++;
	all->key.EA_texture = (char *)malloc(sizeof(char)
			* ((ft_strlen(s) - i) + 1));
	if (!all->key.EA_texture)
		return (0);
	while (s[i] && s[i] != ' ')
		all->key.EA_texture[j++] = s[i++];
	all->key.EA_texture[j] = '\0';
	if (!all->key.EA_texture)
		return (0);
	fd = open(all->key.EA_texture, O_RDONLY);
	if (fd == -1)
		return (0);
	else
		close(fd);
	return (1);
}

int	open_S(char *s, t_all *all)
{
	int	fd;
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (s[i] == ' ')
		i++;
	all->key.S_texture = (char *)malloc(sizeof(char)
			* ((ft_strlen(s) - i) + 1));
	if (!all->key.S_texture)
		return (0);
	while (s[i] && s[i] != ' ')
		all->key.S_texture[j++] = s[i++];
	all->key.S_texture[j] = '\0';
	if (!all->key.S_texture)
		return (0);
	fd = open(all->key.S_texture, O_RDONLY);
	if (fd == -1)
		return (0);
	else
		close(fd);
	return (1);
}
