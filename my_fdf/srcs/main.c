#include "include/fdf.h"

int main()
{
	t_map *map = malloc(sizeof(t_map));
	map->head = NULL;

	fdf_read("basictest.fdf", map);
	//print_2d_matrix(map);
	printf("\n");

	t_gui *gui = malloc(sizeof(t_gui));
	gui_init(gui);
	gui_loop(gui);

/* 	t_point	p0;
	p0.x = 100;
	p0.y = 100;
	p0.z = 0;
	//draw_2d_point(gui, p0); */
	my_mlx_pixel_put(&gui->img, 100, 100, 0x00FFFFFF);
	mlx_put_image_to_window(gui->mlx, gui->window, gui->img.img, 0, 0);
	
	free_points(map->head);
	free(map);
}