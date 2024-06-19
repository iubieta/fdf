/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D_points.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:05:30 by iubieta           #+#    #+#             */
/*   Updated: 2024/06/19 19:09:31 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void	init_map_array(t_map *map, int width, int height);

t_point *new_point(int x, int y, int z)
{
	t_point *point;
	point = (t_point *)malloc(sizeof (t_point));
	if (!point) {
		perror("Error: malloc for point failed");
		exit(EXIT_FAILURE);
	}
	point->x = x;
	point->y = y;
	point->z = z;
	point->color = 0x00FFFFFF;
	return (point);
}

t_map *new_map(int width, int height)
{
    t_map	*map;

    map = (t_map *)malloc(sizeof(t_map));
    if (!map)
    {
        perror("Error: malloc for map failed");
        
    }
	map->width = width;
	map->height = height;
	//init_map_array(map, width, height);
	int i;

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
    return (map);
}

void	init_map_array(t_map *map, int width, int height)
{
	int i;

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
}
