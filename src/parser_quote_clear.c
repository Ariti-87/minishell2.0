/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_quote_clear.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:53:37 by arincon           #+#    #+#             */
/*   Updated: 2023/10/12 14:17:18 by arincon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Add a string to an array of strings and return the updated array.
char	**ft_add_tab(char **tab, char *str, int ftab, int fstr)
{
	int		i;
	char	**ntab;

	i = 0;
	if (!str || !*str)
		return (NULL);
	ntab = ft_calloc(ft_strlen_tab(tab) + 2, sizeof(char *));
	while (tab && tab[i])
	{
		ntab[i] = ft_strdup(tab[i]);
		i++;
	}
	ntab[i++] = ft_strdup(str);
	ntab[i] = NULL;
	if (str && fstr)
		free(str);
	if (tab && ftab)
		ft_free_tab(tab);
	return (ntab);
}

// Count the number of quotes (single or double) in a string.
int	ft_nb_quotes(char *str)
{
	int		i;
	int		nb;
	char	quote;

	nb = 0;
	i = 0;
	quote = 0;
	while (str && str[i])
	{
		if (ft_belong("'\"", str[i]))
		{
			if (!quote)
			{
				nb++;
				quote = str[i];
			}
			else if (quote && str[i] == quote)
			{
				nb++;
				quote = 0;
			}
		}
		i++;
	}
	return (nb);
}

// Merge cell contents when quotes are not properly matched.
static char	*ft_merge_cell(t_coor *x, int n, char **tab)
{
	char	*sub;

	sub = NULL;
	while (n % 2 != 0 && tab[x->i + x->j])
	{
		if (x->j != 0)
			sub = ft_strjoin_free(sub, " ", 1, 0);
		sub = ft_strjoin_free(sub, tab[x->i + x->j], 1, 0);
		x->j++;
		n = ft_nb_quotes(sub);
	}
	return (sub);
}

// Progress to the next cell while merging contents.
static void	ft_progress(t_coor *x)
{
	if (x->j)
		x->i += x->j;
	else
		x->i++;
}

// Process an array of strings, merging elements with unpaired quotes.
char	**ft_clear_tab(char **tab)
{
	int		n;
	t_coor	x;
	char	**tab_final;
	char	*sub;

	tab_final = NULL;
	sub = NULL;
	x.i = 0;
	while (tab && tab[x.i])
	{
		x.j = 0;
		n = ft_nb_quotes(tab[x.i]);
		if (n && n % 2 != 0)
		{
			sub = ft_merge_cell(&x, n, tab);
			tab_final = ft_add_tab(tab_final, sub, 1, 1);
		}
		else
			tab_final = ft_add_tab(tab_final, tab[x.i], 1, 0);
		ft_progress(&x);
	}
	if (tab)
		ft_free_tab(tab);
	return (tab_final);
}
