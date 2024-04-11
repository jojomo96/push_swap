/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:57:51 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/11 16:56:18 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	ft_error(char *message)
{
	t_dlist	*stack_a;
	t_dlist	*stack_b;

	stack_a = ft_global_stack_a();
	stack_b = ft_global_stack_b();
	ft_dlist_destroy(&stack_a, free);
	ft_dlist_destroy(&stack_b, free);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	ft_putchar_fd('\n', 2);
	exit(EXIT_FAILURE);
}
