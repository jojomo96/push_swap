/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:53:05 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/22 23:01:21 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int	ft_get_index_in_a(int num)
{
	return (ft_dlist_index_of(ft_global_stack_a(), &num, ft_int_cmp));
}

int	ft_get_index_in_b(int num)
{
	return (ft_dlist_index_of(ft_global_stack_b(), &num, ft_int_cmp));
}

int	ft_find_place_in_b(int num)
{
	int				i;
	t_dlist			*list;
	t_dlist_node	*current;
	t_dlist_node	*next;

	list = ft_global_stack_b();
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

int	ft_find_place_in_a(int num)
{
	int				i;
	t_dlist			*list;
	t_dlist_node	*current;
	t_dlist_node	*next;

	list = ft_global_stack_a();
	if (num < *(int *)list->head->content && num > *(int *)list->tail->content)
		return (0);
	if (ft_is_new_max(list, num) || ft_is_new_min(list, num))
		return (ft_get_index_of_min(list));
	i = 1;
	current = list->head;
	next = current->next;
	while (current != list->tail && (num < *(int *)current->content
			|| num > *(int *)next->content))
	{
		current = current->next;
		next = current->next;
		i++;
	}
	return (i);
}

t_dlist	*ft_get_corresponding_stack( int is_a_to_b)
{
	if (is_a_to_b)
		return (ft_global_stack_a());
	return (ft_global_stack_b());
}
