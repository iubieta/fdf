/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D_rotations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta <iubieta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:25:52 by iubieta           #+#    #+#             */
/*   Updated: 2024/06/11 18:27:24 by iubieta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

t_point rot_x(t_point p, float angle) {
    t_point new_point;
    float rad;
    rad = angle * M_PI / 180.0;
    new_point.x = p.x;
    new_point.y = p.y * cos(rad) - p.z * sin(rad);
    new_point.z = p.y * sin(rad) + p.z * cos(rad);
    new_point.next = p.next;
    return (new_point);
}

t_point rot_y(t_point p, float angle) {
    t_point new_point;
    float rad;
    rad = angle * M_PI / 180.0;
    new_point.x = p.x * cos(rad) + p.z * sin(rad);
    new_point.y = p.y;
    new_point.z = -p.x * sin(rad) + p.z * cos(rad);
    new_point.next = p.next;
    return (new_point);
}

t_point rot_z(t_point p, float angle) {
    t_point new_point;
    float rad;
    rad = angle * M_PI / 180.0;
    new_point.x = p.x * cos(rad) - p.y * sin(rad);
    new_point.y = p.x * sin(rad) + p.y * cos(rad);
    new_point.z = p.z;
    new_point.next = p.next;
    return (new_point);
}

void   map_rotation(t_map *map, t_point (*func)(t_point, float), float angle){
    t_point *current;
    t_point *head;
    
    current = map->head;
    head = current;
    while (current)
    {
        //printf("x:%i, y:%i, z:%i\n", current->x, current->y, current->z);
        *current = func(*current, angle);
        //printf("x:%i, y:%i, z:%i\n\n", current->x, current->y, current->z);
        current = current->next;
    }
    map->head = head;
}

void    map_translation(t_map *map, char axis, float distance)
{
    t_point *current;
    t_point *head;
    
    current = map->head;
    head = current;
    while (current)
    {
        //printf("x:%i, y:%i, z:%i\n", current->x, current->y, current->z);
        if (axis == 'x')
            current->x += distance;
        else if (axis == 'y')
            current->y += distance;
        else if (axis == 'z')
            current->z += distance;
        //printf("x:%i, y:%i, z:%i\n\n", current->x, current->y, current->z);
        current = current->next;
    }
    map->head = head;
}

t_point isometric_rot(t_point point)
{
    t_point new_point;
    
    new_point = rot_x(point, 30);
    new_point = rot_y(new_point, 30);
    return (new_point);
}

t_point point_projection(t_point point_3d, float fov, float distance)
{
    t_point point_2d;
    float   factor;
    
    factor = fov / (point_3d.z + distance);
    point_2d.x = point_3d.x * factor;
    point_2d.y = point_3d.y * factor;
    return (point_2d);
}
