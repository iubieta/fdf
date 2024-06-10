/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D_points.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta <iubieta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:05:30 by iubieta           #+#    #+#             */
/*   Updated: 2024/06/10 13:10:08 by iubieta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

t_point *new_point(int x, int y, int z) 
{
    t_point *point;
    point = malloc(sizeof(t_point));
    if (!point) {
        perror("Error al asignar memoria para el punto");
        return NULL;
    }
    point->x = x;
    point->y = y;
    point->z = z;
    point->next = NULL;
    return (point);
}

void add_point(t_map *map, t_point *new_point) 
{
    t_point *current;
    
    if (!map->head) {
        map->head = new_point;
    } else {
        current = map->head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_point;
    }
}

void free_points(t_point *head) 
{
    t_point *current;
    current = head;
    while (current) {
        t_point *next = current->next;
        free(current);
        current = next;
    }
}



void print_2d_matrix(t_map *map) {
    if (!map || !map->head) {
        printf("El mapa está vacío o no es válido.\n");
        return;
    }

    // Crear una matriz 2D para almacenar los valores de z
    int **matrix = malloc(map->rows * sizeof(int *));
    for (int i = 0; i < map->rows; i++) {
        matrix[i] = malloc(map->cols * sizeof(int));
        for (int j = 0; j < map->cols; j++) {
            matrix[i][j] = 0; // Inicializar con un valor por defecto, por ejemplo, 0
        }
    }

    // Rellenar la matriz con los valores de z
    t_point *current = map->head;
    while (current) {
        if (current->x < map->cols && current->y < map->rows) {
            matrix[current->y][current->x] = current->z;
        }
        current = current->next;
    }

    // Imprimir la matriz
    for (int i = 0; i < map->rows; i++) {
        for (int j = 0; j < map->cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Liberar la memoria de la matriz
    for (int i = 0; i < map->rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}
