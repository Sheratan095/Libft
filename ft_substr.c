/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:42:51 by maceccar          #+#    #+#             */
/*   Updated: 2023/11/10 15:42:52 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*result;
	size_t		j;
	size_t		str_len;

	str_len = ft_strlen(s);
	j = 0;
	if (start >= str_len)
	{
		result = ft_calloc(1, sizeof(char));
		return (result);
	}
	if (len > str_len)
		len = str_len;
	if (start + len > str_len)
		len = str_len - start;
	result = malloc(sizeof(char) * (len + 1));
	if (!result || !s)
		return (NULL);
	while ((start < str_len) && s[start + j] && j < len)
	{
		result[j] = s[start + j];
		j++;
	}
	result[j] = '\0';
	return (result);
}
