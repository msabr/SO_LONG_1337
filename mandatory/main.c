/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 22:03:23 by msabr             #+#    #+#             */
/*   Updated: 2025/02/19 10:50:49 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**str_map;
	int		width;
	int		height;
	t_game	*game;

	height = 0;
	if (argc != 2)
	{
		ft_putstr_fd ("Error: Try use : ./so_long <map.ber>\n", 2);
		return (1);
	}
	check_file_extension(argv[1]);
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
	{
		ft_putstr_fd ("Error: Memory allocation failed\n", 2);
		return (1);
	}
	prepare_map(&str_map, argv[1], &width, &height);
	game->mlx = mlx_init();
	prepare_imgs(game);
	if (!initialize_window(game, str_map, width, height))
		return (1);
	start_game(game, str_map, width, height);
	return (0);
}
