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

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

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

typedef struct  s_cam {
	double	zoom;
	double	x_angle;
	double	y_angle;
	double	z_angle;
	double	z_height;
	double	x_rot;
	double	z_rot;
	int 	x_offset;
	int 	y_offset;
	int 	iso;
}               t_cam;


typedef struct  s_gui {
	void        *mlx;
	int			width;
	int			height;
	void        *window;
	t_img       img;
	t_cam       *camera;
}               t_gui;

char	*next_word(char* str);
int	    ft_abs(int x);
int	    ft_sign(int x);
double	ft_rad(float degrees);

void    gui_init(t_gui *gui, int width, int height);
void    gui_loop(t_gui *gui);
int     close_window(void *param);

t_point *new_point(int x, int y, int z);
//int     out_of_screen(t_gui gui, t_point point);
t_map   *new_map(int width, int height);

t_map	*fdf_load_map(char *file);

void    add_point(t_map *map, t_point *new_point);
void    free_points(t_point *head);
void    print_2d_matrix(t_map *map);

t_cam	*cam_init(t_map map, t_gui gui);
void	cam_iso(t_cam *camera);
void	cam_home(t_cam *camera, t_map map, t_gui gui);
t_point project_point(t_point point, t_cam camera);

void	draw_point(t_gui *gui, t_point p, int color);
void	draw_line(t_gui *gui, t_point p0, t_point p1);
void    draw_map(t_gui *gui, t_map map, t_cam camera);

//DEBUG
void print_z_values(t_map *map);
