/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 06:55:13 by junmkang          #+#    #+#             */
/*   Updated: 2021/02/03 09:03:20 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "save_screen.h"


void save_screen_chk(char *line, t_map *map)
{
	if (!ft_strncmp(line, "--save", 6))
		map->save_bool = 1;
	else
	{
		printf("argv[2] = %s\n", line);
		ft_error("Invalid input value : argv[2]");
	}
}

size_t	put_data_fd(int fd, size_t data, size_t size)
{
	return (write(fd, &data, size));
}

/*
**	2		bf type (BM)
**	4		bf size
**	2 + 2	bfReserved
**	4		start dir
**	4		header byte : (40).
**	4		screen_X
**	4		screen_Y
**	4		color num (1)
**	4		bpp
**	4 * 6
**			arr
*/

void		save_screen(t_ray_info *ray_info)
{
	int		bitmap_sizeline;
	int		fd;
	int		j;

	bitmap_sizeline = (ray_info->screen_X * ray_info->img[0].bpp / 8);
	fd = open("cub3d_save.bmp", O_RDWR);
	if (fd < 0)
		ft_error("cub3d_save.bmp file does not exist.");
	write(fd, "BM", 2);
	put_data_fd(fd, ray_info->screen_Y * (bitmap_sizeline) + 54, 4);
	put_data_fd(fd, 0, 4);
	put_data_fd(fd, 54, 4);
	put_data_fd(fd, 40, 4);
	put_data_fd(fd, ray_info->screen_X, 4);
	put_data_fd(fd, ray_info->screen_Y, 4);
	put_data_fd(fd, 1, 2);
	put_data_fd(fd, 32, 2);
	j = -1;
	while (++j < 6)
		put_data_fd(fd, 0, 4);
	j = ray_info->screen_Y;
	while (--j >= 0)
		write(fd, ray_info->img[0].data + (ray_info->img[0].size_l / 4) * j, \
			(bitmap_sizeline));
	close(fd);
	exit(0);
}