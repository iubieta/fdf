# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>

# include "get_next_line.h"
# include "../../libs/libft/libft.h"
# include "../../libs/minilibx-linux/mlx.h"
# include "../../libs/printf/ft_printf.h"

typedef struct s_point {
    int x;
    int y;
    int z;
    struct s_point *next;
} t_point;

typedef struct s_map {
    t_point *head;
    int rows;
    int cols;
} t_map;

t_point *new_point(int x, int y, int z);
void    add_point(t_map *map, t_point *new_point);
void    free_points(t_point *head);
void    print_2d_matrix(t_map *map);

t_point rot_x(t_point p, float angle);
t_point rot_y(t_point p, float angle);
t_point rot_z(t_point p, float angle);
void   map_rotation(t_map *map, t_point (*func)(t_point, float), float angle);
t_point isometric_rot(t_point);
t_point point_projection(t_point point_3d, float fov, float distance);

void    read_fdf(int fd, t_map *map);
char    *next_word(char *str);

typedef struct s_data {
	void    *img;
	char    *addr;
	int     bits_per_pixel;
	int     line_length;
	int     endian;
}               t_data;

void    my_mlx_pixel_put(t_data *data, int x, int y, int color);
int     close_window(void *param);

