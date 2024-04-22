/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:08:57 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/22 19:35:52 by jmoritz          ###   ########.fr       */
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
		if (ft_dlist_index_of(stack, ft_dlist_get_max(stack, ft_int_cmp),
				ft_int_cmp) == 1)
			ft_rotate_reverse_a();
		else
			ft_swap_a();
	}
}

int	ft_find_fewerst_moves(t_dlist_node *node, int is_a_to_b)
{
	int	rotations;

	rotations = ft_case_rrarrb(*(int *)node->content, is_a_to_b);
	while (node)
	{
		if (ft_case_rarb(*(int *)node->content, is_a_to_b) < rotations)
			rotations = ft_case_rarb(*(int *)node->content, is_a_to_b);
		if (ft_case_rrarrb(*(int *)node->content, is_a_to_b) < rotations)
			rotations = ft_case_rrarrb(*(int *)node->content, is_a_to_b);
		if (ft_case_rarrb(*(int *)node->content, is_a_to_b) < rotations)
			rotations = ft_case_rarrb(*(int *)node->content, is_a_to_b);
		if (ft_case_rrarb(*(int *)node->content, is_a_to_b) < rotations)
			rotations = ft_case_rrarb(*(int *)node->content, is_a_to_b);
		node = node->next;
	}
	if(rotations > 100)
		printf("rotations: %d\n", rotations);
	return (rotations);
}

void	ft_sort_until_3(int is_a_to_b)
{
	t_dlist_node	*node;
	int				rotations;

	while ((is_a_to_b && ft_global_stack_a()->size > 3
			&& !ft_dlist_is_sorted(ft_global_stack_a(), ft_int_cmp))
		|| (!is_a_to_b && ft_global_stack_b()->head))
	{
		if (is_a_to_b)
			node = ft_global_stack_a()->head;
		else
			node = ft_global_stack_b()->head;
		rotations = ft_find_fewerst_moves(node, is_a_to_b);
		while (rotations >= 0)
		{
			if (ft_case_rarb(*(int *)node->content, is_a_to_b) == rotations)
				rotations = ft_apply_rarb(*(int *)node->content, is_a_to_b);
			else if (ft_case_rrarrb(*(int *)node->content, is_a_to_b) == rotations)
				rotations = ft_apply_rrarrb(*(int *)node->content, is_a_to_b);
			else if (ft_case_rarrb(*(int *)node->content, is_a_to_b) == rotations)
				rotations = ft_apply_rarrb(*(int *)node->content, is_a_to_b);
			else if (ft_case_rrarb(*(int *)node->content, is_a_to_b) == rotations)
				rotations = ft_apply_rrarb(*(int *)node->content, is_a_to_b);
			else
				node = node->next;
		}
	}
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
		ft_sort_until_3(1);
	if (!ft_is_stack_sorted(ft_global_stack_a()))
		ft_sort_3();
	ft_sort_until_3(0);
}
