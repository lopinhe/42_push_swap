/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsasse <lsasse@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:56:46 by lsasse            #+#    #+#             */
/*   Updated: 2024/03/05 17:39:02 by lsasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	**ft_get_param(int argc, char **argv)
{
	char	**argtemp;

	argtemp = NULL;
	if (argc == 2)
		argtemp = ft_split(argv[1], ' ');
	else
		argtemp = argv;
	if (!argtemp)
		exit (0);
	return (argtemp);
}

void	ft_stack_param(t_stack *a, t_stack *b, char **argtemp, char **argv)
{
	int	i;

	i = ft_arglen(argtemp);
	while (--i > 0)
		ft_fill_stack(a, ft_atoi(argtemp[i]), 0);
	if (argtemp != argv)
		ft_fill_stack(a, ft_atoi(argtemp[0]), 0);
	if (ft_is_sorted(a) == 1)
	{
		ft_free_stack(a);
		ft_free_stack(b);
		if (argtemp != argv)
			ft_free(argtemp);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**argtemp;

	if (argc < 2)
		exit(0);
	ft_check_args(argc, argv);
	argtemp = ft_get_param(argc, argv);
	ft_init_stacks(&a, &b);
	ft_stack_param(a, b, argtemp, argv);
	ft_sort(a, b);
	ft_optimize_queue(a);
	ft_print_commands(a);
	ft_free_commands(a);
	if (argtemp != argv)
		ft_free(argtemp);
	ft_free_stack(a);
	ft_free_stack(b);
	return (0);
}
