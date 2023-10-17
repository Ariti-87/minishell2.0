/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:58:29 by arincon           #+#    #+#             */
/*   Updated: 2023/04/04 14:52:01 by arincon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_conversions(va_list ap, char conversion)
{
	int	taille;

	taille = 0;
	if (conversion == 'c')
		taille = ft_print_char(va_arg(ap, int));
	else if (conversion == 's')
		taille = ft_print_str(va_arg(ap, char *));
	else if (conversion == 'p')
		taille = ft_print_ptr(va_arg(ap, unsigned long long));
	else if (conversion == 'd' || conversion == 'i')
		taille = ft_print_nbr(va_arg(ap, int));
	else if (conversion == 'u')
		taille = ft_print_unbr(va_arg(ap, unsigned int));
	else if (conversion == 'x' || conversion == 'X')
		taille = ft_print_hex(va_arg(ap, unsigned int), conversion);
	else if (conversion == '%')
		taille = ft_print_char('%');
	return (taille);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		count;

	if (!str)
		return (-1);
	i = 0;
	count = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (!(str[i + 1]))
				return (-1);
			else
				count += ft_conversions(ap, str[i++ + 1]);
		}
		else
			count += ft_print_char(str[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
