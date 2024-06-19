/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsasse <lsasse@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:00:50 by lsasse            #+#    #+#             */
/*   Updated: 2024/03/04 16:23:47 by lsasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_push(t_stack *stack, int value, int i)
{
	t_node	*newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	if (!newnode)
		return ;
	newnode->data = value;
	newnode->index = i;
	newnode->prev = newnode;
	newnode->next = newnode;
	if (stack->top == NULL && stack->last == NULL)
	{
		stack->top = newnode;
		stack->last = newnode;
	}
	else
	{
		stack->last->next = newnode;
		stack->top->prev = newnode;
		newnode->next = stack->top;
		newnode->prev = stack->last;
		stack->top = newnode;
	}
	stack->len += 1;
}

int	ft_pop(t_stack *stack)
{
	int		result;
	t_node	*temp;

	if (stack->top == NULL && stack->last == NULL)
		return (-1);
	result = stack->top->data;
	temp = stack->top;
	if (stack->top == stack->last)
	{
		stack->top = NULL;
		stack->last = NULL;
	}
	else
	{
		stack->top = stack->top->next;
		stack->top->prev = stack->last;
		stack->last->next = stack->top;
	}
	stack->len -= 1;
	free(temp);
	return (result);
}

void	ft_swap(t_stack *stack)
{
	int	temp1_val;
	int	temp2_val;
	int	temp1_index;
	int	temp2_index;

	if (stack->top == NULL || stack->last == NULL || stack->top == stack->last)
		return ;
	temp1_index = stack->top->index;
	temp1_val = ft_pop(stack);
	temp2_index = stack->top->index;
	temp2_val = ft_pop(stack);
	ft_push(stack, temp1_val, temp1_index);
	ft_push(stack, temp2_val, temp2_index);
	return ;
}

void	ft_rotate(t_stack *stack)
{
	if (stack->top == NULL || stack->last == NULL || stack->top == stack->last)
		return ;
	stack->top = stack->top->next;
	stack->last = stack->last->next;
}

void	ft_reverse_rotate(t_stack *stack)
{
	if (stack->top == NULL || stack->last == NULL || stack->top == stack->last)
		return ;
	stack->top = stack->top->prev;
	stack->last = stack->last->prev;
}
