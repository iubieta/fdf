/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D_points.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta <iubieta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:05:30 by iubieta           #+#    #+#             */
/*   Updated: 2024/06/16 19:36:50 by iubieta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

t_point *new_point(int x, int y, int z)
{
	t_point *point;
	point = malloc(sizeof(t_point));
	if (!point) {
		perror("Failed to malloc point");
		return NULL;
	}
	point->x = x;
	point->y = y;
	point->z = z;
	point->color = 0x00FFFFFF;
	return (point);
}

t_map *init_map(void)
{
    t_map *map;

    map = (t_map *)malloc(sizeof(t_map));
    if (!map)
    {
        perror("Error: malloc for map failed");
        exit(EXIT_FAILURE);
    }
	map->array = NULL;
	map->width = 0;
	map->height = 0;
    return (map);
}

