/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:39:34 by maceccar          #+#    #+#             */
/*   Updated: 2023/11/10 15:39:36 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_digits(long int num)
{
	size_t		count;

	count = 1;
	if (num < 0)
	{
		count++;
		num = -num;
	}
	while (num >= 10)
	{
		num /= 10;
		count++;
	}
	return (count);
}

static char	*reverse_string(char *s, int s_length)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = s_length - 1;
	while (i < (s_length / 2))
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		i++;
		j--;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char		*res;
	int			i;
	size_t		digits_count;
	long int	ln;

	ln = n;
	digits_count = count_digits(ln);
	res = ft_calloc(sizeof(char) * (digits_count + 1), sizeof(char));
	if (!res)
		return (NULL);
	if (ln < 0)
	{
		ln = -ln;
		res[digits_count - 1] = '-';
	}
	i = 0;
	while (ln >= 10)
	{
		res[i] = (ln % 10) + 48;
		ln /= 10;
		i++;
	}
	res[i] = (ln % 10) + 48;
	return (reverse_string(res, digits_count));
}
