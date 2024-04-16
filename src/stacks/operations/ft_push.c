/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:06:01 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/16 09:07:08 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_push_swap.h"

void	ft_push(t_dlist *src, t_dlist *dst)
{
	t_dlist_node	*node;

	if (!src || !dst || ft_dlist_size(src) == 0)
		return ;
	node = src->head;
	src->head = node->next;
	if (src->head)
		src->head->prev = NULL;
	if (!dst->head)
	{
		dst->head = node;
		dst->tail = node;
		node->prev = NULL;
		node->next = NULL;
	}
	else
	{
		node->next = dst->head;
		dst->head->prev = node;
		dst->head = node;
	}
}

void	ft_push_a(void)
{
	ft_push(ft_global_stack_b(), ft_global_stack_a());
	ft_printf("pa\n");
}

void	ft_push_b(void)
{
	ft_push(ft_global_stack_a(), ft_global_stack_b());
	ft_printf("pb\n");
}
