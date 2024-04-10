/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 00:55:15 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/10 13:42:53 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(FT_PUSH_SWAP_H)
#define FT_PUSH_SWAP_H

#ifndef UNISTD_H
# include <unistd.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

#endif