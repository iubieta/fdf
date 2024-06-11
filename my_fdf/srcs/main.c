#include "include/fdf.h"

int main()
{
	t_map *map = malloc(sizeof(t_map));
	map->head = NULL;
	
	int fd = open("basictest.fdf", O_RDONLY);
	    if (fd == -1) {
        perror("Error al abrir el archivo");
        return 1;
    }else{
		char *line = get_next_line(fd);
		while (line)
		{
			printf("%s",line);
			line = get_next_line(fd);
		}
	}
	printf("\n");
	close(fd);

	fd = open("basictest.fdf", O_RDONLY);
	if (fd == -1) {
	perror("Error al abrir el archivo");
	return 1;
    }else{
		read_fdf(fd, map);
	}
	printf("\n");
	close(fd);
	
	print_2d_matrix(map);

	map_rotation(map, rot_x, 90);
	print_2d_matrix(map);

	void *mlx;
    void *window;
    t_data data;

    mlx = mlx_init();
    window = mlx_new_window(mlx, 500, 500, "Ventana 1");
	mlx_hook(window, 17, 0, close_window, NULL);
    data.img = mlx_new_image(mlx, 1920, 1080);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length,
								&data.endian);
    
	t_point *current = map->head;
	while (current) {
        if (current->x < map->cols && current->y < map->rows) {
            if (current->z != 0)
				my_mlx_pixel_put(&data, current->x *40 + 10 , current->y * 40 + 10, 0x0000FF00);
			else
				my_mlx_pixel_put(&data, current->x *40 + 10, current->y * 40 + 10, 0x000000FF);
        }
        current = current->next;
    }
	mlx_put_image_to_window(mlx, window, data.img, 0, 0);
	
	sleep(3);

	window = mlx_new_window(mlx, 500, 500, "Ventana 2");
	mlx_hook(window, 17, 0, close_window, NULL);
	data.img = mlx_new_image(mlx, 1920, 1080);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length,
								&data.endian);
	
	map_rotation(map, rot_x, 90);
	current = map->head;
	while (current) {
        if (current->x < map->cols && current->y < map->rows) {
            if (current->z != 0)
				my_mlx_pixel_put(&data, current->x *40 + 10 , current->y * 40 + 10, 0x0000FF00);
			else
				my_mlx_pixel_put(&data, current->x *40 + 10, current->y * 40 + 10, 0x000000FF);
        }
        current = current->next;
    }
    mlx_put_image_to_window(mlx, window, data.img, 0, 0);
    
	mlx_loop(mlx);

	free_points(map->head);
	free(map);
}