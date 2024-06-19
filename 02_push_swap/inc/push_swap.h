/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsasse <lsasse@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:51:12 by lsasse            #+#    #+#             */
/*   Updated: 2024/03/05 17:44:19 by lsasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_queue
{
	char			*instruction;
	struct s_queue	*next;
	struct s_queue	*prev;
}	t_queue;

typedef struct s_stack
{
	t_node		*top;
	t_node		*last;
	t_queue		*commands;
	int			len;
}	t_stack;

//stack operations
t_stack	*ft_init_stack(void);
int		ft_free_stack(t_stack *stack);
void	ft_push(t_stack *stack, int value, int index);
int		ft_pop(t_stack *stack);
void	ft_swap(t_stack *stack);
void	ft_rotate(t_stack *stack);
void	ft_reverse_rotate(t_stack *stack);

//queue oerations
t_queue	*ft_init_queue(void);
void	ft_delete_command(t_queue *q);
t_queue	*ft_create_command(t_queue *q);
void	ft_append_command(char *str, t_queue *q);
t_queue	*ft_insert_command(t_queue *q);
void	ft_print_commands(t_stack *a);
void	ft_optimize_queue(t_stack *a);
void	ft_del_repl_rarb(t_queue *current, t_queue *anchor, int count);
void	ft_free_commands(t_stack *a);

//push_swap commands
void	sa(t_stack *a);
void	sb(t_stack *a, t_stack *b);
//void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
//void	rrb(t_stack *a, t_stack *b);
//void	rrr(t_stack *a, t_stack *b);

//push_swap main utils
void	ft_init_stacks(t_stack **a, t_stack **b);
void	ft_fill_stack(t_stack *a, int value, int index);
int		ft_arglen(char **str);

//argument checking
void	ft_check_args(int argc, char **argv);
int		ft_isnum(char *num);
int		ft_contains(int num, char **argv, int i);
void	ft_free(char **str);
int		ft_error(void);

//sorting utils
void	ft_create_index(t_stack *a);
int		ft_is_sorted(t_stack *stack);
int		ft_is_rev_sorted(t_stack *stack);
int		ft_find_min_data(t_stack *a);
int		ft_find_max_data(t_stack *a);
int		ft_get_distance(t_stack *a, int data);
int		ft_get_maxbits(t_stack *a);

//sorting algorithms
void	ft_sort(t_stack *a, t_stack *b);
void	ft_sort2(t_stack *a);
void	ft_sort3(t_stack *a);
void	ft_sort4(t_stack *a, t_stack *b);
void	ft_sort5(t_stack *a, t_stack *b);
void	ft_radixsort_small(t_stack *a, t_stack *b);
void	ft_radixsort_big(t_stack *a, t_stack *b);

#endif
