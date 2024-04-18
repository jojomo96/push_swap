/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:08:57 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/18 16:56:11 by jmoritz          ###   ########.fr       */
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

void	ft_sort_until_3(void)
{
	ft_push_b();
	ft_print_both_stacks();
	int val = 3;
	printf("move count for 3 %d\n", ft_case_rarb(val));
	ft_apply_rarb(val, 1);
	printf("move count for 6 %d\n", ft_case_rarb(6));
	ft_apply_rarb(6, 1);
	printf("move count for 5 %d\n", ft_case_rarb(5));
	ft_apply_rarb(5, 1);
	printf("move count for 0 %d\n", ft_case_rarb(0));
	ft_apply_rarb(0, 1);
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
