/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheidi <fheidi@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:38:07 by fheidi            #+#    #+#             */
/*   Updated: 2022/03/21 21:27:18 by fheidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack *stack)
{
	t_node	*node;
	int		*buff;

	if (stack->b->size > 0)
	{
		buff = malloc(sizeof(int));
		*buff = *((int *) stack->b->first->content);
		node_add_front(stack->a, buff);
		node = stack->b->first->next;
		delete_node(stack->b, stack->b->first, free);
		stack->b->first = node;
		ft_putstr_fd("pa\n", 1);
	}
}
