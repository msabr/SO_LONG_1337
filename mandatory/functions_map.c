/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 22:21:29 by msabr             #+#    #+#             */
/*   Updated: 2025/02/27 17:39:03 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_lines(char *file_name)
{
	int		count;
	char	*line;
	int		fd;

	count = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd ("Error: Failed to open file\n", 2);
		exit (1);
	}
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	return (count);
}

void	prepare_map(char ***str_map, char *file_name, int *width, int *height)
{
	char	*line;
	int		fd;

	*height = 0;
	*width = 0;
	*str_map = (char **)malloc(sizeof(char *) * count_lines(file_name));
	if (!*str_map)
	{
		ft_putstr_fd ("Memory allocation failed.\n", 2);
		exit (1);
	}
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		(*str_map)[(*height)++] = line;
		if (*height == 1)
		{
			*width = ft_strlen(line);
			if (line[*width -1] == '\n')
				(*width)--;
		}
		line = get_next_line(fd);
	}
	close (fd);
}
