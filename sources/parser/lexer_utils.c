/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:25:35 by arincon           #+#    #+#             */
/*   Updated: 2023/10/25 11:42:44 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_set_status_quote(int quote, char *line, int i)
{
	if (line[i] == '\'' && quote == N_QUOTE)
		quote = S_QUOTE;
	else if (line[i] == '\"' && quote == N_QUOTE)
		quote = D_QUOTES;
	else if (line[i] == '\'' && quote == S_QUOTE)
		quote = N_QUOTE;
	else if (line[i] == '\"' && quote == D_QUOTES)
		quote = N_QUOTE;
	return (quote);
}

static t_token	*ft_new_token(char *str, int type)
{
	t_token	*new;

	new = malloc(sizeof(t_token) * 1);
	if (!(new))
	{
		ft_putstr_fd("error: malloc\n", 2);
		return (NULL);
	}
	new->str = str;
	new->type = type;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

static void	ft_lstadd_back_token(t_token **lst, t_token *new)
{
	t_token	*temp;

	if (!new)
		return ;
	if (!lst || !*lst)
		*lst = new;
	else
	{
		temp = *lst;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
	}
}

void	ft_add_sep(t_token **token, char *line, int i, int len)
{
	int		index;
	char	*str;
	int		type;

	index = 0;
	type = ft_set_sep_type(line, i);
	str = malloc(sizeof(char) * len);
	if (!str)
		return (ft_putstr_fd("error: malloc\n", 2));
	while (index < (len - 1))
	{
		str[index] = line[i];
		index++;
		i++;
	}
	str[index] = '\0';
	ft_lstadd_back_token(token, ft_new_token(str, type));
}

void	ft_add_word(t_token **token, char *line, int i, int start)
{
	int		index;
	char	*str;

	index = 0;
	str = malloc(sizeof(char) * (i - start + 1));
	if (!str)
		return (ft_putstr_fd("error: malloc\n", 2));
	while (start < i)
	{
		str[index] = line[start];
		index++;
		start++;
	}
	str[index] = '\0';
	ft_lstadd_back_token(token, ft_new_token(str, WORD));
}
