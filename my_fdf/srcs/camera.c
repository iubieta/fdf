/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta <iubieta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:00:07 by iubieta-          #+#    #+#             */
/*   Updated: 2024/06/22 20:21:12 by iubieta          ###   ########.fr       */
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
	camera->x_angle = ft_rad(-30);
	camera->y_angle = ft_rad(0);
	camera->z_angle = ft_rad(-40);
	camera->z_height = 10.0f;
	camera->x_offset = gui.width / 3;
	camera->y_offset = gui.height / 6;
	return camera;
}

t_point cam_zoom(t_point point, t_cam camera)
{
	point.x = point.x * camera.zoom;
	point.y = point.y * camera.zoom;
	point.z = point.z * camera.zoom / camera.z_height;
	return (point);
}

t_point cam_angle(t_point point, t_cam camera)
{
	int	temp_x;
	int	temp_y;

	temp_y = point.y * cos(camera.x_angle) - point.z * sin(camera.x_angle);
    point.z = point.y * sin(camera.x_angle) + point.z * cos(camera.x_angle);
	point.y = temp_y;
    temp_x = point.x * cos(camera.y_angle) + point.z * sin(camera.y_angle);
    point.z = -point.x * sin(camera.y_angle) + point.z * cos(camera.y_angle);
    point.x = temp_x;
    temp_x = point.x * cos(camera.z_angle) - point.y * sin(camera.z_angle);
    point.y = point.x * sin(camera.z_angle) + point.y * cos(camera.z_angle);
    point.x = temp_x;
	return (point);
}

t_point project_point(t_point point, t_cam camera)
{
	point = cam_zoom(point, camera);
	point = cam_angle(point, camera);
	point.x = (int)((point.x - point.y) * cos(ft_rad(60)) + camera.x_offset);
	point.y = (int)((point.x + point.y) * sin(ft_rad(30)) - point.z + camera.y_offset);
	return (point);
}
