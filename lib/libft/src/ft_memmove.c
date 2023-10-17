/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:39:20 by arincon           #+#    #+#             */
/*   Updated: 2022/11/29 12:08:42 by arincon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	if (!src && !dest)
		return (NULL);
	d = dest;
	s = (unsigned char *) src;
	i = 0;
	if (d < s)
	{
		while (i++ < n)
			*d++ = *s++;
	}
	else
	{
		while (i < n)
		{
			d[n - 1] = s[n - 1];
			n--;
		}
	}
	return (dest);
}
