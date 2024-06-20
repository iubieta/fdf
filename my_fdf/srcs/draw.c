/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:29:48 by iubieta           #+#    #+#             */
/*   Updated: 2024/06/20 19:34:17 by iubieta-         ###   ########.fr       */
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
	int 	error_double;

	init_line(&line, p0, p1);;
	while (p0.x != p1.x || p0.y != p1.y)
	{
		printf("(%i,%i)\n", p0.x, p0.y);
		printf("Next: dx=%i dy=%i mx=%i my=%i error=%i\n",
				line.dif_x, line.dif_y, line.move_x, line.move_y, line.error);
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
	printf("(%i,%i)\n", p0.x, p0.y);
	draw_point(gui, p0, 0xFFFFFF);
}

void draw_map(t_gui *gui, t_map *map, t_cam *camera)
{
    for (int y = 0; y < map->height; y++)
    {
        for (int x = 0; x < map->width; x++)
        {
            t_point start = project_point(map->array[y][x], camera);
            if (x < map->width - 1)
            {
                t_point end = project_point(map->array[y][x + 1], camera);
                draw_line(gui, start, end);
            }
            if (y < map->height - 1)
            {
                t_point end = project_point(map->array[y + 1][x], camera);
                draw_line(gui, start, end);
            }
        }
    }
    mlx_put_image_to_window(gui->mlx, gui->window, gui->img.ptr, 0, 0);
}
