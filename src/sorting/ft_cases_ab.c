/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cases_ab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:07:50 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/22 11:14:55 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int	ft_find_place(t_dlist *list, int num)
{
	int				i;
	t_dlist_node	*current;
	t_dlist_node	*next;

	if (num > *(int *)list->head->content && num < *(int *)list->tail->content)
		return (0);
	if (ft_is_new_max(list, num) || ft_is_new_min(list, num))
		return (ft_get_index_of_max(list));
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

int	ft_case_rarb(int num)
{
	int	rotations;

	rotations = ft_find_place_in_b(num);
	if (rotations < ft_get_index_in_a(num))
		rotations = ft_get_index_in_a(num);
	return (rotations);
}

int	ft_case_rrarrb(int num)
{
	int	rotations;
	int	size_a;
	int	size_b;

	size_a = ft_global_stack_a()->size;
	size_b = ft_global_stack_b()->size;
	rotations = ft_find_place_in_b(num);
	if (rotations)
		rotations = size_b - rotations;
	if (rotations < (size_a - ft_get_index_in_a(num)) && rotations > 0)
		rotations = size_a - ft_get_index_in_a(num);
	return (rotations);
}

int	ft_case_rrarb(int num)
{
	int	rotations;
	int	size_a;

	size_a = ft_global_stack_a()->size;
	rotations = ft_get_index_in_a(num);
	if (rotations)
		rotations = size_a - rotations;
	rotations = ft_find_place_in_b(num) + rotations;
	return (rotations);
}

int	ft_case_rarrb(int num)
{
	int	rotations;
	int	size_b;

	size_b = ft_global_stack_b()->size;
	rotations = ft_find_place_in_b(num);
	if (rotations)
		rotations = size_b - rotations;
	rotations = ft_get_index_in_a(num) + rotations;
	return (rotations);
}


