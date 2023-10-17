/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_unclosed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:02:43 by arincon           #+#    #+#             */
/*   Updated: 2023/10/13 15:51:28 by arincon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Set the current quote character and the number of open quotes.
static void	set_quote_nquote(char *quote, int *nquote, char vquote, int vnquote)
{
	*quote = vquote;
	*nquote = vnquote;
}

// Check for unclosed quotes in a given line and
// print an error message if found.
int	ft_unclosed_quote(char *line)
{
	int		i;
	int		nquote;
	char	quote;

	i = 0;
	quote = 0;
	nquote = 0;
	while (line && line[i])
	{
		if (ft_belong("'\'''\"'", line[i]))
		{
			if (!nquote)
				set_quote_nquote(&quote, &nquote, line[i], nquote + 1);
			else if (quote == line[i])
				set_quote_nquote(&quote, &nquote, 0, nquote - 1);
		}
		i++;
	}
	if (line && quote && !line[i])
	{
		ft_putstr_fd("error: unclosed quotes\n", 2);
		return (1);
	}
	return (0);
}
