/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsasse <lsasse@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 22:23:57 by lsasse            #+#    #+#             */
/*   Updated: 2024/03/04 14:53:55 by lsasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_create_index(t_stack *a)
{
	int		i;
	int		j;
	int		ind;
	t_node	*current;
	t_node	*temp;

	i = -1;
	current = a->top;
	while (++i < a->len)
	{
		ind = 0;
		temp = current;
		j = -1;
		while (++j < a->len)
		{
			if (current->data > temp->next->data)
				ind++;
			temp = temp->next;
		}
		current->index = ind;
		current = current->next;
	}
}

void	ft_sort(t_stack *a, t_stack *b)
{
	if (a->len == 1)
		return ;
	if (ft_is_sorted(a) == 1)
		return ;
	else if (a->len == 2)
		ft_sort2(a);
	else if (a->len == 3)
		ft_sort3(a);
	else if (a->len == 4)
		ft_sort4(a, b);
	else if (a->len == 5)
		ft_sort5(a, b);
	else if (a->len > 5 && a->len < 50)
	{
		ft_create_index(a);
		ft_radixsort_small(a, b);
	}
	else if (a->len >= 50)
	{
		ft_create_index(a);
		ft_radixsort_big(a, b);
	}
}
