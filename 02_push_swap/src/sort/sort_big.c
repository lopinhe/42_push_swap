/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsasse <lsasse@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:33:27 by lsasse            #+#    #+#             */
/*   Updated: 2024/03/05 17:13:24 by lsasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_radix_stack_a(t_stack *a, t_stack *b, int i)
{
	int	num_a;

	num_a = a->top->index;
	if ((((num_a >> i) & 1) == 1))
		ra(a);
	else
		pb(a, b);
}

void	ft_radix_stack_b(t_stack *a, t_stack *b, int i, int max_bits)
{
	int	num_b;

	num_b = b->top->index;
	if ((((num_b >> (i + 1)) & 1) == 1) && (i + 1) < max_bits)
		pa(a, b);
	else
		rb(a, b);
}

void	ft_radixsort_small(t_stack *a, t_stack *b)
{
	int	i;
	int	size;
	int	round;
	int	max_bits;

	i = -1;
	size = a->len;
	max_bits = ft_get_maxbits(a);
	while (++i <= max_bits)
	{
		round = 0;
		while (++round <= size)
			ft_radix_stack_a(a, b, i);
		while (b->len > 0)
			pa(a, b);
		if (ft_is_sorted(a) == 1 && b->len == 0)
			break ;
	}
}

void	ft_radixsort_big(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	i;
	int	round;

	i = 0;
	max_bits = ft_get_maxbits(a);
	while (i < max_bits)
	{
		round = a->len +1;
		while (--round > 0)
			ft_radix_stack_a(a, b, i);
		if (ft_is_sorted(a) == 1 && ft_is_rev_sorted(b) == 1)
			break ;
		round = b->len + 1;
		while (--round > 0)
			ft_radix_stack_b(a, b, i, max_bits);
		i++;
	}
	while (b->len > 0)
		pa(a, b);
}
