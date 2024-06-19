/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsasse <lsasse@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:20:51 by lsasse            #+#    #+#             */
/*   Updated: 2024/03/04 18:06:19 by lsasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_sort5(t_stack *a, t_stack *b)
{
	int	distance;

	distance = ft_get_distance(a, ft_find_min_data(a));
	if (distance == 1)
		ra(a);
	else if (distance == 2)
	{
		ra(a);
		ra(a);
	}
	else if (distance == 3)
	{
		rra(a);
		rra(a);
	}
	else if (distance == 4)
		rra(a);
	if (ft_is_sorted(a))
		return ;
	pb(a, b);
	ft_sort4(a, b);
	pa(a, b);
}

void	ft_sort4(t_stack *a, t_stack *b)
{
	int	distance;

	distance = ft_get_distance(a, ft_find_min_data(a));
	if (distance == 1)
		ra(a);
	else if (distance == 2)
	{
		ra(a);
		ra(a);
	}
	else if (distance == 3)
		rra(a);
	if (ft_is_sorted(a))
		return ;
	pb(a, b);
	ft_sort3(a);
	pa(a, b);
}

void	ft_sort3(t_stack *a)
{
	int	max_data;

	max_data = ft_find_max_data(a);
	if (max_data == a->top->data)
		ra(a);
	else if (a->top->next->data == max_data)
		rra(a);
	else if (a->top->data > a->top->next->data)
		sa(a);
	if (a->top->data != ft_find_min_data(a))
		sa(a);
}

void	ft_sort2(t_stack *a)
{
	if (a->top->data > a->last->data)
		sa(a);
}
