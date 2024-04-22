/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 00:55:15 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/22 14:08:33 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "../lib/lib.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

t_dlist	*ft_global_stack_a(void);
t_dlist	*ft_global_stack_b(void);
void	ft_global_stacks_destroy(void);

void	ft_parse_input(t_dlist *list, char **argv);
void	ft_error(char *message);
int		ft_int_cmp(void *a, void *b);

// operations
void	ft_swap_a(void);
void	ft_swap_b(void);
void	ft_swap_s(void);
void	ft_push_a(void);
void	ft_push_b(void);
void	ft_rotate_r(void);
void	ft_rotate_a(void);
void	ft_rotate_b(void);
void	ft_rotate_reverse_a(void);
void	ft_rotate_reverse_b(void);
void	ft_rotate_reverse_r(void);

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
int		ft_case_rarb(int num);
int		ft_apply_rarb(int num, int is_a_to_b);
int		ft_case_rrarrb(int num);
int		ft_apply_rrarrb(int num, int is_a_to_b);
int		ft_apply_rrarb(int num, int is_a_to_b);
int		ft_case_rrarb(int num);
int		ft_apply_rarrb(int num, int is_a_to_b);
int		ft_case_rarrb(int num);

void	ft_print_both_stacks(void);
int		ft_find_place_in_b(int num);
int		ft_find_place_in_a(int num);

#endif
