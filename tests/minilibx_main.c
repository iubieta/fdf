#include "../minilibx-linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_data {
	void    *img;           // Puntero a la imagen
	char    *addr;          // Dirección de memoria de los datos de la imagen
	int     bits_per_pixel; // Bits por píxel (profundidad de color)
	int     line_length;    // Longitud de cada línea de la imagen en bytes
	int     endian;         // Orden de los bytes (endianess)
}               t_data;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int close_window(void *param)
{
    (void)param; // No usamos este parámetro
    exit(0);     // Terminamos el programa
    return (0);  // No es necesario, pero lo incluimos para completar la firma de la función
}

int main(){
    void *mlx;
    void *window;
    t_data data;

    mlx = mlx_init();
    window = mlx_new_window(mlx, 500, 500, "Venatana 1");
    data.img = mlx_new_image(mlx, 1920, 1080);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length,
								&data.endian);
    my_mlx_pixel_put(&data, 250, 250, 0x00FF0000);
    mlx_put_image_to_window(mlx, window, data.img, 0, 0);
    mlx_hook(window, 17, 0, close_window, NULL);
    mlx_loop(mlx);
}


/*
Compilacion:
gcc -o my_program minilibx_main.c -L../minilibx-linux -lmlx -lXext -lX11 -lm 

*/