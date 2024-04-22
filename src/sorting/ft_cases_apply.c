/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cases_ab_apply.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:13:48 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/22 11:43:53 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int	ft_apply_rarb(int num, int is_a_to_b)
{
	t_dlist	*list;

	if (is_a_to_b)
	{
		list = ft_global_stack_a();
		while (*(int *)list->head->content != num
			&& ft_find_place_in_b(num) > 0)
			ft_rotate_r();
		while (*(int *)list->head->content != num)
			ft_rotate_a();
		while (ft_find_place_in_b(num) > 0)
			ft_rotate_b();
		ft_push_b();
		return (-1);
	}
	list = ft_global_stack_b();
	while (*(int *)list->head->content != num && ft_find_place_in_a(num) > 0)
		ft_rotate_r();
	while (*(int *)list->head->content != num)
		ft_rotate_b();
	while (ft_find_place_in_a(num) > 0)
		ft_rotate_r();
	ft_push_a();
	return (-1);
}

int	ft_apply_rrarrb(int num, int is_a_to_b)
{
	t_dlist	*list;

	if (is_a_to_b)
	{
		list = ft_global_stack_a();
		while (*(int *)list->head->content != num
			&& ft_find_place_in_b(num) > 0)
			ft_rotate_reverse_r();
		while (*(int *)list->head->content != num)
			ft_rotate_reverse_a();
		while (ft_find_place_in_b(num) > 0)
			ft_rotate_reverse_b();
		ft_push_b();
		return (-1);
	}
	list = ft_global_stack_b();
	while (*(int *)list->head->content != num && ft_find_place_in_a(num) > 0)
		ft_rotate_reverse_r();
	while (*(int *)list->head->content != num)
		ft_rotate_reverse_b();
	while (ft_find_place_in_a(num) > 0)
		ft_rotate_reverse_r();
	ft_push_a();
	return (-1);
}

int	ft_apply_rrarb(int num, int is_a_to_b)
{
	t_dlist	*list;

	if (is_a_to_b)
	{
		list = ft_global_stack_a();
		while (*(int *)list->head->content != num)
			ft_rotate_reverse_a();
		while (ft_find_place_in_b(num) > 0)
			ft_rotate_b();
		ft_push_b();
		return (-1);
	}
	list = ft_global_stack_b();
	while (*(int *)list->head->content != num)
		ft_rotate_reverse_a();
	while (ft_find_place_in_a(num) > 0)
		ft_rotate_b();
	ft_push_a();
	return (-1);
}

int	ft_apply_rarrb(int num, int is_a_to_b)
{
	t_dlist	*list;

	if (is_a_to_b)
	{
		list = ft_global_stack_a();
		while (*(int *)list->head->content != num)
			ft_rotate_a();
		while (ft_find_place_in_b(num) > 0)
			ft_rotate_reverse_b();
		ft_push_b();
		return (-1);
	}
	list = ft_global_stack_b();
	while (*(int *)list->head->content != num)
		ft_rotate_a();
	while (ft_find_place_in_a(num) > 0)
		ft_rotate_reverse_b();
	ft_push_a();
	return (-1);
}
