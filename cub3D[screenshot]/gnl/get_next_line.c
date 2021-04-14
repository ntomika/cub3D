/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <ntomika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 20:26:12 by ntomika           #+#    #+#             */
/*   Updated: 2021/04/14 19:51:57 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_ost(char **ost, char **vrem)
{
	free(*ost);
	*ost = *vrem;
}

char	*ft_check_bsn(const char *s, int c)
{
	int		i;
	char	*one_str;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			one_str = (char *)&s[i];
			return (one_str);
		}
		i++;
	}
	if (s[i] == c)
	{
		one_str = (char *)&s[i];
		return (one_str);
	}
	return (NULL);
}

char	*ft_check_ost(char **ost, char **line)
{
	char	*check_bsn;
	char	*vrem;

	vrem = NULL;
	check_bsn = NULL;
	if (*ost)
	{
		check_bsn = ft_check_bsn(*ost, '\n');
		if (check_bsn)
		{
			*check_bsn = '\0';
			*line = ft_strdup(*ost);
			vrem = ft_strdup(++check_bsn);
			free_ost(ost, &vrem);
		}
		else
		{
			*line = ft_strdup(*ost);
			free(*ost);
			*ost = NULL;
		}
	}
	else
		*line = ft_new(1);
	return (check_bsn);
}

int	ft_return(int fd, char **line, char *check_bsn, char **ost)
{
	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (!*ost && !check_bsn)
		return (0);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*ost;
	char		buf[BUFFER_SIZE + 1];
	char		*check_bsn;
	int			rd;

	check_bsn = ft_check_ost(&ost, line);
	rd = 1;
	while (!check_bsn && rd)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd < 0)
			return (-1);
		buf[rd] = '\0';
		check_bsn = ft_check_bsn(buf, '\n');
		if (check_bsn)
		{
			*check_bsn = '\0';
			ost = ft_strdup(++check_bsn);
		}
		write_line(line, buf);
	}
	return (ft_return(fd, line, check_bsn, &ost));
}
