/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:12:28 by ddania-c          #+#    #+#             */
/*   Updated: 2023/10/25 15:30:17 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Check parser error, then merge all the WORD, change $VAR and
// remove the quotes
int	ft_parser(t_data *data)
{
	if (ft_parser_error(data->token) != 0)
		return (2);
	ft_expansion_var(data);
	ft_clear_quotes(data);
	return (0);
}
