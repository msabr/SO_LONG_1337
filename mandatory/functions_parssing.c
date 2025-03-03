/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_parssing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 22:11:56 by msabr             #+#    #+#             */
/*   Updated: 2025/02/24 20:24:12 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_file_extension(char *file_name)
{
	int	len;

	len = ft_strlen(file_name);
	if (len < 4 || file_name[len - 1] != 'r' || file_name[len - 2] != 'e'
		|| file_name[len - 3] != 'b' || file_name[len - 4] != '.')
	{
		ft_putstr_fd("Error: try file_name end with -> .ber\n", 2);
		exit(0);
	}
}
