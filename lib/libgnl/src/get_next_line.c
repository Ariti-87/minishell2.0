/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:10:34 by arincon           #+#    #+#             */
/*   Updated: 2023/10/10 14:13:41 by arincon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* static char	*ft_first_line(char *stash)
{
	size_t	i;
	char	*line;

	if (!stash)
		return (NULL);
	i = 0;
	if (stash[0] == '\0')
		return (NULL);
	while (stash[i] != '\n' && stash[i])
		i++;
	line = ft_calloc (i + 2, 1);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i])
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n' && stash[i])
		line[i] = '\n';
	return (line);
}

static char	*ft_new_stash(char *stash)
{
	size_t	i;
	size_t	j;
	char	*new_stash;

	if (!stash)
		return (NULL);
	i = 0;
	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	while (stash[i] != '\n' && stash[i])
		i++;
	new_stash = ft_calloc(ft_strlen_gnl(stash) - i + 1, 1);
	if (!new_stash)
		return (NULL);
	j = -1;
	while (stash[i])
		new_stash[++j] = stash[++i];
	new_stash[++j] = '\0';
	free(stash);
	return (new_stash);
}

static char	*ft_read(int fd, char *buf, char *stash)
{
	int		read_re;
	char	*tmp;

	read_re = 1;
	while (read_re != 0)
	{
		read_re = read(fd, buf, BUFFER_SIZE);
		if (read_re < 0)
			return (NULL);
		buf[read_re] = '\0';
		if (!stash)
			stash = ft_calloc(1, 1);
		tmp = stash;
		stash = ft_strjoin_gnl(tmp, buf);
		free(tmp);
		if (ft_strchr_gnl(stash, '\n'))
			break ;
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*stash;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	stash = ft_read(fd, buf, stash);
	if (stash == NULL)
	{
		free(buf);
		return (NULL);
	}
	line = ft_first_line(stash);
	stash = ft_new_stash(stash);
	free(buf);
	return (line);
}
 */
