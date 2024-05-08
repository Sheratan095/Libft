/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:43:34 by maceccar          #+#    #+#             */
/*   Updated: 2023/11/10 15:43:35 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static size_t	count_words(const char *s, char sep)
// {
// 	size_t	count;
// 	int		i;

// 	count = 0;
// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] != sep)
// 		{
// 			while (s[i] != sep && s[i])
// 				i++;
// 			count++;
// 		}
// 		else
// 			i++;
// 	}
// 	return (count);
// }

// static char	*set_row(char *res, const char *s, int start, int end)
// {
// 	int	j;

// 	j = 0;
// 	res = ft_calloc(sizeof(char) * (end - start + 1 + 1), sizeof(char));
// 	if (!res)
// 		return (NULL);
// 	while (start <= end)
// 	{
// 		res[j] = s[start];
// 		start++;
// 		j++;
// 	}
// 	return (res);
// }

// static void	free_matrix(char **result, int count)
// {
// 	int	i;

// 	i = 0;
// 	while (i <= count)
// 	{
// 		free(result[i]);
// 		i++;
// 	}
// 	free(result);
// 	return ;
// }

// static int	split(char **result, const char *s, char sep, int i)
// {
// 	int	current_row;
// 	int	start;
// 	int	end;

// 	current_row = 0;
// 	start = 0;
// 	end = 0;
// 	while (s[i])
// 	{
// 		if (s[i] != sep)
// 		{
// 			start = i;
// 			while (s[i] != sep && s[i])
// 				i++;
// 			end = i - 1;
// 			result[current_row] = set_row(result[current_row], s, start, end);
// 			if (!result[current_row])
// 				return (-1);
// 			current_row++;
// 		}
// 		else
// 			i++;
// 	}
// 	return (0);
// }

// char	**ft_split(char const *s, char c)
// {
// 	size_t	word_count;
// 	char	**result;
// 	int		i;

// 	i = 0;
// 	word_count = count_words(s, c);
// 	result = ft_calloc(sizeof(char) * (word_count + 1), sizeof(char *));
// 	if (!result)
// 		return (NULL);
// 	if (word_count == 0)
// 		return (result);
// 	if (split(result, s, c, i) == -1)
// 	{
// 		free_matrix(result, word_count + 1);
// 		return (NULL);
// 	}
// 	return (result);
// }

static size_t	ft_count_arr(char const *s, char c)
{
	size_t	count;
	size_t	i;
	size_t	in_arr;

	i = 0;
	count = 0;
	in_arr = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && in_arr == 0)
		{
			count++;
			in_arr = 1;
		}
		else if (s[i] == c)
			in_arr = 0;
		i++;
	}
	return (count);
}

static char	*ft_make_string(char const *s, size_t start, char c)
{
	char	*division;
	size_t	i;
	size_t	j;
	size_t	str_len;

	i = 0;
	j = start;
	str_len = 0;
	if (s[i] == '\0' || s == 0)
		return (NULL);
	while (s[j] != c && s[j])
	{
		j++;
		str_len++;
	}
	division = (char *)ft_calloc(str_len + 1, sizeof(char));
	if (division == NULL)
		return (NULL);
	while (i < str_len)
		division[i++] = s[start++];
	division[i] = '\0';
	return (division);
}

static void	ft_clear(char **array, size_t arr_index)
{
	while (arr_index-- > 0)
		free(array[arr_index]);
	free(array);
}

static char	**ft_make_split(char **array, char const *s, char c)
{
	int	i;
	int	in_arr;
	int	arr_index;

	i = -1;
	in_arr = 0;
	arr_index = 0;
	while (s[++i] != '\0')
	{
		if (s[i] != c && in_arr == 0)
		{
			array[arr_index++] = ft_make_string(s, i, c);
			if (array[arr_index - 1] == NULL)
			{
				ft_clear(array, arr_index);
				return (NULL);
			}
			in_arr = 1;
		}
		else if (s[i] == c)
			in_arr = 0;
	}
	array[arr_index] = 0;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	array = (char **)ft_calloc(ft_count_arr(s, c) + 1, sizeof(char *));
	if (array == NULL)
		return (NULL);
	array = ft_make_split(array, s, c);
	if (array == NULL)
		return (NULL);
	else
		return (array);
}

// int main()
// {
// 	char**res = ft_split("^^^1^^2a,^^^^3^^^^--h^^^^", '^');
// 	int i = 0;
// 	while(res[i])
// 	{
// 		ft_putstr_fd(res[i], 1);
// 		ft_putchar_fd('\n', 1);
// 		i++;
// 	}
// }
