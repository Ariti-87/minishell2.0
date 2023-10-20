/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:27:23 by arincon           #+#    #+#             */
/*   Updated: 2023/10/13 15:49:58 by arincon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Prints an error message, cleans up resources,
// and exits the program.
void	ft_error_msn(char *str, t_data *data)
{
	write (2, str, ft_strlen(str));
	ft_close_and_free(data);
	exit (EXIT_FAILURE);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;

	i = 0;
	if (to_find[i] == '\0')
		return (&str[i]);
	while (str[i])
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

long int	ft_atol(const char *nptr)
{
	long int	i;
	int			sign;
	long int	res;

	if (!nptr)
		return (0);
	i = 0;
	res = 0;
	sign = 1;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-')
		sign = -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (10 * res) + (nptr[i] - '0');
		i++;
	}
	return (res * sign);
}

long long int	ft_atoll(const char *nptr)
{
	long long int	i;
	int				sign;
	long long int	res;

	if (!nptr)
		return (0);
	i = 0;
	res = 0;
	sign = 1;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-')
		sign = -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (10 * res) + (nptr[i] - '0');
		i++;
	}
	return ((unsigned char)res * sign);
}
