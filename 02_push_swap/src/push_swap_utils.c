/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsasse <lsasse@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:52:42 by lsasse            #+#    #+#             */
/*   Updated: 2024/03/05 15:41:05 by lsasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_init_stacks(t_stack **a, t_stack **b)
{
	*a = ft_init_stack();
	*b = ft_init_stack();
}

void	ft_fill_stack(t_stack *a, int value, int index)
{
	ft_push(a, value, index);
}

int	ft_arglen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
