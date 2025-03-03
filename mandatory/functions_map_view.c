/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_map_view.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 00:11:54 by msabr             #+#    #+#             */
/*   Updated: 2025/02/19 10:47:46 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	show_element(t_game *game, char element, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->background_img, x * SIZE, y * SIZE);
	if (element == '1')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall_img, x * SIZE, y * SIZE);
	}
	else if (element == 'C')
	{
		game->collectibles++;
		mlx_put_image_to_window(game->mlx, game->win,
			game->collectible_img, x * SIZE, y * SIZE);
	}
	else if (element == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->exit_img, x * SIZE, y * SIZE);
	else if (element == 'P')
	{
		game->player_x = x;
		game->player_y = y;
		mlx_put_image_to_window(game->mlx, game->win,
			game->player_img, x * SIZE, y * SIZE);
	}
}

void	show_map(t_game *game, char **str_map, int width, int heigth)
{
	int	x;
	int	y;

	game->collectibles = 0;
	y = 0;
	while (y < heigth)
	{
		x = 0;
		while (x < width)
		{
			show_element(game, str_map[y][x], x, y);
			x++;
		}
		y++;
	}
}
