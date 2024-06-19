/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsasse <lsasse@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:07:52 by lsasse            #+#    #+#             */
/*   Updated: 2024/03/05 16:34:42 by lsasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	ft_num_check(char **args, int index)
{
	long	tmp;
	int		i;
	int		error;

	error = 0;
	i = index;
	while (args[i])
	{
		if (ft_isnum(args[i]) == 0)
			error = ft_error();
		if (error == 1)
			break ;
		tmp = ft_atoi(args[i]);
		if (ft_isnum(args[i]) == 0)
			error = ft_error();
		else if (ft_contains(tmp, args, i))
			error = ft_error();
		else if (tmp < -2147483648 || tmp > 2147483647)
			error = ft_error();
		if (error == 1)
			break ;
		i++;
	}
	return (error);
}

void	ft_check_args(int argc, char **argv)
{
	int		i;
	char	**args;
	int		error;

	error = 0;
	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	error = ft_num_check(args, i);
	if (argc == 2)
		ft_free(args);
	if (error == 1)
		exit(0);
}
