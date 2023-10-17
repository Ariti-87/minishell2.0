/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arincon <arincon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:02:15 by arincon           #+#    #+#             */
/*   Updated: 2023/10/10 15:05:48 by arincon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (!size || !nmemb)
		return (malloc(0));
	if (size * nmemb / size != nmemb)
		return (NULL);
	p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	ft_bzero (p, nmemb * size);
	return (p);
}

/* void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (!nmemb || !size)
		return (malloc(0));
	if (nmemb > SIZE_MAX || size > SIZE_MAX)
		return (NULL);
	p = malloc(nmemb * size);
	ft_bzero(p, nmemb * size);
	return (p);
} */
