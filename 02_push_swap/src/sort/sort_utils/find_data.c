/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsasse <lsasse@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:29:58 by lsasse            #+#    #+#             */
/*   Updated: 2024/03/05 15:45:24 by lsasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap.h"

int	ft_find_max_data(t_stack *a)
{
	int		max;
	t_node	*current;

	current = a->top->next;
	max = a->top->data;
	while (current != a->top)
	{
		if (current->data > max)
			max = current->data;
		current = current->next;
	}
	return (max);
}

int	ft_find_min_data(t_stack *a)
{
	int		min;
	t_node	*current;

	current = a->top->next;
	min = a->top->data;
	while (current != a->top)
	{
		if (current->data < min)
			min = current->data;
		current = current->next;
	}
	return (min);
}
