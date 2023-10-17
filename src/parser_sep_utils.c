/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_sep_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:44:53 by arincon           #+#    #+#             */
/*   Updated: 2023/10/16 10:35:12 by arincon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_error_msn_separator(char *str, int err_sep)
{
	ft_putstr_fd("minishell: error: syntax token '", 2);
	ft_putchar_fd(str[err_sep], 2);
	ft_putstr_fd("'\n", 2);
	return (1);
}

int	ft_lstsize_token(t_token *list)
{
	int		i;
	t_token	*current;

	i = 0;
	current = list;
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}

int	ft_same_char(char *str, char c, int len)
{
	int	i;

	i = 0;
	while (str[i] == c && i < len)
		i++;
	if (i == len)
		return (-1);
	return (i);
}
