/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsasse <lsasse@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:46:43 by lsasse            #+#    #+#             */
/*   Updated: 2024/03/05 16:01:11 by lsasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ra(t_stack *a)
{
	if (a->top != NULL && a->last != NULL)
		ft_rotate(a);
	ft_append_command("ra\n", a->commands);
}

void	rb(t_stack *a, t_stack *b)
{
	if (b->top != NULL && b->last != NULL)
		ft_rotate(b);
	ft_append_command("rb\n", a->commands);
}

void	rr(t_stack *a, t_stack *b)
{
	if (b->top != NULL && b->last != NULL)
		ft_rotate(b);
	if (a->top != NULL && a->last != NULL)
		ft_rotate(a);
	ft_append_command("rr\n", a->commands);
}

void	rra(t_stack *a)
{
	if (a->top != NULL && a->last != NULL)
		ft_reverse_rotate(a);
	ft_append_command("rra\n", a->commands);
}

// void	rrb(t_stack *a, t_stack *b)
// {
// 	if (b->top != NULL && b->last != NULL)
// 		ft_reverse_rotate(b);
// 	ft_append_command("rrb\n", a->commands);
// }
// 
// void	rrr(t_stack *a, t_stack *b)
// {
// 	if (b->top != NULL && b->last != NULL)
// 		ft_reverse_rotate(b);
// 	if (a->top != NULL && a->last != NULL)
// 		ft_reverse_rotate(a);
// 	ft_append_command("rrr\n", a->commands);
// }

// void	ss(t_stack *a, t_stack *b)
// {
// 	ft_swap(a);
// 	ft_swap(b);
// 	ft_append_command("ss\n", a->commands);
// }