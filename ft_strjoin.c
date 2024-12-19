/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmahfou <anmahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:45:46 by anmahfou          #+#    #+#             */
/*   Updated: 2024/11/16 13:47:15 by anmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*helper(char *conca, char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	while (i < len_s1)
	{
		conca[i] = s1[i];
		i++;
	}
	while (j < len_s2)
	{
		conca[i] = s2[j];
		i++;
		j++;
	}
	conca[i] = '\0';
	return (conca);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*conca;
	char	*tmp;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
	{
		tmp = ft_strdup(s2);
		return (tmp);
	}
	if (s2 == NULL)
	{
		tmp = ft_strdup(s1);
		return (tmp);
	}
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	conca = malloc(len_s1 + len_s2 + 1);
	if (!conca)
		return (NULL);
	helper(conca, s1, s2);
	return (conca);
}
