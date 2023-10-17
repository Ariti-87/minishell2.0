/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:07:33 by arincon           #+#    #+#             */
/*   Updated: 2023/02/13 15:10:24 by arincon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_word(char const *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static size_t	ft_len_word(char const *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i] != c && s[i])
	{
		i++;
		len++;
	}
	return (len);
}

static void	*ft_free_alloc(char **split, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static char	*ft_word_alloc(char const *s, char c)
{
	char	*tab;
	size_t	i;
	size_t	j;
	size_t	len_word;

	len_word = ft_len_word(s, c);
	tab = malloc(sizeof(*tab) * (len_word + 1));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != c && s[i])
	{
		tab[j] = s[i];
		i++;
		j++;
	}
	tab[j] = 0;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;

	tab = malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == (char)c && s[i])
			i++;
		if (s[i] != (char)c && s[i])
		{
			tab[j] = ft_word_alloc(&s[i], c);
			if (!tab[j])
				return (ft_free_alloc(tab, j));
			j++;
		}
		while (s[i] != (char)c && s[i])
			i++;
	}
	tab[j] = 0;
	return (tab);
}
