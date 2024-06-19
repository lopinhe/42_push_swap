/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_operations_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsasse <lsasse@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:45:25 by lsasse            #+#    #+#             */
/*   Updated: 2024/03/04 18:22:06 by lsasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_queue	*ft_init_queue(void)
{
	t_queue	*newqueue;

	newqueue = (t_queue *)malloc(sizeof(t_queue));
	if (!newqueue)
		return (NULL);
	newqueue->prev = NULL;
	newqueue->next = NULL;
	return (newqueue);
}

void	ft_delete_command(t_queue *q)
{
	t_queue	*temp;

	if (q->next != NULL)
	{
		temp = q;
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
	}
	else if (q->prev != NULL)
		q->prev->next = NULL;
	free(q);
}

t_queue	*ft_insert_command(t_queue *q)
{
	t_queue	*newcommand;

	if (!q)
		return (NULL);
	newcommand = (t_queue *)malloc(sizeof(t_queue));
	if (!newcommand)
		return (NULL);
	newcommand->next = q->next;
	newcommand->prev = q;
	if (q->next)
		q->next->prev = newcommand;
	q->next = newcommand;
	return (newcommand);
}

t_queue	*ft_create_command(t_queue *q)
{
	t_queue	*newcommand;

	newcommand = (t_queue *)malloc(sizeof(t_queue));
	if (!newcommand)
		return (NULL);
	q->next = newcommand;
	newcommand->prev = q;
	newcommand->next = NULL;
	return (newcommand);
}

void	ft_append_command(char *str, t_queue *q)
{
	t_queue	*current;

	if (q == NULL)
		q = ft_init_queue();
	current = q;
	while (current->next != NULL)
		current = current->next;
	current = ft_create_command(current);
	current->instruction = str;
}
