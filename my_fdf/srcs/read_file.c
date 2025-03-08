/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:33:19 by iubieta           #+#    #+#             */
/*   Updated: 2024/07/15 20:21:45 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

int		fdf_width(char *file);
int		fdf_height(char	*file);
void	fdf_save_array(int fd, t_map *map);

t_map	*fdf_load_map(char *file)
{
	t_map	*map;
	int		width;
	int		height;
	int		fd;

	width = fdf_width(file);
	ft_printf("Ancho: %i\n",width);
	height = fdf_height(file);
	ft_printf("Alto: %i\n",height);
	map = new_map(width, height);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("ERROR");
		exit(EXIT_FAILURE);
	}
	fdf_save_array(fd, map);
	return (map);
}

int	fdf_width(char *file)
{
	int		fd;
	char	*line;
	char	*word;
	int		width;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (perror("ERROR"), exit(EXIT_FAILURE), 0);
	line = get_next_line(fd);
	while (line)
	{
		word = line;
		width = 0;
		if (*word == ' ')
			width--;
		while (word)
		{
			word = next_word(word);
			width++;
		}
		free(line);
		line = get_next_line(fd);
	}
	return (free(line), line = NULL, close(fd), width);
}

int	fdf_height(char	*file)
{
	int		fd;
	char	*line;
	int		height;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("ERROR");
		exit(EXIT_FAILURE);
	}
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		height++;
	}
	close(fd);
	return (height);
}

void	fdf_save_array(int fd, t_map *map)
{
	int		x;
	int		y;
	char	*str_point;
	char	*del;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		str_point = get_next_line(fd);
		del = str_point;
		while (++x < map->width)
		{
			//ft_printf("(%i,%i)\n",y,x);
			map->array[y][x].x = x;
			map->array[y][x].y = y;
			map->array[y][x].z = ft_atoi(str_point);
			map->array[y][x].color = 0x00FFFFFF;
			str_point = next_word(str_point);
		}
		free(del);
		del = NULL;
	}
	get_next_line(fd);
}
