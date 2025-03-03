/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:21:35 by msabr             #+#    #+#             */
/*   Updated: 2025/03/02 13:57:24 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	initialize_window(t_game *game, char **str_map, int width, int height)
{
	game->win = mlx_new_window(game->mlx, width * SIZE,
			height * SIZE, "so_long");
	if (!game->mlx || !game->win)
	{
		ft_putstr_fd(
			"Error: Failed to initialize MiniLibX or create window\n", 2);
		exit_game(game);
		return (0);
	}
	if (!map_is_valid(str_map, width, height))
	{
		ft_putstr_fd("Error: Invalid map configuration\n", 2);
		exit_game(game);
		return (0);
	}
	return (1);
}
