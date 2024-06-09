# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

# include "get_next_line.h"
# include "../../libs/libft/libft.h"
# include "../../libs/minilibx-linux/mlx.h"
# include "../../libs/printf/ft_printf.h"

typedef struct  s_3Dmap {
    int x;
    int y;
    int z;
}               t_3Dmap;