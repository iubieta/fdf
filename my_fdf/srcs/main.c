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
	ft_printf("Iniciando GUI\n");
	gui_init(gui, 1080, 720);
	ft_printf("Cargando mapa\n");
	gui->map = fdf_load_map(argv[1]);
	ft_printf("Iniciando camara\n");
	gui->camera = cam_init(*gui->map, *gui);
	draw_map(gui, *gui->map, *gui->camera);
	gui_loop(gui);
	free_gui(gui);
}
