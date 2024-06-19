/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsasse <lsasse@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:23:08 by lsasse            #+#    #+#             */
/*   Updated: 2024/03/04 13:52:12 by lsasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str)
{
	long	i;
	long	number;
	int		sign;

	i = 0;
	number = 0;
	sign = 1;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + (str[i] - '0');
		i++;
	}
	return (number * sign);
}

// int	ft_atoi(const char *str)
// {
// 	int			i;
// 	int			sign;
// 	long long	res;

// 	i = 0;
// 	sign = 1;
// 	res = 0;
// 	while (str[i] == ' ' || ((9 <= str[i]) && (str[i] <= 13)))
// 		i++;
// 	if (str[i] == '+')
// 		i++;
// 	else if (str[i] == '-')
// 	{
// 		sign = -1;
// 		i++;
// 	}
// 	while (str[i] && ('0' <= str[i]) && (str[i] <= '9'))
// 	{
// 		res = (res * 10) + (str[i] - '0');
// 		i++;
// 	}
// 	return (sign * res);
// }
