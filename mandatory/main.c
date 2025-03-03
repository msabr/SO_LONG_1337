/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 22:03:23 by msabr             #+#    #+#             */
/*   Updated: 2025/02/27 17:53:47 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**str_map;
	int		width;
	int		height;
	t_game	*game;

	if (argc == 2)
	{
		check_file_extension(argv[1]);
		game = (t_game *)malloc(sizeof(t_game));
		if (!game)
			return (ft_putstr_fd ("Error: Memory allocation failed\n", 2), 1);
		ft_memset(game, 0, sizeof(t_game));
		prepare_map(&str_map, argv[1], &width, &height);
		if (width < 3 || height < 3 || width > 35 || height > 20)
			return (ft_putstr_fd("Error:Invalid map\n", 2), exit_game(game), 1);
		game->mlx = mlx_init();
		if (!game->mlx)
			return (ft_putstr_fd ("Error: MiniLibX\n", 2), exit_game(game), 1);
		prepare_imgs(game);
		if (!initialize_window(game, str_map, width, height))
			return (1);
		return (start_game(game, str_map, width, height), 0);
	}
	else
		return (ft_putstr_fd ("Error: Try use : ./so_long <map.ber>\n", 2), 1);
}
