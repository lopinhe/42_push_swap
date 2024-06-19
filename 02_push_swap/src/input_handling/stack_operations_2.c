/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsasse <lsasse@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:21:58 by lsasse            #+#    #+#             */
/*   Updated: 2024/03/04 16:22:45 by lsasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_stack	*ft_init_stack(void)
{
	t_stack	*newstack;

	newstack = (t_stack *)malloc(sizeof(t_stack));
	if (!newstack)
		return (NULL);
	newstack->top = NULL;
	newstack->last = NULL;
	newstack->len = 0;
	newstack->commands = ft_init_queue();
	return (newstack);
}

int	ft_free_stack(t_stack *stack)
{
	while (stack->top != NULL && stack->last != NULL)
		ft_pop(stack);
	if (stack->commands != NULL)
		free(stack->commands);
	if (stack->top == NULL && stack->last == NULL)
	{
		free(stack);
		return (0);
	}
	else
		return (-1);
}
