/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsasse <lsasse@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:21:18 by lsasse            #+#    #+#             */
/*   Updated: 2024/03/05 16:52:04 by lsasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/push_swap.h"

int	ft_is_sorted(t_stack *stack)
{
	t_node	*current;
	int		i;

	i = stack->len;
	current = stack->top;
	while (current != stack->last)
	{
		if (current->data < current->next->data)
			i--;
		else
			return (0);
		current = current->next;
	}
	return (1);
}

int	ft_is_rev_sorted(t_stack *stack)
{
	t_node	*current;
	int		i;

	i = stack->len;
	current = stack->top;
	while (current != stack->last)
	{
		if (current->data > current->next->data)
			i--;
		else
			return (0);
		current = current->next;
	}
	return (1);
}

int	ft_get_distance(t_stack *a, int data)
{
	int		count;
	t_node	*current;

	count = 0;
	current = a->top;
	while (current->data != data)
	{
		count++;
		current = current->next;
	}
	return (count);
}

int	ft_get_maxbits(t_stack *a)
{
	int	max_index;
	int	max_bits;

	max_index = a->len - 1;
	max_bits = 0;
	while ((max_index >> max_bits) != 0)
		++max_bits;
	return (max_bits);
}
