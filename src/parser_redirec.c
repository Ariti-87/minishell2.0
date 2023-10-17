/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_redirec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:36:39 by arincon           #+#    #+#             */
/*   Updated: 2023/10/17 17:46:48 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// t_token	ft_separe_token(char *str, char quote)
// {
// 	t_token	*token;

// 	if (!str)
// 		return (NULL);
// 	token = malloc(sizeof(t_token));
// 	if (!token)
// 		return (NULL);
// 	if (quote)
// 		token->type = ALPHANUM;
// 	else
// 		token->type = ft_type_token(*str);
// 	token->str = ft_calloc(2, sizeof(char));
// 	if (!token->str)
// 		return (NULL);
// 	*(token->str) = *str;
// 	token->next = NULL;
// 	return (token);
// }

// void	ft_final_list(t_data *data)
// {
// 	int		i;
// 	t_token	*current;

// 	i = 0;
// 	current = data->tlist;
// 	while (current)
// 	{
// 		if (current->type == SEPARATOR && *current->str == '|')
// 		{
// 			ft_lstadd_back_token(&data->plist, ft_tokenize(1, current));
// 			current = current->next;
// 		}
// 		else
// 		{
// 			i = ft_type_nb(current, current->type);
// 			ft_lstadd_back_token(&data->plist, ft_tokenize(i, current));
// 			while (i > 0 && current)
// 			{
// 				current = current->next;
// 				i--;
// 			}
// 		}
// 	}
// }

void	ft_parser_redirect(t_data *data, t_token *list)
{
	t_token *current;
	int		i;

	i = 0;
	current = list;
	while(current)
	{
		if (current->type == SEPARATOR && *current->str == '>')
		{
			ft_lstadd_back_token(&data->flist, ft_tokenize(1, current));
			if (current->next->type == ALPHANUM)
		}
	}
}

void	ft_split_node(t_token *head, char *str)
{
	char	*space_pos = ft_strchr(str, ' ')

	if (space_pos == NULL)
		return ;

}

void	ft
