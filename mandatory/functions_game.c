/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 23:24:04 by msabr             #+#    #+#             */
/*   Updated: 2025/02/27 17:50:22 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_images(t_game *game)
{
	if (game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->collectible_img)
		mlx_destroy_image(game->mlx, game->collectible_img);
	if (game->player_img)
		mlx_destroy_image(game->mlx, game->player_img);
	if (game->exit_img)
		mlx_destroy_image(game->mlx, game->exit_img);
	if (game->background_img)
		mlx_destroy_image(game->mlx, game->background_img);
}

void	exit_game(t_game *game)
{
	int	i;

	if (game)
	{
		if (game->mlx && game->win)
			mlx_destroy_window(game->mlx, game->win);
		destroy_images(game);
		if (game->map)
		{
			i = 0;
			while (i < game->map_height)
				free(game->map[i++]);
			free(game->map);
		}
		free(game->mlx);
	}
	free(game);
	exit(1);
}

void	start_game(t_game *game, char **map, int width, int height)
{
	game->map = map;
	game->map_width = width;
	game->map_height = height;
	show_map(game, map, width, height);
	if (!move_valid(game))
	{
		ft_putstr_fd ("Error: invalid path\n", 2);
		exit_game(game);
	}
	mlx_hook(game->win, 2, 0, handle_keypress, game);
	mlx_hook(game->win, 17, 0, (int (*)(void *))exit_game, game);
	mlx_loop(game->mlx);
}
