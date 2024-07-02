/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 18:21:14 by iubieta           #+#    #+#             */
/*   Updated: 2024/07/02 20:00:24 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void	free_map(t_map *map)
{
	int	y;

	y = -1;
	if (!map || !map->array)
		return ;
	while (++y < map->height)
	{
		if (map->array[y])
		{
			free(map->array[y]);
			map->array[y] = NULL;
		}
	}
	free(map->array);
	map->array = NULL;
	free(map);
	map = NULL;
}

void	free_img(void *mlx, t_img img)
{
	if (img.ptr)
	{
		mlx_destroy_image(mlx, img.ptr);
		img.ptr = NULL;
	}
	if (img.addr)
	{
		img.addr = NULL;
	}
}

void	free_mlx_group(t_gui *gui)
{
	if (gui->img.ptr)
	{
		free_img(gui->mlx, gui->img);
	}
	if (gui->window)
	{
		mlx_destroy_window(gui->mlx, gui->window);
		gui->window = NULL;
	}
	if (gui->mlx)
	{
		mlx_destroy_display(gui->mlx);
		free(gui->mlx);
		gui->mlx = NULL;
	}
}

void	free_gui(t_gui *gui)
{
	if (!gui)
		return ;
	if (gui->map)
	{
		free_map(gui->map);
	}
	if (gui->camera)
	{
		free (gui->camera);
		gui->camera = NULL;
	}
	free_mlx_group(gui);
	free(gui);
	gui = NULL;
}
