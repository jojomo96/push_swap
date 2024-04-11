/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:36:42 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/11 17:42:31 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_push_swap.h"

void ft_print_int(void *data)
{
	printf("%d ", *(int *)data);
}

int main(int argc, char const *argv[])
{

	if (argc < 2)
		ft_error("Error");
	ft_parse_input(ft_global_stack_a(), (char **)argv);
	ft_dlist_print(ft_global_stack_a(), ft_print_int);
	ft_global_stacks_destroy();
	return (0);
}
