/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 09:58:39 by iubieta           #+#    #+#             */
/*   Updated: 2024/07/09 19:42:21 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

t_img	gui_img_init(t_gui *gui, int width, int height)
{
	t_img	img;

	img.ptr = mlx_new_image(gui->mlx, width, height);
	if (!img.ptr)
	{
		perror("Failed to init image");
		exit(EXIT_FAILURE);
	}
	img.addr = mlx_get_data_addr(img.ptr, &img.bpp, &img.line_len,
			&img.endian);
	if (!img.addr)
	{
		perror("Failed to init img address");
		exit(EXIT_FAILURE);
	}
	return (img);
}

void	gui_init(t_gui *gui, int width, int height)
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
	gui->img = gui_img_init(gui, width, height);
}

void	gui_loop(t_gui *gui)
{
	mlx_hook(gui->window, 17, 0, close_window, gui);
	mlx_hook(gui->window, 2, 1L << 0, handle_key, gui);
	mlx_loop(gui->mlx);
}
