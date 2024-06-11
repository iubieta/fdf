/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta <iubieta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:33:19 by iubieta           #+#    #+#             */
/*   Updated: 2024/06/11 17:00:41 by iubieta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"


int	fdf_read(char *file, t_map *map)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd == -1) {
		perror("Error al abrir el archivo");
		return (1);
    }else{
		fdf_save_data(fd, map);
	}
	close(fd);
	return (0);
}

void	fdf_save_data(int fd, t_map *map)
{
	t_point     *point;    
	int         x;
	int         y;
	int         z;
	char        *str_point;

	x = 0;
	y = 0;
	str_point = get_next_line(fd);
	while (str_point != NULL)
	{
		while (str_point != NULL)
		{
			z = ft_atoi(str_point);
			point = new_point(x++, y, z);
			add_point(map, point);
			str_point = next_word(str_point);
		}
		map->cols = x;
		y++;
		x = 0;
		str_point = get_next_line(fd);
	}
	map->rows = y;
}

char	*next_word(char* str) 
{
	if (str == NULL)
	{
		return (NULL);
	}
    while (*str != ' ' && *str != '\0')
	{
        str++;
    }
	while (*str == ' ')
	{
		str++;
	}
	if (*str == '\0')
	{
        return (NULL);
    }
    return (str);
}
