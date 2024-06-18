#include "include/fdf.h"

int main()
{
	//t_map *map = malloc(sizeof(t_map));
	//map->head = NULL;

	//fdf_read("basictest.fdf", map);
	//print_2d_matrix(map);
	printf("\n");

	t_gui *gui = malloc(sizeof(t_gui));
	gui_init(gui, 500, 500);

	t_point	p0;
	p0.x = 500/2;
	p0.y = 500/2;
	p0.z = 0;
	t_point	p1;
	p1.x = 25;
	p1.y = 233;
	p1.z = 0;

    draw_line(gui, p0, p1);
	mlx_put_image_to_window(gui->mlx, gui->window, gui->img.ptr, 0, 0);
	gui_loop(gui);
	
	//free_points(map->head);
	//free(map);
}