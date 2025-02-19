/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 22:00:38 by msabr             #+#    #+#             */
/*   Updated: 2025/02/19 10:36:52 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 75
# endif

# include <stdlib.h>
# include <unistd.h>
# include "../Libft/libft.h"

char	*get_next_line(int fd);
int		contains_a_new_line(char *str_buf);
int		len_to_newline(char *string);
char	*get_line_exact(char **string);
char	*read_and_join(char **buffer, int fd);

#endif
