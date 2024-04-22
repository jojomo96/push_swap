/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:08:57 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/22 10:40:20 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_sort_3(void)
{
	t_dlist	*stack;

	stack = ft_global_stack_a();
	if (ft_dlist_is_sorted(stack, ft_int_cmp))
		return ;
	if (*(int *)ft_dlist_get_min(stack,
			ft_int_cmp) == *(int *)stack->head->content)
	{
		ft_rotate_reverse_a();
		ft_swap_a();
	}
	else if (*(int *)ft_dlist_get_max(stack,
			ft_int_cmp) == *(int *)stack->head->content)
	{
		ft_rotate_a();
		if (!ft_dlist_is_sorted(stack, ft_int_cmp))
			ft_swap_a();
	}
	else
	{
		if (ft_dlist_index_of(stack, ft_dlist_get_max(stack, ft_int_cmp), ft_int_cmp) == 1)
			ft_rotate_reverse_a();
		else
			ft_swap_a();
	}
}

int	ft_find_fewerst_moves(t_dlist_node *node)
{
	int	rotations;

	rotations = ft_case_rarb(*(int *)node->content);
	while (node->next)
	{
		if (ft_case_rarb(*(int *)node->next->content) < rotations)
			rotations = ft_case_rarb(*(int *)node->next->content);
		node = node->next;
	}
	return (rotations);
}

void	ft_sort_until_3(void)
{
	t_dlist_node	*node;
	int				rotations;

	while (ft_global_stack_a()->size > 3
		&& !ft_dlist_is_sorted(ft_global_stack_a(), ft_int_cmp))
	{
		node = ft_global_stack_a()->head;
		rotations = ft_find_fewerst_moves(ft_global_stack_b()->head);
		while (rotations >= 0)
		{
			if (ft_case_rarb(*(int *)node->content) == rotations)
			{
				rotations = ft_apply_rarb(*(int *)node->content, 1);
				// ft_print_both_stacks();
				// ft_printf("\n");
			}
			node = node->next;
		}
	}
	// ft_sort_3();
}

void	ft_sort(void)
{
	if (ft_global_stack_a()->size == 2)
		return (ft_swap_a());
	if (ft_global_stack_a()->size == 3)
		return (ft_sort_3());
	// push 2 elements to stack b
	if (!ft_is_stack_sorted(ft_global_stack_a())
		&& ft_global_stack_a()->size > 3)
		ft_push_b();
	if (!ft_is_stack_sorted(ft_global_stack_a())
		&& ft_global_stack_a()->size > 3)
		ft_push_b();
	if (!ft_is_stack_sorted(ft_global_stack_a())
		&& ft_global_stack_a()->size > 3)
		ft_sort_until_3();
	// if(!ft_is_stack_sorted(ft_global_stack_a()))
	// 	ft_sort_3();
}
