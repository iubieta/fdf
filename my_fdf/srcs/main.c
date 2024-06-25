#include "include/fdf.h"

int main()
{
	t_map	*map = fdf_load_map("42.fdf");
	print_z_values(map);

	t_gui *gui = malloc(sizeof(t_gui));
	gui_init(gui, 1920, 1080);
		
	t_cam *cam = cam_init(*map, *gui);
	gui->camera = cam;
	gui->map = map;
	draw_map(gui, *map, *cam);
	gui_loop(gui);
	
}