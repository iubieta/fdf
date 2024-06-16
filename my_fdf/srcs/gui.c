/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta <iubieta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 09:58:39 by iubieta           #+#    #+#             */
/*   Updated: 2024/06/16 19:16:34 by iubieta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void gui_init(t_gui *gui, int width, int height)
{
	gui->mlx = mlx_init();
	if (!gui->mlx)
	{
		perror("Failed to init mlx");
		exit(EXIT_FAILURE);
	}
	gui->width = width;
	gui->height = height;
	gui->window = mlx_new_window(gui->mlx, gui->width, gui->height, "FdF");
	if (!gui->window)
	{
		perror("Failed to init window");
		exit(EXIT_FAILURE);
	}
	gui->img.ptr = mlx_new_image(gui->mlx, gui->width, gui->height);
	if (!gui->img.ptr)
	{
		perror("Failed to init image");
		exit(EXIT_FAILURE);
	}
	gui->img.addr = mlx_get_data_addr(gui->img.ptr, &gui->img.bpp, &gui->img.line_len, &gui->img.endian);
	if (!gui->img.addr)
	{
		perror("Failed to init img address");
		exit(EXIT_FAILURE);
	}
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