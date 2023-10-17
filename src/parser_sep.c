/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_sep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:29:27 by arincon           #+#    #+#             */
/*   Updated: 2023/10/17 14:54:20 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_valid_sep(char *str, int *err_sep)
{
	int		len;
	char	*str2;

	str2 = "<>";
	len = ft_strlen(str);
	*err_sep = 0;
	if (len == 2)
	{
		if (str[0] == '<')
			*err_sep = ft_same_char(str, '<', 2);
		else if (str[0] == '>')
			*err_sep = ft_same_char(str, '>', 2);
	}
	else if (ft_belong(str2, str[0]))
	{
		if (str[1] == '\0')
			*err_sep = -1;
		else
			*err_sep = 1;
	}
	return (*err_sep);
}

static int	ft_error_redirec(t_token *list, t_token *nlist)
{
	int	err_sep;

	err_sep = 0;
	if (ft_valid_sep(list->str, &err_sep) != -1)
		return (ft_error_msn_separator(list->str, err_sep));
	if (!nlist || nlist->type == SEPARATOR)
		return (ft_error_msn_separator(list->str, 0));
	return (0);
}

static int	ft_error_pipe(t_token *list, t_token *nlist, t_token *plist)
{
	int	err;

	err = 0;
	if (!plist || plist->type == SEPARATOR)
		err = 1;
	if (!nlist)
		err = 1;
	if (ft_strlen(list->str) > 1 && list->str[1] == '|')
		err = 1;
	if (err)
		return (ft_error_msn_separator(list->str, 0));
	return (0);
}

static int	ft_match_sep(t_data *data, t_token *list, t_token *plist)
{
	int	err;

	err = 0;
	if (ft_lstsize_token(data->plist) == 1)
		return (ft_error_msn_separator(list->str, 0));
	if (ft_belong("><", *list->str))
		err = ft_error_redirec(list, list->next);
	if (*list->str == '|')
		err = ft_error_pipe(list, list->next, plist);
	if (err)
		return (err);
	return (0);
}

int	ft_error_separator(t_data *data, t_token *list)
{
	int		err;
	t_token	*tmp;
	t_token	*plist;

	err = 0;
	plist = NULL;
	tmp = list;
	while (list)
	{
		if (list->type == SEPARATOR)
		{
			err = ft_match_sep(data, list, plist);
			if (err)
				return (err);
		}
		plist = list;
		list = list->next;
	}
	list = tmp;
	return (0);
}
