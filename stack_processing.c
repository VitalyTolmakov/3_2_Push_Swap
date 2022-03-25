/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheidi <fheidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:56:25 by fheidi            #+#    #+#             */
/*   Updated: 2022/03/25 21:16:08 by fheidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	stack_init(void)
{
	t_stack	stack;

	stack.a = create_list();
	stack.b = create_list();
	return (stack);
}

int	stack_norm(t_lst *stack, t_index *index)
{
	t_node	*current;
	int		idx;
	int		*value;

	sort_by_index(index);
	current = stack->first;
	while (current != NULL)
	{
		idx = find_index(index, *((int *) current->content));
		value = (int *)malloc(sizeof(int));
		if (NULL == value)
			return (0);
		*value = idx;
		free(current->content);
		current->content = value;
		current = current->next;
	}
	free(index->pointer);
	return (1);
}

t_node	*create_node(void *content)
{
	t_node	*node;

	node = (t_node *) malloc(sizeof(t_node));
	if (NULL == node)
		return (NULL);
	node->content = content;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	lst_print(t_lst *lst)
{
	t_node	*current;
	int		i;

	i = 0;
	current = lst->first;
	while (current != NULL)
	{
		ft_putnbr_fd(*((int *)current->content), 1);
		write(1, " ", 1);
		current = current->next;
	}
}

void	print_stacks(t_stack *stacks)
{
	write(1, "---=== STACK STATE ===---\n", 27);
	write(1, "A : ", 5);
	lst_print(stacks->a);
	write(1, "// Size = ", 11);
	ft_putnbr_fd(stacks->a->size, 1);
	write(1, "\nB : ", 6);
	lst_print(stacks->b);
	write(1, "// Size = ", 11);
	ft_putnbr_fd(stacks->b->size, 1);
	write(1, "\n---------------------------\n", 30);
}
