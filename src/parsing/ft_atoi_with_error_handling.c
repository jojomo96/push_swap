/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_with_error_handling.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:39:12 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/23 00:15:32 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

static void	ft_set_error(int *error, int value)
{
	*error = value;
}

static void	ft_extract_number(const char *str, int *error, int *sign,
		long *result)
{
	while (*str >= '0' && *str <= '9')
	{
		*result = (*result * 10) + (*str - '0');
		if (*result * *sign > INT_MAX)
			ft_set_error(error, -1);
		if (*result * *sign < INT_MIN)
			ft_set_error(error, -1);
		str++;
	}
}

int	ft_atoi_with_error(const char *str, int *error)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	ft_set_error(error, 0);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
		if (!(*str >= '0' && *str <= '9'))
		{
			ft_set_error(error, -1);
			return (0);
		}
	}
	ft_extract_number(str, error, &sign, &result);
	return (result * sign);
}
