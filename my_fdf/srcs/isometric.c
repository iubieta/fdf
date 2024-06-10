/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta <iubieta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:25:52 by iubieta           #+#    #+#             */
/*   Updated: 2024/06/10 18:29:10 by iubieta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void top_to_iso(int x, int y, int z, t_point *iso)
{
	float	angle_x;
	float	angle_y;
	
	angle_x = M_PI / 6;
    iso->x = x;
    iso->y = y * cos(angle_x) - z * sin(angle_x);
    iso->z = y * sin(angle_x) + z * cos(angle_x);
	
    angle_y = M_PI / 6;
	iso->x = x1 * cos(angle_y) + z1 * sin(angle_y);
    double y2 = y1;
    double z2 = -x1 * sin(angle_y) + z1 * cos(angle_y);

    // Proyección isométrica
    *x_iso = x2;
    *y_iso = y2;
}
// Function to rotate a point around the X-axis
Point3D rotateX(Point3D p, double angle) {
    Point3D result;
    double rad = angle * PI / 180.0;
    result.x = p.x;
    result.y = p.y * cos(rad) - p.z * sin(rad);
    result.z = p.y * sin(rad) + p.z * cos(rad);
    return result;
}

// Function to rotate a point around the Y-axis
Point3D rotateY(Point3D p, double angle) {
    Point3D result;
    double rad = angle * PI / 180.0;
    result.x = p.x * cos(rad) + p.z * sin(rad);
    result.y = p.y;
    result.z = -p.x * sin(rad) + p.z * cos(rad);
    return result;
}

// Function to rotate a point around the Z-axis
Point3D rotateZ(Point3D p, double angle) {
    Point3D result;
    double rad = angle * PI / 180.0;
    result.x = p.x * cos(rad) - p.y * sin(rad);
    result.y = p.x * sin(rad) + p.y * cos(rad);
    result.z = p.z;
    return result;
}