#include "header.h"

int		open_NO(char *s, t_all *all)
{
//	int fd;
	int i = 2;
	int j = 0;

	while (s[i] == ' ')
		i++;
	if (!(all->key.NO_texture = (char*)malloc(sizeof(char) * ((ft_strlen(s) -
															   i) + 1))))
		return (0);
	while (s[i] && s[i] != ' ')
		all->key.NO_texture[j++] = s[i++];
	all->key.NO_texture[j] = '\0';
	if (!all->key.NO_texture)
		return (0);
	printf("NO_texture = {%s}\n", all->key.NO_texture);
//	if ((fd = open(all->key.NO_texture, O_RDONLY)) == -1)
//		return (0);
//	else
//	{
//		all->key.img_NO = mlx_xpm_file_to_image(all->img.mlx, all->key.NO_texture,
//											   &all->key.img_NO_w,
//											   &all->key.img_NO_h);
//		close(fd);
//	}
	return (1);
}

int		open_SO(char *s, t_all *all)
{
//	int fd;
	int i = 2;
	int j = 0;

	while (s[i] == ' ')
		i++;
	if (!(all->key.SO_texture = (char*)malloc(sizeof(char) * ((ft_strlen(s) -
															   i) + 1))))
		return (0);
	while (s[i] && s[i] != ' ')
		all->key.SO_texture[j++] = s[i++];
	all->key.SO_texture[j] = '\0';
	if (!all->key.SO_texture)
		return (0);
	printf("SO_texture = {%s}\n", all->key.SO_texture);
//	if ((fd = open(all->key.SO_texture, O_RDONLY)) == -1)
//		return (0);
//	else
//	{
//		all->key.img_SO = mlx_xpm_file_to_image(all->img.mlx, all->key.SO_texture,
//											   &all->key.img_SO_w,
//											   &all->key.img_SO_h);
//		close(fd);
//	}
	return (1);
}

int		open_WE(char *s, t_all *all)
{
	int i = 2;
	int j = 0;
//	int fd;

	while (s[i] == ' ')
		i++;
	if (!(all->key.WE_texture = (char*)malloc(sizeof(char) * ((ft_strlen(s) -
															   i) + 1))))
		return (0);
	while (s[i] && s[i] != ' ')
		all->key.WE_texture[j++] = s[i++];
	all->key.WE_texture[j] = '\0';
	if (!all->key.WE_texture)
		return (0);
	printf("WE_texture = {%s}\n", all->key.WE_texture);
//	if ((fd = open(all->key.WE_texture, O_RDONLY)) == -1)
//		return (0);
//	else
//	{
//		all->key.img_S = mlx_xpm_file_to_image(all->img.mlx, all->key.WE_texture,
//											   &all->key.img_WE_w,
//											   &all->key.img_WE_h);
//		close(fd);
//	}
	return (1);
}

int		open_EA(char *s, t_all *all)
{
	int i = 2;
	int j = 0;
//	int fd;

	while (s[i] == ' ')
		i++;
	if (!(all->key.EA_texture = (char*)malloc(sizeof(char) * ((ft_strlen(s) -
			i) + 1))))
		return (0);
	while (s[i] && s[i] != ' ')
		all->key.EA_texture[j++] = s[i++];
	all->key.EA_texture[j] = '\0';
	if (!all->key.EA_texture)
		return (0);
	printf("EA_texture = {%s}\n", all->key.EA_texture);
//	if ((fd = open(all->key.EA_texture, O_RDONLY)) == -1)
//		return (0);
//	else
//	{
//		all->key.img_EA = mlx_xpm_file_to_image(all->img.mlx, all->key.EA_texture,
//											   &all->key.img_EA_w,
//											   &all->key.img_EA_h);
//		close(fd);
//	}
	return (1);
}

int		open_S(char *s, t_all *all)
{
	int i = 1;
	int j = 0;
//	int fd;

	while (s[i] == ' ')
		i++;
	if (!(all->key.S_texture = (char*)malloc(sizeof(char) * ((ft_strlen(s) - i) + 1))))
		return (0);
	while (s[i] && s[i] != ' ')
		all->key.S_texture[j++] = s[i++];
	all->key.S_texture[j] = '\0';
	if (!all->key.S_texture)
		return (0);
	printf("S_texture = {%s}\n", all->key.S_texture);
//	if ((fd = open(all->key.S_texture, O_RDONLY)) == -1)
//		return (0);
//	else
//	{
//		all->key.img_S = mlx_xpm_file_to_image(all->img.mlx, all->key.S_texture,
//											   &all->key.img_S_w,
//											   &all->key.img_S_h);
//		close(fd);
//	}
	return (1);
}

