/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_var_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:31:25 by arincon           #+#    #+#             */
/*   Updated: 2023/10/13 15:31:45 by arincon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Modify variables in an array of strings
void	ft_modif_var_env(t_data *data, char **tab)
{
	int		i;
	char	*var;

	i = 0;
	var = NULL;
	while (tab && tab[i])
	{
		if (!ft_belong("'", tab[i][0]))
		{
			var = ft_var_env(data, tab[i]);
			tab[i] = var;
		}
		i++;
	}
}
