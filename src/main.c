/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:36:42 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/16 11:43:38 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_print_int(t_dlist_node *node)
{
	if (!node)
		ft_printf("NULL");
	else
		ft_printf("%d (prev: %d, next: %d) ", *(int *)node->content,
			node->prev ? *(int *)node->prev->content : 0,
			node->next ? *(int *)node->next->content : 0);
}
void	ft_print_stack_info(t_dlist *stack)
{
	ft_printf("Stack size: %d\n", ft_dlist_size(stack));
	ft_printf("Stack head: ");
	ft_print_int(stack->head ? stack->head : NULL);
	ft_printf("\n");
	ft_printf("Stack tail: ");
	ft_print_int(stack->tail ? stack->tail : NULL);
	ft_printf("\n");
}

void	ft_print_both_stacks(void)
{
	ft_dlist_print(ft_global_stack_a(), ft_print_int);
	ft_printf("\n");
	ft_dlist_print(ft_global_stack_b(), ft_print_int);
	ft_printf("\n");
}

int	main(int argc, char const *argv[])
{
	if (argc < 2)
		return (0);
	ft_parse_input(ft_global_stack_a(), (char **)argv);
	ft_print_both_stacks();
	ft_print_stack_info(ft_global_stack_a());
	ft_print_stack_info(ft_global_stack_b());
	ft_print_both_stacks();
	ft_global_stacks_destroy();
	return (0);
}
