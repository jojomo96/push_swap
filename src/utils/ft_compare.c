/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:45:39 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/16 09:45:45 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int	ft_int_cmp(void *a, void *b)
{
	return (*(int *)a - *(int *)b);
}
