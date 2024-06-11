/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta <iubieta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 09:58:39 by iubieta           #+#    #+#             */
/*   Updated: 2024/06/11 20:08:29 by iubieta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void gui_init(t_gui *gui)
{
	gui->mlx = mlx_init();
	gui->width = 500;
	gui->height = 500;
	gui->window = mlx_new_window(gui->mlx, gui->width, gui->height, "FdF");
	gui->img.img = mlx_new_image(gui->mlx, gui->width, gui->height);
	gui->img.addr = mlx_get_data_addr(gui->img.img, &gui->img.bits_per_pixel, &gui->img.line_length,
								&gui->img.endian);
}

void gui_loop(t_gui *gui)
{
	mlx_hook(gui->window, 17, 0, close_window, NULL);
    mlx_loop(gui->mlx);
}

int close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}