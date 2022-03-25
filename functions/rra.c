/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheidi <fheidi@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:38:57 by fheidi            #+#    #+#             */
/*   Updated: 2022/03/21 21:22:13 by fheidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack *stack)
{
	t_node	*node;
	int		*buff;

	if (stack->a->size > 1)
	{
		buff = malloc(sizeof(int));
		*buff = *((int *) stack->a->last->content);
		node = stack->a->last->prev;
		node->next = NULL;
		node_add_front(stack->a, buff);
		delete_node(stack->a, stack->a->last, free);
		stack->a->last = node;
		ft_putstr_fd("rra\n", 1);
	}
}
