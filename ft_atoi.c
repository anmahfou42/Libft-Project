/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmahfou <anmahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:14:17 by anmahfou          #+#    #+#             */
/*   Updated: 2024/11/06 16:16:09 by anmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	ft_signft(const char *str, int *index)
{
	int	sign;

	sign = 1;
	if (str[*index] == '-' || str[*index] == '+')
	{
		if (str[*index] == '-')
			sign = -1;
		(*index)++;
	}
	return (sign);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long	result;

	result = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	sign = ft_signft(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((result > 9223372036854775807 / 10)
			|| (result == 9223372036854775807 / 10 && (str[i]
					- '0') > 9223372036854775807 % 10))
			return (-(sign == 1));
		result = result * 10 + (str[i++] - '0');
	}
	return (sign * result);
}
