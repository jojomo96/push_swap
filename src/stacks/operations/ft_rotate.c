/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:00:23 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/16 09:05:38 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_push_swap.h"

void	ft_rotate_a(void)
{
	ft_dlist_rotate(ft_global_stack_a());
	ft_printf("ra\n");
}

void	ft_rotate_b(void)
{
	ft_dlist_rotate(ft_global_stack_b());
	ft_printf("rb\n");
}

void	ft_rotate_r(void)
{
	ft_dlist_rotate(ft_global_stack_a());
	ft_dlist_rotate(ft_global_stack_b());
	ft_printf("rr\n");
}
