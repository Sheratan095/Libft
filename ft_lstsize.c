/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:40:45 by maceccar          #+#    #+#             */
/*   Updated: 2023/11/10 15:40:45 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*i;
	int		j;

	j = 1;
	i = malloc(sizeof(t_list));
	if (!i || !lst)
		return (0);
	*i = *lst;
	while (i->next)
	{
		*i = *i->next;
		j++;
	}
	return (j);
}
