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

typedef	struct 	s_line {
	int dif_x;
	int dif_y;
	int move_x;
	int	move_y;
	int error;
}				t_line;


void	draw_point(t_gui *gui, t_point p, int color)
{
	int	i;

	if (p.x >= 0 && p.x < gui->width && p.y >= 0 && p.y < gui->height)
	{
		i = (p.x * gui->img.bits_per_pixel / 8) + (p.y * gui->img.line_length);
		gui->img.addr[++i] = color & 0xFF;
        gui->img.addr[++i] = (color >> 8) & 0xFF;
        gui->img.addr[++i] = (color >> 16) & 0xFF;
	}
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_line(t_gui *gui, t_point p0, t_point p1)
{
	t_line	line;
	int 	error_double;

	init_line(&line, p0, p1);;
	while (p0.x != p1.x || p0.y != p1.y)
	{
		draw_point(gui, p0, 0xFFFFFF);
		error_double = line.error * 2;
		if (error_double > -line.dif_y)
		{
			line.error -= line.dif_y;
			p0.x += line.move_x;  
		}
		if (error_double < line.dif_x)
		{
			line.error += line.dif_x;
			p0.y += line.move_y;
		}
	}
	draw_point(gui, p0, 0xFFFFFF);
}

void	init_line(t_line *line, t_point p0, t_point p1)
{
	line->dif_x = ft_abs(p1.x - p0.x);
	line->dif_y = ft_abs(p1.y - p0.y);
	line->move_x = p1.x - p0.x;
	line->move_y = p1.y - p0.y;
	line->error = line->dif_x - line->dif_y;
}

