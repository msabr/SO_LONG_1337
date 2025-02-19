/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_parssing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 22:11:56 by msabr             #+#    #+#             */
/*   Updated: 2025/02/19 10:48:03 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_file_extension(char *file_name)
{
	int	i;

	i = 0;
	while (file_name[i])
		i++;
	if (i < 4 || file_name[i - 1] != 'r' || file_name[i - 2] != 'e'
		|| file_name[i - 3] != 'b' || file_name[i - 4] != '.')
	{
		ft_putstr_fd("Error: try file_name end with -> .ber\n", 2);
		exit(0);
	}
}
