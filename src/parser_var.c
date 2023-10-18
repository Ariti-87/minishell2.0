/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:39:33 by arincon           #+#    #+#             */
/*   Updated: 2023/10/18 17:18:32 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* // Handle the status code and add it to the string.
static int	ft_match_status(char **f)
{
	*f = ft_strjoin_free(*f, ft_itoa(ft_get_last_status()), 1, 1);
	return (2);
}

// Add a dollar sign to the string based on specific conditions.
static void	ft_just_dollar(char **f, char c, int quote)
{
	if (quote || c == ' ' || c == '$' || !c)
		*f = ft_add_char(*f, '$');
}

// Retrieve the value of an environment variable.
static char	*ft_value_attr(t_data *data, char *str)
{
	t_env	*current;

	current = data->env;
	while (current)
	{
		if (!ft_strcmp(str, current->name))
			return (ft_strdup(current->var));
		current = current->next;
	}
	return (NULL);
}

// Extract and add variable values to the string.
static int	ft_var_value(t_data *data, char **f, char *str, char quote)
{
	int		i;
	char	*sub;
	char	*final;

	i = 0;
	final = NULL;
	if (!ft_strncmp("$?", str, 2))
		return (ft_match_status(f));
	if (str[i] == '$')
		i++;
	while (str && str[i] && (str[i] == '_' || ft_isalnum(str[i])))
		i++;
	sub = ft_substr(str, 0, i);
	final = ft_value_attr(data, sub + 1);
	if (!final && i == 1)
		ft_just_dollar(f, str[i], quote);
	else if (final)
		*f = ft_strjoin_free(*f, final, 1, 1);
	else if (sub && !final)
		*f = ft_strjoin_free(*f, "", 1, 0);
	if (sub)
		free(sub);
	return (i);
}

// Replace variables in a string with their values.
char	*ft_var_env(t_data *data, char *str)
{
	int		i;
	int		quote;
	char	*final;

	i = 0;
	final = NULL;
	quote = 0;
	while (str && str[i])
	{
		if (!quote && ft_belong("'\"", str[i]))
			quote = str[i];
		else if (quote && ft_belong("'\"", str[i]) && quote == str[i])
			quote = 0;
		if (str[i] == '$' && quote != '\'')
			i += ft_var_value(data, &final, str + i, quote);
		else
			final = ft_add_char(final, str[i++]);
	}
	if (final)
	{
		free(str);
		return (final);
	}
	else
		return (str);
} */
