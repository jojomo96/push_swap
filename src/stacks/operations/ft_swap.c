/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 08:55:10 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/16 09:05:07 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_push_swap.h"

void	ft_swap(t_dlist *stack)
{
	t_dlist_node	*first;
	t_dlist_node	*second;

	if (!stack || ft_dlist_size(stack) < 2)
		return ;
	first = stack->head;
	second = first->next;
	if (stack->size == 2)
	{
		stack->head = second;
		stack->tail = first;
		first->next = NULL;
		second->prev = NULL;
		second->next = first;
		first->prev = second;
		return ;
	}
	first->next = second->next;
	second->prev = first->prev;
	if (second->next != NULL)
		second->next->prev = first;
	first->prev = second;
	second->next = first;
	if (stack->head == first)
		stack->head = second;
}

void	ft_swap_a(void)
{
	ft_swap(ft_global_stack_a());
	ft_printf("sa\n");
}

void	ft_swap_b(void)
{
	ft_swap(ft_global_stack_b());
	ft_printf("sb\n");
}

void	ft_swap_s(void)
{
	ft_swap(ft_global_stack_a());
	ft_swap(ft_global_stack_b());
	ft_printf("ss\n");
}
