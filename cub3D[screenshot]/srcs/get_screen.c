#include "header.h"

void	file_header(t_all *all, int fd)
{
	unsigned char	bmp_file[14];
	int				file_size;

	ft_bzero(bmp_file, 14);
	file_size = INFO_HEADER_SIZE + FILE_HEADER_SIZE
		+ all->key.w * all->key.h * (all->img.bits_per_pixel / 8);
	bmp_file[0] = (unsigned char)('B');
	bmp_file[1] = (unsigned char)('M');
	bmp_file[2] = (unsigned char)(file_size);
	bmp_file[3] = (unsigned char)(file_size >> 8);
	bmp_file[4] = (unsigned char)(file_size >> 16);
	bmp_file[5] = (unsigned char)(file_size >> 24);
	bmp_file[10] = (unsigned char)(INFO_HEADER_SIZE + FILE_HEADER_SIZE);
	write(fd, bmp_file, FILE_HEADER_SIZE);
}

void	info_header(t_all *all, int fd)
{
	unsigned char	bmp_info[40];

	ft_bzero(bmp_info, 40);
	bmp_info[0] = (unsigned char)(INFO_HEADER_SIZE);
	bmp_info[4] = (unsigned char)(all->key.w);
	bmp_info[5] = (unsigned char)(all->key.w >> 8);
	bmp_info[6] = (unsigned char)(all->key.w >> 16);
	bmp_info[7] = (unsigned char)(all->key.w >> 24);
	bmp_info[8] = (unsigned char)(all->key.h);
	bmp_info[9] = (unsigned char)(all->key.h >> 8);
	bmp_info[10] = (unsigned char)(all->key.h >> 16);
	bmp_info[11] = (unsigned char)(all->key.h >> 24);
	bmp_info[12] = (unsigned char)(1);
	bmp_info[14] = (unsigned char)(all->img.bits_per_pixel);
	write(fd, bmp_info, INFO_HEADER_SIZE);
}

void	get_bmp(t_all *all, int fd)
{
	int	w;
	int	h;

	h = all->key.h;
	while (h--)
	{
		w = 0;
		while (w < all->key.w)
		{
			write(fd, &all->gr.bufer[h][w], 4);
			w++;
		}
	}
}

void	get_screen(t_all *all, char **argv)
{
	int	fd;

	if (!(ft_memcmp("--save", argv[2], ft_strlen(argv[2]))))
	{	
		general(all);
		img_3d(all);
		fd = open("screen.bmp", O_CREAT | O_TRUNC | O_WRONLY, 0644);
		if (!fd)
			exit(0);
		file_header(all, fd);
		info_header(all, fd);
		get_bmp(all, fd);
		close(fd);
		exit(0);
	}
	else
	{
		get_error("The argument \"--save\" is specified incorrectly");
		exit(-1);
	}
}
