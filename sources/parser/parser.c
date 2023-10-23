/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:12:28 by ddania-c          #+#    #+#             */
/*   Updated: 2023/10/23 15:20:31 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Create the new str to exchange the WORD line
static char	*ft_token_join(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(*str) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!str)
	{
		ft_putstr_fd("error: malloc\n", 2);
		return (NULL);
	}
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
	return (str);
}

// Merge the list if style = WORD in the first WORD found and deleting
// the other second one
static void	ft_join_del_token(t_token *current, t_token *start)
{
	char	*joined;

	joined = ft_token_join(start->str, current->str);
	free(current->str);
	free(start->str);
	start->str = joined;
	if (current->next == NULL)
		current->prev->next = NULL;
	else
		current->prev->next = current->next;
	if (current->next != NULL)
		current->next->prev = current->prev;
	free(current);
}
// Verify the quotes, and putting all the WORD together
static void	ft_word_join(t_token *token)
{
	t_token *aux;
	t_token	*current;
	t_token	*start;
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
			ft_join_del_token(current, start);
			current = aux;
		}
		else if (current->type == PIPE)
			status = false;
		current = current->next;
	}
}

// Check parser error, then merge all the WORD, change $VAR and remove the quotes
int	ft_parser(t_data *data)
{
	if (ft_parser_error(data->token) == true)
		return (ft_set_last_status(data, 2));
	ft_word_join(data->token);
	ft_expansion_var(data);
	ft_clear_quotes(data);
	return (0);
}
