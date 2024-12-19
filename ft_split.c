/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmahfou <anmahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:48:14 by anmahfou          #+#    #+#             */
/*   Updated: 2024/11/16 13:47:00 by anmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **strf)
{
	size_t	i;

	i = 0;
	while (strf[i])
	{
		free(strf[i]);
		i++;
	}
	free(strf);
	return (NULL);
}

static size_t	ft_count_words(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static void	ft_next_word(char **next_word, size_t *next_word_len, char c)
{
	size_t	i;

	*next_word += *next_word_len;
	*next_word_len = 0;
	i = 0;
	while (**next_word && **next_word == c)
		(*next_word)++;
	while ((*next_word)[i])
	{
		if ((*next_word)[i] == c)
			return ;
		(*next_word_len)++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**strf;
	char	*next_word;
	size_t	next_word_len;
	size_t	i;

	if (!s)
		return (NULL);
	strf = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!strf)
		return (NULL);
	i = 0;
	next_word = (char *)s;
	next_word_len = 0;
	while (i < ft_count_words(s, c))
	{
		ft_next_word(&next_word, &next_word_len, c);
		strf[i] = (char *)malloc(sizeof(char) * (next_word_len + 1));
		if (!strf[i])
			return (ft_free(strf));
		ft_strlcpy(strf[i], next_word, next_word_len + 1);
		i++;
	}
	strf[i] = NULL;
	return (strf);
}
