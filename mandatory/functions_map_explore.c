/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_map_explore.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:47:25 by msabr             #+#    #+#             */
/*   Updated: 2025/02/19 10:47:28 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**copy_map(char **map_original, int height, int width)
{
	char	**map_copy;
	int		i;

	map_copy = (char **)malloc(height * sizeof(char *));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		map_copy[i] = (char *)malloc((width + 1) * sizeof(char));
		if (!map_copy[i])
			return (free(map_copy[i]), free(map_copy), NULL);
		ft_strlcpy(map_copy[i], map_original[i], width);
		map_copy[i][width] = '\0';
		i++;
	}
	return (map_copy);
}

static void	explore_map(t_map *info, char **str_map, int x, int y)
{
	if (x < 0 || x >= info->map_width || y < 0 || y >= info->map_height)
		return ;
	if (str_map[y][x] == '1' || str_map[y][x] == 'V')
		return ;
	if (str_map[y][x] == 'C')
	{
		info->collectibles--;
		if (info->collectibles == 0)
			info->can_collect = 1;
	}
	if (str_map[y][x] == 'E')
	{
		info->can_move = 1;
		return ;
	}
	str_map[y][x] = 'V';
	explore_map(info, str_map, x + 1, y);
	explore_map(info, str_map, x - 1, y);
	explore_map(info, str_map, x, y + 1);
	explore_map(info, str_map, x, y - 1);
}

int	move_valid(t_game *game)
{
	int		i;
	int		x;
	int		y;
	t_map	info;
	char	**str_map_copy;

	i = 0;
	x = game->player_x;
	y = game->player_y;
	str_map_copy = copy_map(game->map, game->map_height, game->map_width);
	if (!str_map_copy)
		exit_game(game);
	info.map_width = game->map_width;
	info.map_height = game->map_height;
	info.collectibles = game->collectibles;
	info.can_move = 0;
	info.can_collect = 0;
	explore_map(&info, str_map_copy, x, y);
	while (i < game->map_height)
	{
		free(str_map_copy[i]);
		i++;
	}
	free(str_map_copy);
	return (info.can_collect && info.can_move);
}
