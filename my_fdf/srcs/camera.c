/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:00:07 by iubieta-          #+#    #+#             */
/*   Updated: 2024/06/20 19:40:12 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

t_cam	*cam_init(t_map map, t_gui gui)
{
    t_cam *camera = (t_cam *)malloc(sizeof(t_cam));
    if (!camera)
    {
        fprintf(stderr, "Error: malloc for camera failed\n");
        exit(EXIT_FAILURE);
    }
    camera->zoom = gui.height / map.height / 2.5;
	if (gui.width < gui.height) 
		camera->zoom = gui.width / map.width / 2.5;
    camera->x_angle = ft_rad(30);
    camera->y_angle = ft_rad(30);
    camera->z_angle = 0;
    camera->z_height = 1.0f;
    camera->x_offset = gui.width / 2;
    camera->y_offset = gui.height / 2;
    return camera;
}

void	cam_iso(t_cam *camera)
{
	camera->x_angle = ft_rad(30);
    camera->y_angle = ft_rad(30);
    camera->z_angle = 0;
}

void	cam_home(t_cam *camera, t_map map, t_gui gui)
{
	camera->zoom = gui.height / map.height;
	if (gui.width < gui.height) 
		camera->zoom = gui.width / map.width;
    camera->z_height = 1.0f;
    camera->x_offset = gui.width / 2;
    camera->y_offset = gui.height / 2;
}

t_point project_point(t_point point, t_cam *camera)
{
    t_point projected_point;
    float x;
    float y;
    float z;

	x = point.x * camera->zoom;
	y = point.y * camera->zoom;
	z = point.z * camera->zoom / camera->z_height;
	projected_point.x = (int)((x - y) * cos(camera->x_angle) + camera->x_offset);
	projected_point.y = (int)((x + y) * sin(camera->y_angle) - z + camera->y_offset);
    projected_point.color = point.color;
    return projected_point;
}
