/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 00:54:57 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/10 15:13:31 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_dlist_node	*ft_dlist_new_node(void *content)
{
	t_dlist_node	*new;

	new = (t_dlist_node *)malloc(sizeof(t_dlist_node));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_dlist	*ft_dlist_new(void)
{
	t_dlist	*new;

	new = (t_dlist *)malloc(sizeof(t_dlist));
	if (!new)
		return (NULL);
	new->head = NULL;
	new->tail = NULL;
	new->size = 0;
	return (new);
}

void	ft_dlist_destroy(t_dlist **lst, void (*del)(void *))
{
	t_dlist_node	*tmp;

	if (!lst || !*lst)
		return ;
	while ((*lst)->head)
	{
		tmp = (*lst)->head->next;
		if (del)
			del((*lst)->head->content);
		free((*lst)->head);
		(*lst)->head = tmp;
	}
	free(*lst);
	*lst = NULL;
}
