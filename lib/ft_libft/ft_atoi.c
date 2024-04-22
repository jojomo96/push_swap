/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:10:16 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/22 23:20:37 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Converts a string representation of an integer to an integer value.
 *
 * @param str The string to convert.
 * @return The converted integer value.
 */
int	ft_atoi(const char *str)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (sign > 0 && result > (INT_MAX - (*str - '0')) / 10)
			return (INT_MAX);
		if (sign < 0 && result > (INT_MIN + (*str - '0')) / -10)
			return (INT_MIN);
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * sign);
}
