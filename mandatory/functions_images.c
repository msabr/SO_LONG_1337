/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_images.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 23:14:38 by msabr             #+#    #+#             */
/*   Updated: 2025/02/27 17:18:21 by msabr            ###   ########.fr       */
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
	load_image(game, &game->wall_img, "./mandatory/textures/img_wall.xpm");
	load_image(game, &game->exit_img, "./mandatory/textures/img_exit.xpm");
	load_image(game, &game->player_img, "./mandatory/textures/img_player.xpm");
	load_image(game, &game->collectible_img,
		"./mandatory/textures/img_collectible.xpm");
	load_image(game, &game->background_img,
		"./mandatory/textures/img_background.xpm");
}
