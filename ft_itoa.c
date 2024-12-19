/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmahfou <anmahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:16:04 by anmahfou          #+#    #+#             */
/*   Updated: 2024/11/16 12:17:17 by anmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int nb)
{
	long	n;
	int		count;

	n = nb;
	if (n <= 0)
	{
		count = 1;
	}
	else
		count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*ft_malloc(int len)
{
	char	*str;

	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_itoa(int nb)
{
	long	n;
	char	*str;

	n = nb;
	nb = count_digits(n);
	str = ft_malloc(nb);
	if (!str)
		return (NULL);
	str[nb] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	else if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (n > 0)
	{
		str[--nb] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
