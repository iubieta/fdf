/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D_rotations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta <iubieta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:25:52 by iubieta           #+#    #+#             */
/*   Updated: 2024/06/10 18:58:41 by iubieta          ###   ########.fr       */
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
    return (new_point);
}

t_point rot_y(t_point p, float angle) {
    t_point new_point;
    float rad;
    rad = angle * M_PI / 180.0;
    new_point.x = p.x * cos(rad) + p.z * sin(rad);
    new_point.y = p.y;
    new_point.z = -p.x * sin(rad) + p.z * cos(rad);
    return (new_point);
}

t_point rot_z(t_point p, float angle) {
    t_point new_point;
    float rad;
    rad = angle * M_PI / 180.0;
    new_point.x = p.x * cos(rad) - p.y * sin(rad);
    new_point.y = p.x * sin(rad) + p.y * cos(rad);
    new_point.z = p.z;
    return (new_point);
}

t_point isometric_rot(t_point point)
{
    t_point new_point;
    
    new_point = rot_x(point, 30);
    new_point = rot_y(new_point, 30);
    return (new_point);
}