/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta <iubieta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 21:42:27 by iubieta           #+#    #+#             */
/*   Updated: 2024/06/18 21:42:51 by iubieta          ###   ########.fr       */
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