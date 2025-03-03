/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:57:50 by msabr             #+#    #+#             */
/*   Updated: 2025/02/19 13:03:36 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	contains_a_new_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	len_to_newline(char *string)
{
	int	len;

	len = 0;
	if (!string)
		return (0);
	while (string[len] && string[len] != '\n')
		len++;
	if (string[len] == '\n')
		len++;
	return (len);
}

char	*get_line_exact(char **string)
{
	int		len;
	char	*line;

	if (!string || !*string)
		return (NULL);
	len = len_to_newline(*string);
	line = (char *)malloc(len + 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line, *string, len + 1);
	return (line);
}

char	*read_and_join(char **buffer, int fd)
{
	ssize_t		n;
	char		*buf;
	char		*temp;

	while (contains_a_new_line(*buffer) == 0)
	{
		buf = (char *)malloc((size_t)BUFFER_SIZE + 1);
		if (!buf)
			return (free(*buffer), *buffer = NULL, NULL);
		n = read(fd, buf, BUFFER_SIZE);
		if (n < 0)
			return (free(*buffer), *buffer = NULL, free(buf), NULL);
		buf[n] = '\0';
		temp = *buffer;
		*buffer = ft_strjoin(*buffer, buf);
		if (!*buffer)
			return (free(*buffer), *buffer = NULL, free(buf), free(temp), NULL);
		free(temp);
		free(buf);
		if (n == 0)
			break ;
	}
	return (*buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(buffer), buffer = NULL, NULL);
	buffer = read_and_join(&buffer, fd);
	if (!buffer || !*buffer)
		return (free(buffer), buffer = NULL, NULL);
	line = get_line_exact(&buffer);
	if (!line)
		return (free(buffer), buffer = NULL, NULL);
	temp = buffer;
	buffer = ft_strdup(buffer + len_to_newline(buffer));
	free(temp);
	return (line);
}
