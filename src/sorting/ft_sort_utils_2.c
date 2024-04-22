/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:53:05 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/22 10:54:10 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int ft_get_index_in_a(int num)
{
	return (ft_dlist_index_of(ft_global_stack_a(), &num, ft_int_cmp));
}

int ft_get_index_in_b(int num)
{
	return (ft_dlist_index_of(ft_global_stack_b(), &num, ft_int_cmp));
}
