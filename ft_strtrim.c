/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmahfou <anmahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:45:11 by anmahfou          #+#    #+#             */
/*   Updated: 2024/11/05 20:12:44 by anmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_allocate_str(size_t size)
{
	char	*str;

	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len_s1;
	char	*str;
	size_t	len_str;

	if (!s1 || !set)
		return (NULL);
	len_s1 = ft_strlen(s1);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = len_s1;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	len_str = end - start;
	str = ft_allocate_str(len_str);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + start, len_str + 1);
	return (str);
}
