/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_map_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 23:45:55 by msabr             #+#    #+#             */
/*   Updated: 2025/02/24 22:04:43 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	walls_valid(char **str_map, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < width)
	{
		if (str_map[0][i] != '1' || str_map[height - 1][i] != '1')
			return (0);
		i++;
	}
	while (j < height)
	{
		if (str_map[j][0] != '1' || str_map[j][width - 1] != '1')
			return (0);
		j++;
	}
	return (1);
}

static int	rectangle_valid(char **str_map, int height)
{
	int	i;
	int	j;
	int	k;

	if (!str_map || height < 1)
		return (0);
	j = 0;
	while (str_map[0][j] && str_map[0][j] != '\n')
		j++;
	i = 1;
	while (i < height)
	{
		k = 0;
		while (str_map[i][k] && str_map[i][k] != '\n')
			k++;
		if (k != j)
			return (0);
		i++;
	}
	return (1);
}

static int	elements_count(char element, int *e_count,
	int *c_count, int *p_count)
{
	if (element == 'E')
		(*e_count)++;
	else if (element == 'C')
		(*c_count)++;
	else if (element == 'P')
		(*p_count)++;
	else if (element != '0' && element != '1'
		&& element != '\n' && element != '\0')
		return (0);
	return (1);
}

static int	elements_valid(char **str_map, int width, int height)
{
	int	y;
	int	x;
	int	e_count;
	int	c_count;
	int	p_count;

	y = 0;
	e_count = 0;
	c_count = 0;
	p_count = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (!elements_count(str_map[y][x], &e_count, &c_count, &p_count))
				return (0);
			x++;
		}
		y++;
	}
	if (e_count != 1 || c_count < 1 || p_count != 1)
		return (0);
	return (1);
}

int	map_is_valid(char **str_map, int width, int height)
{
	if ((!elements_valid(str_map, width, height))
		|| (width < 3) || (height < 3)
		|| (width > 35) || (height > 20)
		|| (!rectangle_valid(str_map, height))
		|| (!walls_valid(str_map, width, height)))
		return (0);
	return (1);
}
