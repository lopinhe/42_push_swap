/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsasse <lsasse@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:46:34 by lsasse            #+#    #+#             */
/*   Updated: 2024/03/05 17:46:19 by lsasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_optimize_pbpa(t_stack *a)
{
	t_queue	*current;
	t_queue	*temp;

	if (!a || !a->commands)
		return ;
	current = a->commands->next;
	while (current != NULL && current->next != NULL)
	{
		if ((ft_strncmp(current->instruction, "pb\n", 3) == 0
				&& ft_strncmp(current->next->instruction, "pa\n", 3) == 0)
			|| (ft_strncmp(current->instruction, "pa\n", 3) == 0
				&& ft_strncmp(current->next->instruction, "pb\n", 3) == 0))
		{
			temp = current->next;
			current = current->prev;
			ft_delete_command(current->next);
			ft_delete_command(temp);
		}
		else
			current = current->next;
	}
}

void	ft_del_repl_rarb(t_queue *current, t_queue *anchor, int count)
{
	t_queue	*temp;

	while (current != NULL && current->next != NULL)
	{
		if ((ft_strncmp(current->instruction, "ra\n", 3) == 0
				&& ft_strncmp(current->next->instruction, "rb\n", 3) == 0)
			|| (ft_strncmp(current->instruction, "rb\n", 3) == 0
				&& ft_strncmp(current->next->instruction, "ra\n", 3) == 0))
		{
			count++;
			anchor = current->prev;
			temp = current->next;
			current = current->prev;
			ft_delete_command(current->next);
			ft_delete_command(temp);
		}
		else if (count > 0)
		{
			ft_insert_command(anchor)->instruction = "rr\n";
			anchor = anchor->next;
			count--;
		}
		else
			current = current->next;
	}
}

void	ft_optimize_rarb(t_stack *a)
{
	t_queue	*current;
	t_queue	*anchor;
	int		count;

	count = 0;
	anchor = NULL;
	if (!a || !a->commands)
		return ;
	current = a->commands->next;
	ft_del_repl_rarb(current, anchor, count);
}

void	ft_optimize_queue(t_stack *a)
{
	ft_optimize_pbpa(a);
	ft_optimize_rarb(a);
}
