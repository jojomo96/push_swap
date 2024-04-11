/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 00:55:15 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/11 14:43:36 by jmoritz          ###   ########.fr       */
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

#endif
