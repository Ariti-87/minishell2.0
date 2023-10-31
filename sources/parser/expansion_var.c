/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:44:43 by ddania-c          #+#    #+#             */
/*   Updated: 2023/10/31 14:39:28 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_exchange_var(char *line, int i, char *value, char *var)
{
	int		len;
	char	*str;
	int		j;

	j = 0;
	len = ((ft_strlen(line) - ft_strlen(var)) + ft_strlen(value));
	str = malloc(sizeof(char) * len);
	if (!str)
	{
		ft_putstr_fd("error: malloc\n", 2);
		return (NULL);
	}
	while (j < i && line[j])
	{
		str[j] = line[j];
		j++;
	}
	while (*value)
		str[j++] = *value++;
	i += ft_strlen(var) + 1;
	while (line[i])
		str[j++] = line[i++];
	str[j] = '\0';
	return (str);
}

static bool	ft_check_var(char c)
{
	if (c >= 'a' && c <= 'z')
		return (true);
	else if (c >= 'A' && c <= 'Z')
		return (true);
	else if (c >= '0' && c <= '9')
		return (true);
	else if (c == '_')
		return (true);
	return (false);
}

static char	*ft_identify_var(char *str, int i)
{
	int		len;
	char	*var;
	int		j;

	i++;
	len = i;
	if (str[len] == '?')
		return ("?");
	if (str[len] == '$')
		return ("$");
	while (ft_check_var(str[len]) == true)
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

static void	ft_remplace_var(int i, t_data *data)
{
	char	*var;
	char	*value;
	char	*new_str;

	var = ft_identify_var(data->line, i);
	if (!var)
		return ;
	if (var[0] == '?')
		value = ft_itoa(g_last_status);
	else if (var[0] == '$')
		value = ft_strdup("PID");
	else
		value = ft_get_var_value(data, var);
	if (value != NULL)
	{
		new_str = ft_exchange_var(data->line, i, value, var);
		ft_free_ptr(data->line);
		data->line = new_str;
	}
	if (var[0] == '?' || var[0] == '$')
		ft_free_ptr(value);
	else
		ft_free_ptr(var);
}

void	ft_expansion_var(t_data *data)
{
	int		i;
	int		quote;

	quote = N_QUOTE;
	i = 0;
	while (data->line[i])
	{
		if (data->line[i] == '$' && data->line[i + 1] == ' ')
			i++;
		quote = ft_update_quote(data->line[i], quote);
		if (data->line[i] == '$'
			&& ft_next_sep(data->line[i + 1] == false)
			&& ft_between_quotes(data->line, i) == false
			&& (quote == N_QUOTE || quote == D_QUOTES))
			ft_remplace_var(i, data);
		else
			i++;
	}
}
