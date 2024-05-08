/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:41:03 by maceccar          #+#    #+#             */
/*   Updated: 2023/11/10 15:41:03 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest_tmp;
	const char	*src_tmp;

	dest_tmp = dest;
	src_tmp = src;
	i = 0;
	if (dest == src || !n)
		return (dest);
	while (i < n)
	{
		dest_tmp[i] = src_tmp[i];
		i++;
	}
	return (dest);
}
