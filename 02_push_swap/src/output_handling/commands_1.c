/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsasse <lsasse@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:46:43 by lsasse            #+#    #+#             */
/*   Updated: 2024/03/05 16:01:10 by lsasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sa(t_stack *a)
{
	ft_swap(a);
	ft_append_command("sa\n", a->commands);
}

void	sb(t_stack *a, t_stack *b)
{
	ft_swap(b);
	ft_append_command("sb\n", a->commands);
}

void	pa(t_stack *a, t_stack *b)
{
	int	temp_val;
	int	temp_index;

	if (b->top != NULL && b->last != NULL)
	{
		temp_index = b->top->index;
		temp_val = ft_pop(b);
		ft_push(a, temp_val, temp_index);
	}
	ft_append_command("pa\n", a->commands);
}

void	pb(t_stack *a, t_stack *b)
{
	int	temp_val;
	int	temp_index;

	if (a->top != NULL && a->last != NULL)
	{
		temp_index = a->top->index;
		temp_val = ft_pop(a);
		ft_push(b, temp_val, temp_index);
	}
	ft_append_command("pb\n", a->commands);
}
