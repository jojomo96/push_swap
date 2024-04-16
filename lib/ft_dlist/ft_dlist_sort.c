/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:44:02 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/16 09:44:06 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

void	ft_dlist_sort(t_dlist *lst, int (*cmp)(void *, void *))
{
	t_dlist_node	*tmp;
	void			*content;
	int				swapped;

	if (!lst || !lst->head || !cmp)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		tmp = lst->head;
		while (tmp->next)
		{
			if (cmp(tmp->content, tmp->next->content) > 0)
			{
				content = tmp->content;
				tmp->content = tmp->next->content;
				tmp->next->content = content;
				swapped = 1;
			}
			tmp = tmp->next;
		}
	}
}
