/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_keypress.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 00:08:38 by msabr             #+#    #+#             */
/*   Updated: 2025/03/02 14:01:58 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	validate_move(t_game *game, int new_x, int new_y, int steps)
{
	char	next_tile;

	next_tile = game->map[new_y][new_x];
	if (next_tile == 'E' && game->collectibles == 0)
	{
		steps++;
		ft_putstr_fd("step: ", 1);
		ft_putnbr_fd(steps, 1);
		ft_putchar_fd('\n', 1);
		exit_game(game);
	}
	if (next_tile == '1' || (next_tile == 'E' && game->collectibles > 0))
		return (0);
	if (next_tile == 'C')
	{
		game->collectibles--;
		game->map[new_y][new_x] = '0';
	}
	return (1);
}

static void	move_player(t_game *game, int dx, int dy)
{
	static int	steps;
	int			new_x;
	int			new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (!validate_move(game, new_x, new_y, steps))
		return ;
	mlx_put_image_to_window(game->mlx, game->win, game->background_img,
		game->player_x * SIZE, game->player_y * SIZE);
	mlx_put_image_to_window(game->mlx, game->win,
		game->player_img, new_x * SIZE, new_y * SIZE);
	game->player_x = new_x;
	game->player_y = new_y;
	steps++;
	ft_putstr_fd("step: ", 1);
	ft_putnbr_fd(steps, 1);
	ft_putchar_fd('\n', 1);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 126)
		move_player(game, 0, -1);
	else if (keycode == 125)
		move_player(game, 0, 1);
	else if (keycode == 123)
		move_player(game, -1, 0);
	else if (keycode == 124)
		move_player(game, 1, 0);
	else if (keycode == 53)
		exit_game(game);
	return (0);
}
