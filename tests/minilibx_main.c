#include "../minilibx-linux/mlx.h"

int main(){
    void *mlx;
    //void *mlx_win;

    mlx = mlx_init();
    mlx_new_window(mlx, 100, 100, "Venatana 1");
    mlx_loop(mlx);
}

//gcc -L ../minilibx-linux -lmlx -lX11 -lXext -lm
