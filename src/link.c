/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:14:46 by arincon           #+#    #+#             */
/*   Updated: 2023/10/16 17:02:27 by arincon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "minishell.h"

static void	ft_link_redirec(t_data *data, t_token *list, t_token *nlist, int cmd_index)
{
	if (list->str == '<')
		data->cmds[cmd_index]->input_redirec = nlist->str;
	if (list->str == '<<')
		data->cmds[cmd_index]->eof = nlist->str;
	if (list->str == '>')
		data->cmds[cmd_index]->output_redirec = nlist->str;
	if (list->str == '>>')
	{
		data->cmds[cmd_index]->output_redirec = nlist->str;
		data->cmds[cmd_index]->append = 1;
	}
}

static void	ft_link_cmd(t_data *data, t_token *list, int cmd_index)
{
	ft_isbuiltins(list, )
}

void	ft_link_exec(t_data *data)
{
	t_token	*current;
	t_token *cmd;
	int		cmd_index;

	cmd_index = 0;
	current = data->plist;
	while (current)
	{
		cmd = current;
		while (current && current->str != '|')
		{
			if (current->type == SEPARATOR)
				ft_link_redirec(data, current, current->next, cmd_index);
			else
			current->next;
		}
		ft_link_cmd(data, cmd, cmd_index);
		cmd_index++;
		current = current->next;
	}
} */
