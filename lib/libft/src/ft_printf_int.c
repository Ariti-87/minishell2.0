/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:26:40 by arincon           #+#    #+#             */
/*   Updated: 2023/04/04 14:54:29 by arincon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_nbr(int n)
{
	int		len;
	char	*str;

	str = ft_itoa(n);
	len = ft_print_str(str);
	free (str);
	return (len);
}

int	ft_print_unbr(unsigned int n)
{
	int		len;
	char	*str;

	str = ft_utoa(n);
	len = ft_print_str(str);
	free (str);
	return (len);
}

int	ft_len_hex(size_t n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

int	ft_print_hex(unsigned int n, char conversion)
{
	if (n == 0)
		return (write(1, "0", 1));
	if (n >= 16)
	{
		ft_print_hex(n / 16, conversion);
		ft_print_hex(n % 16, conversion);
	}
	else
	{
		if (n <= 9)
			ft_print_char(n + '0');
		else
		{
			if (conversion == 'x')
				ft_print_char(n - 10 + 'a');
			if (conversion == 'X')
				ft_print_char(n - 10 + 'A');
		}
	}
	return (ft_len_hex(n));
}
