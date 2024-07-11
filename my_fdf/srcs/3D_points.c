/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D_points.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:05:30 by iubieta           #+#    #+#             */
/*   Updated: 2024/07/09 19:45:16 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

t_point	*new_point(int x, int y, int z)
{
	t_point	*point;

	point = (t_point *) malloc(sizeof(t_point));
	if (!point)
	{
		perror("ERROR");
		exit(EXIT_FAILURE);
	}
	point->x = x;
	point->y = y;
	point->z = z;
	point->color = 0x00FFFFFF;
	return (point);
}

/* int	out_of_screen(t_gui gui, t_point point)
{
	if (point.x < 0 || point.x > gui.width)
		return (1);
	if (point.y < 0 || point.x > gui.height)
		return (1);
	return (0);
} */

t_point	**init_array(int width, int height)
{
	t_point	**array;
	int		i;

	array = (t_point **)malloc(sizeof(t_point *) * height);
	if (!array)
	{
		perror("ERROR");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < height)
	{
		array[i] = (t_point *)malloc(sizeof(t_point) * width);
		if (!array[i])
		{
			perror("ERROR");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (array);
}

t_map	*new_map(int width, int height)
{
	t_map	*map;

	map = (t_map *) malloc(sizeof(t_map));
	if (!map)
	{
		perror("ERROR");
	}
	map->width = width;
	map->height = height;
	map->array = init_array(width, height);
	return (map);
}

/* 
void	init_map_array(t_map *map, int width, int height)
{
	int	i;

	map->array = (t_point **)malloc(sizeof(t_point *) * height);
	if (!map->array)
	{
		perror("Error: malloc for map array failed");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < map->height)
	{
		map->array[i] = (t_point *)malloc(sizeof(t_point) * width);
		if (!map->array[i])
		{
			perror("Error: malloc for map array row failed");
			exit(EXIT_FAILURE);
		}
		i++;
	}
} */
