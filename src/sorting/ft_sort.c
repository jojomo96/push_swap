/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:08:57 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/16 20:01:09 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_sort_3(void)
{
	t_dlist	*stack;

	stack = ft_global_stack_a();
	if (ft_dlist_size(stack) == 2)
	{
		if (*(int *)ft_dlist_get(stack, 0) > *(int *)ft_dlist_get(stack, 1))
			ft_rotate_a();
		return ;
	}
	if (ft_dlist_is_sorted(stack, ft_int_cmp))
		return ;
	if(*(int *)ft_dlist_get_min(stack, ft_int_cmp) == *(int *)stack->head->content)
	{
		ft_rotate_reverse_a();
		ft_swap_a();
	}
	else if (*(int *)ft_dlist_get_max(stack, ft_int_cmp) == *(int *)stack->head->content)
	{
		ft_rotate_a();
		if(!ft_dlist_is_sorted(stack, ft_int_cmp))
			ft_swap_a();
	}
	else
	{
		if(ft_dlist_index_of(stack, ft_dlist_get_max(stack, ft_int_cmp), ft_int_cmp) == 1)
			ft_rotate_reverse_a();
		else
			ft_swap_a();
	}
}

void	ft_sort(void)
{
	if (ft_global_stack_a()->size <= 3)
		return (ft_sort_3());
	ft_push_b();
	ft_push_b();
	if (ft_global_stack_a()->size == 3)
		return (ft_sort_3());
}
