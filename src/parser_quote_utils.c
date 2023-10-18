/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_quote_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:07:08 by arincon           #+#    #+#             */
/*   Updated: 2023/10/18 17:13:52 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* // Clear quotes from a single string.
char	*ft_clear_word(char *str)
{
	char	*final;
	char	quote;
	t_coor	x;

	x.i = 0;
	quote = 0;
	if (!str || !*str)
		return (NULL);
	final = ft_strdup("'");
	while (str && str[x.i])
	{
		if (!quote && ft_belong("'\"", str[x.i]))
			quote = str[x.i];
		else if (quote && ft_belong("'\"", str[x.i]) && str[x.i] == quote)
			quote = 0;
		else
			final = ft_add_char(final, str[x.i]);
		x.i++;
	}
	final = ft_strjoin_free(final, "'", 1, 0);
	if (str)
		free(str);
	return (final);
}

// Add spaces between words in a string based on specific conditions.
void	ft_add_word_space(char **s, char **final, int i)
{
	if (ft_strlen(final[i]) >= 1 && !ft_belong("'", final[i][0])
			&& ft_type_token(final[i][0]) == ALPHANUM)
		*s = ft_strjoin_free(*s, " ", 1, 0);
	if (ft_strlen(final[i]) >= 2 && ft_belong("'", final[i][0])
			&& ft_type_token(final[i][0]) == ALPHANUM)
		*s = ft_strjoin_free(*s, " ", 1, 0);
}

// Identify if a character should be removed based on specific criteria.
int	ft_rm_quotes(char c, char c2, int i)
{
	if (c != ' ' && c != '\0')
		return (1);
	if (i > 0 && c2 != ' ')
		return (1);
	return (0);
}

// Determine whether to skip quotes in a string.
int	ft_skip_quotes(char *quote, int *j, char *str)
{
	int	i;

	i = *j;
	if (str[i] && ft_belong("'\"", str[i])
		&& str[i] == *quote && str[i + 1] == *quote && str[i + 2]
		&& i > 0 && ft_rm_quotes(str[i + 2], str[i - 1], i))
	{
		*j += 2;
		*quote = 0;
		return (1);
	}
	return (0);
}

// Add a character to a string and return the modified string.
char	*ft_add_char(char *str, char c)
{
	int		i;
	char	*str2;

	i = 0;
	str2 = calloc(ft_strlen(str) + 2, sizeof(char));
	if (!str2)
		return (NULL);
	while (str && str[i])
	{
		str2[i] = str[i];
		i++;
	}
	str2[i++] = c;
	str2[i] = '\0';
	if (str)
		free(str);
	return (str2);
} */
