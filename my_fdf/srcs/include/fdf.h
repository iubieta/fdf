# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>

# include "get_next_line.h"
# include "../../libs/libft/libft.h"
# include "../../libs/minilibx/mlx.h"
# include "../../libs/printf/ft_printf.h"

typedef struct  s_point {
    int x;
    int y;
    int z;
    struct s_point *next;
}               t_point;

typedef struct  s_map {
    t_point *head;
    int rows;
    int cols;
}               t_map;

typedef struct  s_img {
	void    *img;           // Puntero a la imagen
	char    *addr;          // Dirección de memoria de los datos de la imagen
	int     bits_per_pixel; // Bits por píxel (profundidad de color)
	int     line_length;    // Longitud de cada línea de la imagen en bytes
	int     endian;         // Orden de los bytes (endianess)
}               t_img;

typedef struct  s_gui {
    void        *mlx;
    void        *window;
	int			width;
	int			height;
    t_img       img;
}               t_gui;

t_point *new_point(int x, int y, int z);
void    add_point(t_map *map, t_point *new_point);
void    free_points(t_point *head);
void    print_2d_matrix(t_map *map);

t_point rot_x(t_point p, float angle);
t_point rot_y(t_point p, float angle);
t_point rot_z(t_point p, float angle);
void   map_rotation(t_map *map, t_point (*func)(t_point, float), float angle);
void    map_translation(t_map *map, char axis, float distance);
t_point isometric_rot(t_point);
t_point point_projection(t_point point_3d, float fov, float distance);

int     fdf_read(char *file, t_map *map);
void    fdf_save_data(int fd, t_map *map);
char    *next_word(char *str);

void    my_mlx_pixel_put(t_img *data, int x, int y, int color);
int     close_window(void *param);
void gui_init(t_gui *gui);
void gui_loop(t_gui *gui);

void draw_2d_point(t_gui *gui, t_point point);