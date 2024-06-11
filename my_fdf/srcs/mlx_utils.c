/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta <iubieta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 09:58:39 by iubieta           #+#    #+#             */
/*   Updated: 2024/06/11 10:04:58 by iubieta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int close_window(void *param)
{
    (void)param;
    exit(0);
    return (0);
}