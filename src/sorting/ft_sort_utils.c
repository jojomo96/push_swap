/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:05:39 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/18 14:12:33 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int	ft_is_new_min(t_dlist *stack, int num)
{
	int min = *(int *)ft_dlist_get_min(stack, ft_int_cmp);
	return (min > num);
}

int	ft_get_index_of_min(t_dlist *stack)
{
	return (ft_dlist_index_of(stack, ft_dlist_get_min(stack, ft_int_cmp),
			ft_int_cmp));
}

int	ft_is_new_max(t_dlist *stack, int num)
{
	int max = *(int *)ft_dlist_get_max(stack, ft_int_cmp);
	return (max < num);
}
int	ft_get_index_of_max(t_dlist *stack)
{
	return (ft_dlist_index_of(stack, ft_dlist_get_max(stack, ft_int_cmp),
			ft_int_cmp));
}

int	ft_is_stack_sorted(t_dlist *stack)
{
	return (ft_dlist_is_sorted(stack, ft_int_cmp));
}
