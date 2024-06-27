/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta <iubieta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 19:22:10 by iubieta           #+#    #+#             */
/*   Updated: 2024/06/27 20:19:24 by iubieta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

int close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int handle_key(int keycode, void *param)
{
    t_gui *gui = (t_gui *)param;
	
	//printf("Key pressed:%i\n",keycode);

	if (keycode == 65307)
        exit(0);
    else if (keycode == 119)
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
    else if (keycode == 43)
        gui->camera->zoom += 1;
    else if (keycode == 45)
        gui->camera->zoom -= 1;
	else if (keycode == 65363)
        gui->camera->x_offset -= gui->width/100;
    else if (keycode == 65361)
        gui->camera->x_offset += gui->width/100;
	else if (keycode == 65364)
        gui->camera->y_offset -= gui->height/100;
    else if (keycode == 65362)
        gui->camera->y_offset += gui->height/100;
    clear_image(&gui->img, gui->width, gui->height);
    draw_map(gui, *gui->map, *gui->camera);
    return (0);
}
