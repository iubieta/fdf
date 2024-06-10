# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
#include <math.h>

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
t_point isometric_rot(t_point);


void    read_fdf(int fd, t_map *map);
char    *next_word(char *str);