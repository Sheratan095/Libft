/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:43:15 by maceccar          #+#    #+#             */
/*   Updated: 2023/11/10 15:43:15 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	l;
	unsigned int	l2;

	i = 0;
	l = 0;
	l2 = 0;
	while (dest[l])
		l++;
	while (src[l2])
		l2++;
	if (size == 0)
	{
		return (l2);
	}
	while (src[i] && i + l < size - 1)
	{
		dest[i + l] = src[i];
		i++;
	}
	if (i < size)
		dest[i + l] = '\0';
	if (l > size)
		return (l2 + size);
	return (l + l2);
}
