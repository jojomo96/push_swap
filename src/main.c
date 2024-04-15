/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:36:42 by jmoritz           #+#    #+#             */
/*   Updated: 12/04/2024 04:56:31 PM jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_print_int(t_dlist_node *node)
{
	ft_printf("%d (prev: %d, next: %d)", *(int *)node->content,
		node->prev ? *(int *)node->prev->content : 0,
		node->next ? *(int *)node->next->content : 0);
}

int	main(int argc, char const *argv[])
{
	if (argc < 2)
		ft_error("To few arguments. Please provide a list of integer.");
	ft_parse_input(ft_global_stack_a(), (char **)argv);
	ft_dlist_print(ft_global_stack_a(), ft_print_int);
	ft_printf("\n");
  ft_rotate_a();
	ft_dlist_print(ft_global_stack_a(), ft_print_int);
	ft_printf("\n");
	ft_global_stacks_destroy();
	return (0);
}
