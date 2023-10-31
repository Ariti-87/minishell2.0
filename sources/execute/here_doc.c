/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:55:46 by arincon           #+#    #+#             */
/*   Updated: 2023/10/31 15:53:38 by arincon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_heredoc_create(t_data *data, int i, char *file_name)
{
	int		fd;
	char	*buf;

	fd = open(file_name, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd < 0)
		ft_error_msn("An error occured with open of here_doc\n", data);
	while (1)
	{
		buf = readline("heredoc> ");
		if (!buf)
		{
			printf("\n");
			break ;
		}
		if (buf || buf[0])
		{
			if (!ft_strcmp(data->cmds[i]->eof, buf))
				break ;
			write(fd, buf, ft_strlen(buf));
			write(fd, "\n", 1);
		}
		free(buf);
	}
	close(fd);
}

void	ft_heredoc_path(t_data *data, int i)
{
	char	*tmp;
	int		j;

	j = i + 1;
	if (data->cmds[i]->eof)
	{
		tmp = ft_itoa(j);
		data->cmds[i]->heredoc_path
			= ft_strjoin_gnl(".build/.heredoc", tmp);
		free(tmp);
		if (!data->cmds[i]->heredoc_path)
			ft_error_msn("Invalid Malloc here_doc path\n", data);
	}
}
/* void	ft_heredoc_path(t_data *data)
{
	int		i;
	int		j;
	char	*tmp;

	i = -1;
	j = 1;
	while (++i < data->cmds_nb)
	{
		if (data->cmds[i]->eof)
		{
			tmp = ft_itoa(j);
			data->cmds[i]->heredoc_path
				= ft_strjoin_gnl(".build/.heredoc", tmp);
			free(tmp);
			if (!data->cmds[i]->heredoc_path)
				ft_error_msn("Invalid Malloc here_doc path\n", data);
			j++;
		}
	}
} */
