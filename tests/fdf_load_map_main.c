#include "include/fdf.h"

int main()
{
	t_map	*map;
	int		y = 0;
	int		x = 0;
	int 	color;


	map = fdf_load_map("basictest.fdf");
	print_z_values(map);

	t_gui *gui = malloc(sizeof(t_gui));
	gui_init(gui, 1920, 1080);
    while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->array[y][x].z == 0)
				color = 0x00FF0000;
			else
				color = 0x00FFFFFF;
			draw_point(gui, map->array[y][x], color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(gui->mlx, gui->window, gui->img.ptr, 0, 0);
	gui_loop(gui);
}