/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta <iubieta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:33:19 by iubieta           #+#    #+#             */
/*   Updated: 2024/06/18 19:57:20 by iubieta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"


void	fdf_load_map(char *file, t_map *map)
{
	int	width;
	int height;

	width = fdf_width;
	height = fdf_height;
	map = new_map(width, height);
	fdf_save_array(file, map);
}

int	fdf_width(char *file)
{
	int 	fd;
	char	*line;
	int		width;

	fd = open(file, O_RDONLY);
	if (fd == -1) {
		perror("Error al abrir el archivo");
		return (1);
	}
	line = get_next_line(fd);
	width = ft_str_len(line);
	return (width);
}

int	fdf_height(char	*file)
{
	int 	fd;
	char	*line;
	int		height;

	fd = open(file, O_RDONLY);
	if (fd == -1) {
		perror("Error al abrir el archivo");
		return (1);
	}
	while (get_next_line(fd))
		height++;
	return (height);
}

void	fdf_save_array(char *file, t_map *map)
{
	int 	fd;
	int		x;
	int		y;
	char	*str_point;

	fd = open(file, O_RDONLY);
	if (fd == -1) {
		perror("Error al abrir el archivo");
		return (1);
	}
	x = 0;
	y = 0;
	while (y < map->height)
	{
		str_point = get_next_line(fd);
		while (x < map->width)
		{
			map->array[y][x].x = x++;
			map->array[y][x].y = y;
			map->array[y][x].z = ft_atoi(str_point);
			map->array[y][x].color = 0x00FFFFFF;
			str_point = next_word(str_point);
		}
		y++;
	}
}
