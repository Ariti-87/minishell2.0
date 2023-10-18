/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:03:34 by arincon           #+#    #+#             */
/*   Updated: 2023/10/18 17:13:39 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* // Check if there are single or double quotes inside the input string.
int	ft_quote_inside(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (ft_belong("'\"", str[i]))
			return (1);
		i++;
	}
	return (0);
}

// Remove quotes from the input string and return the modified string.
char	*ft_remove_quotes(char *str)
{
	int		i;
	char	quote;
	char	*final;

	i = 0;
	final = NULL;
	quote = 0;
	while (str && str[i])
	{
		if (!quote && ft_belong("'\"", str[i]))
			quote = str[i];
		else if (quote && quote == str[i])
			quote = 0;
		if (!ft_skip_quotes(&quote, &i, str))
		{
			final = ft_add_char(final, str[i]);
			i++;
		}
	}
	if (str)
		free(str);
	return (final);
}

// Merge individual strings within an array of strings, considering quotes.
char	*ft_merge_quotes(t_data *data, char **tab)
{
	int		n;
	int		i;
	char	*str;
	char	**final_tab;

	str = NULL;
	i = 0;
	n = 0;
	final_tab = ft_clear_tab(tab);
	ft_modif_var_env(data, final_tab);
	while (final_tab && final_tab[i])
	{
		n = ft_nb_quotes(final_tab[i]);
		if (n)
			final_tab[i] = ft_clear_word(final_tab[i]);
		str = ft_strjoin_free(str, final_tab[i], 1, 0);
		ft_add_word_space(&str, final_tab, i);
		i++;
	}
	if (final_tab)
		ft_free_tab(final_tab);
	return (str);
}

// Clear and process a string, including removing quotes and handling variables
char	*ft_clear_str(t_data *data, char *str)
{
	char	*final;
	char	**tab;

	tab = NULL;
	final = ft_remove_quotes(str);
	if (final)
	{
		tab = ft_split(final, ' ');
		free(final);
		final = ft_merge_quotes(data, tab);
	}
	print_lexer(&data->plist);
	return (final);
}

// Clear quotes and variables in a list of tokens.
void	ft_clear_quote(t_data *data)
{
	t_token	*current;

	current = data->plist;
	while (current)
	{
		if (ft_quote_inside(current->str))
			current->str = ft_clear_str(data, current->str);
		else
			current->str = ft_var_env(data, current->str);
		current = current->next;
	}
} */
