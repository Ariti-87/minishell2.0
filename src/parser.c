/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:12:28 by ddania-c          #+#    #+#             */
/*   Updated: 2023/10/19 18:14:09 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_token_join(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(*str) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i++] = ' ';
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free((void *)s1);
	return (str);
}

static void	ft_del_list(t_token *current)
{
	current->prev->next = current->next;
	if (current->next)
		current->next->prev = current->prev;
	free(current);
}

static void	ft_word_join(t_token *token)
{
	t_token	*current;
	t_token	*start;
	t_token *aux;
	int		status;

	status = false;
	current = token;
	while (current)
	{
		if (current->type == WORD && status == false)
		{
			status = true;
			start = current;
		}
		else if (current->type == WORD && status == true)
		{
			aux = current->prev;
			start->str = ft_token_join(start->str, current->str);
			ft_del_list(current);
			current = aux;
		}
		else if (current->type == PIPE)
			status = false;
		current = current->next;
	}
}


int	ft_parser(t_data *data)
{
	if (ft_parser_error(data->token) != 0)
		return (2);
	ft_word_join(data->token);
	ft_expansion_var(data);

	// ft_clear_quotes(*token);
	return (0);
}
