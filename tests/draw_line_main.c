#include "include/fdf.h"

int main()
{
	t_gui *gui = malloc(sizeof(t_gui));
	gui_init(gui, 1920, 1080);

	t_point	p0;
	p0.x = 1920/2;
	p0.y = 1080/2;
	p0.z = 0;
	t_point	p1;
	p1.x = 0;
	p1.y = 1080/2;
	p1.z = 0;

    draw_line(gui, p0, p1);
	mlx_put_image_to_window(gui->mlx, gui->window, gui->img.ptr, 0, 0);
	gui_loop(gui);
}