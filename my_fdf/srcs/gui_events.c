/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta <iubieta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 19:22:10 by iubieta           #+#    #+#             */
/*   Updated: 2024/06/30 17:55:10 by iubieta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

int	close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

void	window_ctrl(int keycode)
{
	if (keycode == 65307)
		exit(0);
}

void	camera_angle_ctrl(int keycode, t_gui *gui)
{
	if (keycode == 119)
		gui->camera->x_angle += 0.05;
	else if (keycode == 115)
		gui->camera->x_angle -= 0.05;
	else if (keycode == 113)
		gui->camera->y_angle -= 0.05;
	else if (keycode == 101)
		gui->camera->y_angle += 0.05;
	else if (keycode == 100)
		gui->camera->z_angle += 0.05;
	else if (keycode == 97)
		gui->camera->z_angle -= 0.05;
}

void	camera_pos_ctrl(int keycode, t_gui *gui)
{
	if (keycode == 65363)
		gui->camera->x_offset -= gui->width / 100;
	else if (keycode == 65361)
		gui->camera->x_offset += gui->width / 100;
	else if (keycode == 65364)
		gui->camera->y_offset -= gui->height / 100;
	else if (keycode == 65362)
		gui->camera->y_offset += gui->height / 100;
}

int	handle_key(int keycode, void *param)
{
	t_gui	*gui;

	gui = (t_gui *)param;
	window_ctrl(keycode);
	camera_angle_ctrl(keycode, gui);
	camera_pos_ctrl(keycode, gui);
	if (keycode == 43)
		gui->camera->zoom += 1;
	else if (keycode == 45)
		gui->camera->zoom -= 1;
	clear_image(&gui->img, gui->width, gui->height);
	draw_map(gui, *gui->map, *gui->camera);
	return (0);
}
