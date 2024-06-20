/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 21:42:27 by iubieta           #+#    #+#             */
/*   Updated: 2024/06/20 19:28:45 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

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

int	ft_abs(int x)
{
	if (x == 0)
		return (0);
	if (x < 0)
		return (-x);
	return (x);
}

int	ft_sign(int x)
{
	if (x == 0)
		return (0);
	if (x < 0)
		return (-1);
	return (1);
}

double	ft_rad(float degrees)
{
	double	rad;

	rad = degrees * 3.14159 / 180;
	return (rad);
}