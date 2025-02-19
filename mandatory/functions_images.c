/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_images.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 23:14:38 by msabr             #+#    #+#             */
/*   Updated: 2025/02/19 10:56:52 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_image(t_game *game, void **image, char *path)
{
	int	width;
	int	heitgh;

	*image = mlx_xpm_file_to_image(game->mlx, path, &width, &heitgh);
	if (!*image)
	{
		ft_putstr_fd("Error: Failed to load images\n", 2);
		exit_game(game);
	}
}

void	prepare_imgs(t_game *game)
{
	game->exit_img = NULL;
	game->collectible_img = NULL;
	game->player_img = NULL;
	game->background_img = NULL;
	game->wall_img = NULL;
	game->win = NULL;
	load_image(game, &game->wall_img, "./mandatory/images/img_wall_1.xpm");
	load_image(game, &game->exit_img, "./mandatory/images/img_exit_6.xpm");
	load_image(game, &game->player_img, "./mandatory/images/img_player.xpm");
	load_image(game, &game->collectible_img,
		"./mandatory/images/img_collectible_1.xpm");
	load_image(game, &game->background_img,
		"./mandatory/images/img_background_1.xpm");
}
