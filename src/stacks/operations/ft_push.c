/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:06:01 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/16 09:32:28 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_push_swap.h"

void	ft_push(t_dlist *src, t_dlist *dst)
{
	t_dlist_node	*node;

	if (!src || !dst || ft_dlist_size(src) == 0)
		return ;
	node = ft_dlist_pop_front(src);
	if (node)
		ft_dlist_prepend(dst, node);
}

void	ft_push_a(void)
{
	ft_push(ft_global_stack_b(), ft_global_stack_a());
	ft_printf("pa\n");
}

void	ft_push_b(void)
{
	ft_push(ft_global_stack_a(), ft_global_stack_b());
	ft_printf("pb\n");
}
