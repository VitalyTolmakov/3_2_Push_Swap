/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheidi <fheidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:56:15 by fheidi            #+#    #+#             */
/*   Updated: 2022/03/25 18:33:31 by fheidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

// Node Structure with Content

typedef struct s_node
{
	void			*content;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

// List Structure with Nodes

typedef struct s_lst
{
	struct s_node	*first;
	struct s_node	*last;
	unsigned int	size;
}	t_lst;

// Stack Structure with 2 Lists

typedef struct s_stack
{
	t_lst	*a;
	t_lst	*b;
}	t_stack;

// Structure for indexing with pointers and sizes

typedef struct s_index
{
	int		*pointer;
	int		size;
}	t_index;

// parse & fill

int		parse_fill(char **argv, t_stack *stacks);
int		put_error(char *str);
void	err_exit(char *str, t_stack *stacks);

// duplicate & sorting check

int		sort_checker(t_index *tab);
int		dup_checker(t_index *tab);
int		checker_result(t_lst *lst);

// lists_processing

t_lst	*create_list(void);
void	clear_list(t_lst *list, void (*del)(void*));
void	delete_node(t_lst *list, t_node *node, void (*del)(void*));
void	node_add_front(t_lst *list, void *content);
void	node_add_back(t_lst *list, void *content);

// stack_processing

t_stack	stack_init(void);
int		stack_norm(t_lst *stack, t_index *index);
t_node	*create_node(void *content);
void	lst_print(t_lst *lst);
void	print_stacks(t_stack *stacks);

// index_processing

t_index	stack_indexing(t_lst *stack);
void	sort_by_index(t_index *index);
int		find_index(t_index *index, int value);

// sorting

void	sort_small_stack(t_stack *stacks);
void	sort_big_stack(t_stack *stacks);

// Moving

void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);
void	pb(t_stack *stack);
void	pa(t_stack *stack);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);

#endif
