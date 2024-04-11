/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_global_stacks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:35:52 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/11 14:36:40 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

t_dlist	*ft_global_stack_a(void)
{
	static t_dlist	*stack_a = NULL;

	if (!stack_a)
		stack_a = ft_dlist_new();
	return (stack_a);
}

t_dlist	*ft_global_stack_b(void)
{
	static t_dlist	*stack_b = NULL;

	if (!stack_b)
		stack_b = ft_dlist_new();
	return (stack_b);
}

void	ft_global_stacks_destroy(void)
{
	t_dlist	*stack_a;
	t_dlist	*stack_b;

	stack_a = ft_global_stack_a();
	stack_b = ft_global_stack_b();
	ft_dlist_destroy(&stack_a, NULL);
	ft_dlist_destroy(&stack_b, NULL);
}
