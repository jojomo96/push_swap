/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:36:42 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/23 00:09:57 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char const *argv[])
{
	if (argc < 2)
		return (0);
	ft_parse_input(ft_global_stack_a(), (char **)argv);
	if (!ft_is_stack_sorted(ft_global_stack_a()))
		ft_sort();
	ft_global_stacks_destroy();
	return (0);
}
