/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta <iubieta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:29:48 by iubieta           #+#    #+#             */
/*   Updated: 2024/06/30 17:23:49 by iubieta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void	draw_point(t_gui *gui, t_point p, int color)
{
	int	i;

	if (p.x >= 0 && p.x < gui->width && p.y >= 0 && p.y < gui->height)
	{
		i = (p.x * gui->img.bpp / 8) + (p.y * gui->img.line_len);
		gui->img.addr[i] = color & 0xFF;
		gui->img.addr[++i] = (color >> 8) & 0xFF;
		gui->img.addr[++i] = (color >> 16) & 0xFF;
	}
}

void	init_line(t_line *line, t_point p0, t_point p1)
{
	line->dif_x = ft_abs(p1.x - p0.x);
	line->dif_y = ft_abs(p1.y - p0.y);
	line->move_x = ft_sign(p1.x - p0.x);
	line->move_y = ft_sign(p1.y - p0.y);
	line->error = line->dif_x - line->dif_y;
}

void	draw_line(t_gui *gui, t_point p0, t_point p1)
{
	t_line	line;
	int		error_double;

	init_line(&line, p0, p1);
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

void	draw_map(t_gui *gui, t_map map, t_cam camera)
{
	int		x;
	int		y;
	t_point	start;
	t_point	end;

	y = -1;
	while (++y < map.height)
	{
		x = -1;
		while (++x < map.width)
		{
			start = project_point(map.array[y][x], camera);
			if (x < map.width - 1)
			{
				end = project_point(map.array[y][x + 1], camera);
				draw_line(gui, start, end);
			}
			if (y < map.height - 1)
			{
				end = project_point(map.array[y + 1][x], camera);
				draw_line(gui, start, end);
			}
		}
	}
	mlx_put_image_to_window(gui->mlx, gui->window, gui->img.ptr, 0, 0);
}

void	clear_image(t_img *image, int width, int height)
{
	int	x;
	int	y;
	int	color;
	int	i;

	color = 0x000000;
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			i = (y * image->line_len) + (x * (image->bpp / 8));
			image->addr[i] = color & 0xFF;
			image->addr[++i] = (color >> 8) & 0xFF;
			image->addr[++i] = (color >> 16) & 0xFF;
			x++;
		}
		y++;
	}
}
