/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta <iubieta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:01:29 by iubieta-          #+#    #+#             */
/*   Updated: 2024/06/30 20:12:13 by iubieta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = malloc(num * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < num * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

/* int main()
{
	return (0);
} */