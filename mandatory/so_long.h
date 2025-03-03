/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:49:00 by msabr             #+#    #+#             */
/*   Updated: 2025/02/27 16:42:51 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"

# define SIZE 75

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		can_move;
	int		can_collect;
	void	*wall_img;
	void	*collectible_img;
	void	*player_img;
	void	*exit_img;
	void	*background_img;
}	t_game;

typedef struct s_map
{
	int	map_width;
	int	map_height;
	int	collectibles;
	int	can_move;
	int	can_collect;
}	t_map;

int		main(int ac, char **av);
void	check_file_extension(char *file_name);
void	prepare_map(char ***str_map, char *file_name, int *width, int *height);
void	prepare_imgs(t_game *game);
int		initialize_window(t_game *game, char **str_map, int width, int height);
int		map_is_valid(char **str_map, int width, int height);
void	start_game(t_game *game, char **map, int width, int height);
void	show_map(t_game *game, char **str_map, int width, int heigth);
int		move_valid(t_game *game);
int		handle_keypress(int keycode, t_game *game);
void	exit_game(t_game *game);

#endif
