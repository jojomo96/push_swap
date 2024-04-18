/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cases_ab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:07:50 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/18 16:32:49 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int	ft_find_place(t_dlist *list, int num)
{
	int				i;
	t_dlist_node	*current;
	t_dlist_node	*next;

	if (num > *(int *)list->head->content && num < *(int *)list->tail->content)
	{
		// printf("Chase num is between min and max\n");
		return (0);
	}
	if (ft_is_new_max(list, num) || ft_is_new_min(list, num))
	{
		// printf("Chase num is new min or max\n");
		return (ft_get_index_of_max(list));
	}
	// printf("Chase num is in the middle\n");
	i = 1;
	current = list->head;
	next = current->next;
	while (current != list->tail && (num > *(int *)current->content
			|| num < *(int *)next->content))
	{
		current = current->next;
		next = current->next;
		i++;
	}
	return (i);
}

int	ft_find_place_in_b(int num)
{
	return (ft_find_place(ft_global_stack_b(), num));
}

int	ft_find_place_in_a(int num)
{
	return (ft_find_place(ft_global_stack_a(), num));
}

int ft_case_rarb(int num)
{
	int rotations;

	rotations = ft_find_place_in_b(num);
	if (rotations < ft_dlist_index_of(ft_global_stack_a(), &num, ft_int_cmp))
		rotations = ft_dlist_index_of(ft_global_stack_a(), &num, ft_int_cmp);
	return (rotations);
}

// int	ft_case_rarb(int num)
// {
// 	int	rotations;
// 	int	place_in_b;
// 	int	index_in_a;

// 	rotations = 0;
// 	place_in_b = ft_find_place_in_b(num);
// 	if (place_in_b)
// 		rotations = (ft_global_stack_b()->size - place_in_b);
// 	index_in_a = ft_dlist_index_of(ft_global_stack_a(), &num, ft_int_cmp);
// 	if (rotations < (int)(ft_global_stack_a()->size - index_in_a))
// 		rotations = (ft_global_stack_a()->size - index_in_a);
// 	return (rotations);
// }

int ft_apply_rarb(int num, int is_a_to_b)
{
	t_dlist	*list_a;
	t_dlist	*list_b;

	list_a = ft_global_stack_a();
	list_b = ft_global_stack_b();

	if (is_a_to_b)
	{
		while(*(int *)list_a->head->content != num && ft_find_place_in_b(num) > 0)
			ft_rotate_r();
		while(*(int *)list_a->head->content != num)
			ft_rotate_a();
		while(ft_find_place_in_b(num) > 0)
			ft_rotate_b();
		ft_push_b();
	}
	else
	{
		while(*(int *)list_b->head->content != num && ft_find_place_in_a(num) > 0)
			ft_rotate_r();
		while(*(int *)list_b->head->content != num)
			ft_rotate_b();
		while(ft_find_place_in_a(num) > 0)
			ft_rotate_r();
		ft_push_a();
	}
	return (1);
}
