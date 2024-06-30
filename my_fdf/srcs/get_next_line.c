/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta <iubieta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:30:09 by iubieta-          #+#    #+#             */
/*   Updated: 2024/06/30 20:09:28 by iubieta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/get_next_line.h"

char	*ft_join_gnl(char *s1, char *s2)
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

char	*ft_read(int fd, char *text)
{
	int		read_bytes;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	read_bytes = BUFFER_SIZE;
	while (!(ft_strchr(text, '\n')) && read_bytes == BUFFER_SIZE)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[read_bytes] = '\0';
		if (read_bytes >= 0)
			text = ft_join_gnl(text, buffer);
		else
			return (free (buffer), buffer = NULL, NULL);
	}
	free (buffer);
	buffer = NULL;
	return (text);
}

int	ft_linelen(const char *text)
{
	size_t	count;

	count = 0;
	if (!text)
		return (0);
	while (text[count] != '\0' && text[count] != '\n')
		count++;
	if (text[count] == '\n')
		count++;
	return (count);
}

char	*ft_errorscheck(int fd, char *text)
{
	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		if (text)
		{
			free(text);
			text = NULL;
		}
		return (0);
	}
	if (!text)
	{
		text = malloc(sizeof(char));
		if (!text)
			return (0);
		text[0] = '\0';
	}
	return (text);
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*del;
	char		*line;
	int			line_len;

	text = ft_errorscheck(fd, text);
	if (text == 0)
		return (NULL);
	text = ft_read(fd, text);
	if (text[0] == '\0')
		return (free(text), text = NULL, NULL);
	line_len = ft_linelen(text);
	line = ft_substr(text, 0, line_len);
	if (!line)
		return (free(line), line = NULL, NULL);
	del = text;
	text = ft_substr(text, line_len, ft_strlen(text) - line_len);
	if (!text)
		return (free(text), text = NULL, NULL);
	free(del);
	del = NULL;
	return (line);
}
