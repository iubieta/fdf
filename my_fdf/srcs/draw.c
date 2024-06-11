/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta <iubieta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:29:48 by iubieta           #+#    #+#             */
/*   Updated: 2024/06/11 22:07:46 by iubieta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void draw_2d_point(t_gui *gui, t_point point)
{
	int	x0;
	int	y0;
	//int color;

	x0 = 0;//gui->width / 2;
	y0 = 0;//gui->height / 2;
	//color = 0x00FFFFFF; //Ajustar color en funcion de 'z'
	my_mlx_pixel_put(gui->img.img, x0 + point.x, y0 + point.y, 0x00FFFFFF);
}

void my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

