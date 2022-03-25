/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheidi <fheidi@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:39:07 by fheidi            #+#    #+#             */
/*   Updated: 2022/03/21 21:27:32 by fheidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrb(t_stack *stack)
{
	t_node	*node;
	int		*buff;

	if (stack->b->size > 1)
	{
		buff = malloc(sizeof(int));
		*buff = *((int *) stack->b->last->content);
		node_add_front(stack->b, buff);
		node = stack->b->last->prev;
		node->next = NULL;
		delete_node(stack->b, stack->b->last, free);
		stack->b->last = node;
		ft_putstr_fd("rrb\n", 1);
	}
}
