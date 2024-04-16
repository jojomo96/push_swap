/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_reverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:07:16 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/16 09:08:01 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_push_swap.h"

void	ft_rotate_reverse_a(void)
{
	ft_dlist_reverse_rotate(ft_global_stack_a());
	ft_printf("rra\n");
}

void	ft_rotate_reverse_b(void)
{
	ft_dlist_reverse_rotate(ft_global_stack_b());
	ft_printf("rrb\n");
}

void	ft_rotate_reverse_r(void)
{
	ft_dlist_reverse_rotate(ft_global_stack_a());
	ft_dlist_reverse_rotate(ft_global_stack_b());
	ft_printf("rrr\n");
}
