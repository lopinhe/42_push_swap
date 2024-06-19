/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsasse <lsasse@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:29:17 by lsasse            #+#    #+#             */
/*   Updated: 2024/03/04 16:10:18 by lsasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap.h"

int	ft_find_max_index(t_stack *a)
{
	int		max;
	t_node	*current;

	current = a->top->next;
	max = a->top->index;
	while (current != a->top)
	{
		if (current->index > max)
			max = current->index;
		current = current->next;
	}
	return (max);
}

int	ft_find_min_index(t_stack *a)
{
	int		min;
	t_node	*current;

	current = a->top->next;
	min = a->top->index;
	while (current != a->top)
	{
		if (current->index > min)
			min = current->index;
		current = current->next;
	}
	return (min);
}
