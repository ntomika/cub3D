#include "header.h"

void 			get_map(char **argv, int argc, t_all *all)
{
	int 	fd;
	int 	i = 0;
	char 	*line = NULL;
	int 	size = 0;

	all->sizemap = 1;
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	if (argc == 3)
		fd = open(argv[2], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (*line == ' ' || *line == '1')
			all->sizemap++;
		size++;
	}
	close(fd);
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	if (argc == 3)
		fd = open(argv[2], O_RDONLY);
//	else
//		get_error();
	if (!(all->conf = (char **)malloc(sizeof(char *) * (size + 1))))
	{
		get_error("Failed to allocate memory");
		return ;
	}
	while(i < size)
	{
		get_next_line(fd, &all->conf[i]);
		i++;
	}
	get_next_line(fd, &all->conf[i]);
	close(fd);
//	i = -1;
//	printf("conf :\n");
//	while (all->conf[++i])
//		printf("%s\n", all->conf[i]);
//	write(1, "\n", 1);
}


 void		plr_bihavior(t_all *all)
 {
 	int i = -1;
 	int flag = 0;
 	while (all->map[++i])
 	{
 		int j = -1;
 		while (all->map[i][++j])
 		{
 			if (ft_strchr("NSWE", all->map[i][j]))
 			{
 				all->plr.player_x = j * SCALE;
 				all->plr.player_y = i * SCALE;
 				all->plr.poz = all->map[i][j];
 				check_player(all);
 				flag++;
 			}
 		}
 	}
 	if (flag > 1)
 		get_error("The map must contain only one player");
 }

int main(int argc, char **argv)
{
	t_all 	all;

	get_map(argv, argc, &all);
	check_valid(&all);
	all.img.mlx = mlx_init();
	all.img.win = mlx_new_window(all.img.mlx, 1080, 1080, "testCUB");
	plr_bihavior(&all);
	print_map(&all);
	mlx_hook(all.img.win, 2, 1L<<0, &key_hook, &all);
	mlx_loop(all.img.mlx);
	return (0);
}