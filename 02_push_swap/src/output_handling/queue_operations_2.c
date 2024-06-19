/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_operations_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsasse <lsasse@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:45:25 by lsasse            #+#    #+#             */
/*   Updated: 2024/03/04 18:00:03 by lsasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_print_commands(t_stack *a)
{
	t_queue	*current;

	current = a->commands->next;
	while (current->next != NULL)
	{
		ft_printf("%s", current->instruction);
		current = current->next;
	}
	ft_printf("%s", current->instruction);
}

void	ft_free_commands(t_stack *a)
{
	t_queue	*current;
	t_queue	*temp;

	if (!a || !a->commands)
		return ;
	current = a->commands->next;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		ft_delete_command(temp);
	}
}
