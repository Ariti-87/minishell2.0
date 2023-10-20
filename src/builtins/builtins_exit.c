/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:24:18 by arincon           #+#    #+#             */
/*   Updated: 2023/10/20 18:03:07 by arincon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Attention au cas exit | exit voir avec le parsing
void	ft_exit(t_data *data, char **argv)
{
	int	i;

	i = 1;
	if (!argv[i])
	{
		ft_free_tab(data->builtins_tab);
		ft_close_and_free(data);
		exit (0);
	}
	if (argv[i] && argv[i + 1])
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		return ;
	}
	if (argv[i])
	{
		ft_exit_arg(argv[i]);
		ft_free_tab(data->builtins_tab);
		ft_close_and_free(data);
		exit(ft_atoll(argv[i]));
	}
}

void	ft_exit_arg(char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	if (str[i] == '=' || str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = 1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
		i++;
	if (str[i] || ft_above_lli(str, sign))
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": numeric argument required\n", 2);
	}
}

int	ft_above_lli(char *str, int sign)
{
	int		i;
	char	*max_lli;

	i = 0;
	max_lli = "9223372036854775807";
	if (ft_strlen(str) > ft_strlen(max_lli))
		return (1);
	if (ft_strlen(str) < ft_strlen(max_lli))
		return (0);
	while (max_lli[i] && max_lli[i + 1])
	{
		if (str[i] < max_lli[i])
			return (0);
		if (str[i] > max_lli[i])
			return (1);
		i++;
	}
	if (sign == 1 && str[i] > '8')
		return (1);
	if (sign == 0 && str[i] > '7')
		return (1);
	return (0);
}
