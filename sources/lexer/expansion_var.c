/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:44:43 by ddania-c          #+#    #+#             */
/*   Updated: 2023/10/23 12:22:35 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Create a str new to exchange the line
static char	*ft_exchange_var(char *token_str, int i, char *value, char *var)
{
	int		len;
	char	*str;
	int		j;

	j = 0;
	len = ((ft_strlen(token_str) - ft_strlen(var)) + ft_strlen(value));
	str = malloc(sizeof(char) * len);
	if (!str)
	{
		ft_putstr_fd("error: malloc\n", 2);
		return (NULL);
	}
	while (j < i && token_str[j])
	{
		str[j] = token_str[j];
		j++;
	}
	while (*value)
		str[j++] = *value++;
	i += ft_strlen(var) + 1;
	while (token_str[i])
		str[j++] = token_str[i++];
	str[j] = '\0';
	return (str);
}

// Get the what is the VAR to look in the env
static char	*ft_identify_var(char *str, int i)
{
	int		len;
	char	*var;
	int		j;

	i++;
	len = i;
	if (str[len] == '$')
		return ("$");
	while (str[len] != ' ' && str[len] != '=' && str[len] != '\"'
		&& str[len] != '\'' && str[len] && str[len] != '$')
		len++;
	len = len - i;
	var = (char *)malloc(sizeof(char) * (len + 1));
	if (!var)
	{
		ft_putstr_fd("error: malloc\n", 2);
		return (NULL);
	}
	j = 0;
	while (j < len)
		var[j++] = str[i++];
	var[j] = '\0';
	return (var);
}

// All the process to identify the VAR and replace it
static void	ft_remplace_var(t_token **token, int i, t_data *data)
{
	char	*var;
	char	*value;
	char	*new_str;

	var = ft_identify_var((*token)->str, i);
	// printf("VAR = %s;", var); // BORRAR
	// printf(" LEN = %ld;", ft_strlen(var)); // BORRAR
	value = ft_get_var_value(data, var);
	// printf("VALUE = %s;\n", value); // BORRAR
	if (value != NULL)
	{
		// printf("NS = %s;\n", (*token)->str); // BORRAR
		new_str = ft_exchange_var((*token)->str, i, value, var);
		free((*token)->str);
		(*token)->str = new_str;
		// printf("NS = %s;\n", (*token)->str); // BORRAR
	}
	else
		value = NULL;
	if (var[0] != '$')
		free(var);
}

// Check if there is '$VAR'
void	ft_expansion_var(t_data *data)
{
	t_token	*temp;
	int		i;
	int		quote;

	quote = N_QUOTE;
	temp = data->token;
	while (temp)
	{
		i = 0;
		while (temp->str[i])
		{
			if (temp->str[i] == '$' && temp->str[i + 1] == ' ')
				i++;
			quote = ft_update_quote(temp->str[i], quote);
			if (temp->str[i] == '$'
				&& ft_next_sep(temp->str[i + 1] == false)
				&& ft_between_quotes(temp->str, i) == false
				&& (quote == N_QUOTE || quote == D_QUOTES))
				ft_remplace_var(&temp, i, data);
			else
				i++;
		}
		temp = temp->next;
	}
}
