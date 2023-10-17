/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:57:36 by arincon           #+#    #+#             */
/*   Updated: 2022/12/08 09:32:31 by arincon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	d;
	size_t	s;

	if (!size)
		return (ft_strlen(src));
	d = ft_strlen(dst);
	s = ft_strlen(src);
	i = 0;
	if (size > 0 && d < (size - 1))
	{
		while (src[i] && (d + i) < (size - 1))
		{
			dst[d + i] = src[i];
			i++;
		}
		dst[d + i] = '\0';
	}
	if (d >= size)
		d = size;
	return (d + s);
}
