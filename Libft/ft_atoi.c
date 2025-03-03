/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:54:04 by msabr             #+#    #+#             */
/*   Updated: 2025/03/03 15:30:00 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_overflow(int signe)
{
	if (signe == 1)
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int			sign;
	int			i;
	long long	nbr;

	nbr = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || ('\t' <= str[i] && str[i] <= '\r'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		if ((nbr > (9223372036854775807 / 10))
			|| (nbr >= (9223372036854775807 / 10) && ((str[i] - '0') > 7)))
			return (check_overflow(sign));
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(nbr * sign));
}
