/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:43:45 by iubieta-          #+#    #+#             */
/*   Updated: 2024/02/10 14:53:58 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	char		ch;
	char		*ptr;

	ch = (char)c;
	ptr = (char *)s;
	if (s == NULL)
		return (ptr);
	while (*ptr != ch && *ptr != '\0')
		ptr++;
	if (*ptr == ch || ch == '\0')
		return (ptr);
	else
		return (0);
}

char	*ft_join(char *s1, char *s2)
{
	char	*final_str;
	int		i;
	int		j;

	final_str = NULL;
	if (!s1 && !s2)
		return (NULL);
	else if (s1 && s2)
	{
		final_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (!final_str)
			return (NULL);
		i = 0;
		while (s1 && s1[i])
		{
			final_str[i] = s1[i];
			i++;
		}
		final_str[i] = '\0';
		j = 0;
		while (s2 && s2[j] != '\0')
			final_str[i++] = s2[j++];
		final_str[i] = '\0';
	}
	return (free(s1), s1 = NULL, final_str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (0);
	i = 0;
	while (s[start + i] && i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
