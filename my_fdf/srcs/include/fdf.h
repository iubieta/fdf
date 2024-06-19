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
    int color;
}               t_point;

typedef struct  s_map {
    t_point **array;
    int     width;
    int     height;
}               t_map;

typedef struct  s_img {
	void    *ptr;           // Puntero a la imagen
	char    *addr;          // Dirección de memoria de los datos de la imagen
	int     bpp; // Bits por píxel (profundidad de color)
	int     line_len;    // Longitud de cada línea de la imagen en bytes
	int     endian;         // Orden de los bytes (endianess)
}               t_img;

typedef struct  s_gui {
    void        *mlx;
    int			width;
	int			height;
    void        *window;
    t_img       img;
}               t_gui;

void    gui_init(t_gui *gui, int width, int height);
void    gui_loop(t_gui *gui);
int     close_window(void *param);

void	draw_point(t_gui *gui, t_point p, int color);
void	draw_line(t_gui *gui, t_point p0, t_point p1);

t_point *new_point(int x, int y, int z);
t_map   *new_map(int width, int height);

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

t_map	*fdf_load_map(char *file);

char	*next_word(char* str);

//DEBUG
void print_z_values(t_map *map);
