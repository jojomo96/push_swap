/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:00:23 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/23 14:19:21 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_push_swap.h"

void	ft_rotate_a(int print)
{
	ft_dlist_rotate(ft_global_stack_a());
	if (print)
		ft_printf("ra\n");
}

void	ft_rotate_b(int print)
{
	ft_dlist_rotate(ft_global_stack_b());
	if (print)
		ft_printf("rb\n");
}

void	ft_rotate_r(int print)
{
	ft_dlist_rotate(ft_global_stack_a());
	ft_dlist_rotate(ft_global_stack_b());
	if (print)
		ft_printf("rr\n");
}
