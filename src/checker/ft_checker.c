/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:36:53 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/23 14:33:44 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

static void	ft_run_command(char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		ft_swap_a(0);
	else if (!ft_strcmp(line, "sb\n"))
		ft_swap_b(0);
	else if (!ft_strcmp(line, "ss\n"))
		ft_swap_s(0);
	else if (!ft_strcmp(line, "pa\n"))
		ft_push_a(0);
	else if (!ft_strcmp(line, "pb\n"))
		ft_push_b(0);
	else if (!ft_strcmp(line, "ra\n"))
		ft_rotate_a(0);
	else if (!ft_strcmp(line, "rb\n"))
		ft_rotate_b(0);
	else if (!ft_strcmp(line, "rr\n"))
		ft_rotate_r(0);
	else if (!ft_strcmp(line, "rra\n"))
		ft_rotate_reverse_a(0);
	else if (!ft_strcmp(line, "rrb\n"))
		ft_rotate_reverse_b(0);
	else if (!ft_strcmp(line, "rrr\n"))
		ft_rotate_reverse_r(0);
	else
		ft_error("Error\n");
}

int	main(int argc, char const *argv[])
{
	char	*line;

	if (argc < 2)
		return (0);
	ft_parse_input(ft_global_stack_a(), (char **)argv);
	line = get_next_line(0);
	while (line)
	{
		ft_run_command(line);
		free(line);
		line = get_next_line(0);
	}
	if (ft_is_stack_sorted(ft_global_stack_a())
		&& (ft_global_stack_b()->size == 0))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_global_stacks_destroy();
	return (0);
}
