/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:18:25 by iubieta-          #+#    #+#             */
/*   Updated: 2024/07/09 19:43:30 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

int	main(int argc, char **argv)
{
	t_gui	*gui;

	if (argc != 2)
	{
		ft_printf("ERROR: Check your arguments");
		return (0);
	}
	gui = malloc(sizeof(t_gui));
	gui_init(gui, 1080, 720);
	gui->map = fdf_load_map(argv[1]);
	gui->camera = cam_init(*gui->map, *gui);
	draw_map(gui, *gui->map, *gui->camera);
	gui_loop(gui);
	free_gui(gui);
}
