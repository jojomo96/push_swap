/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 00:55:15 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/23 14:20:17 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "../lib/lib.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define DEBUG 0

t_dlist	*ft_global_stack_a(void);
t_dlist	*ft_global_stack_b(void);
void	ft_global_stacks_destroy(void);

void	ft_parse_input(t_dlist *list, char **argv);
void	ft_error(char *message);
int		ft_int_cmp(void *a, void *b);

// operations
void	ft_swap_a(int print);
void	ft_swap_b(int print);
void	ft_swap_s(int print);
void	ft_push_a(int print);
void	ft_push_b(int print);
void	ft_rotate_r(int print);
void	ft_rotate_a(int print);
void	ft_rotate_b(int print);
void	ft_rotate_reverse_a(int print);
void	ft_rotate_reverse_b(int print);
void	ft_rotate_reverse_r(int print);

// sorting
void	ft_sort(void);
int		ft_is_new_min(t_dlist *stack, int num);
int		ft_get_index_of_min(t_dlist *stack);
int		ft_is_new_max(t_dlist *stack, int num);
int		ft_get_index_of_max(t_dlist *stack);
int		ft_is_stack_sorted(t_dlist *stack);

int		ft_get_index_in_a(int num);
int		ft_get_index_in_b(int num);

// cases
int		ft_case_rarb(int num, int is_a_to_b);
int		ft_apply_rarb(int num, int is_a_to_b);
int		ft_case_rrarrb(int num, int is_a_to_b);
int		ft_apply_rrarrb(int num, int is_a_to_b);
int		ft_apply_rrarb(int num, int is_a_to_b);
int		ft_case_rrarb(int num, int is_a_to_b);
int		ft_apply_rarrb(int num, int is_a_to_b);
int		ft_case_rarrb(int num, int is_a_to_b);

t_dlist	*ft_get_corresponding_stack(int is_a_to_b);
int		ft_find_place_in_b(int num);
int		ft_find_place_in_a(int num);
int		ft_atoi_with_error(const char *str, int *error);

#endif
