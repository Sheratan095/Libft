/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:40:56 by maceccar          #+#    #+#             */
/*   Updated: 2023/11/10 15:40:56 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const unsigned char	*char_dest;
	const unsigned char	*char_src;
	size_t				i;

	i = 0;
	char_dest = str1;
	char_src = str2;
	while (i < n)
	{
		if ((char_dest[i] - char_src[i]) != 0)
			return (char_dest[i] - char_src[i]);
		i++;
	}
	return (0);
}
