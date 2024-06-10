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
	free_points(map->head);
	free(map);
}