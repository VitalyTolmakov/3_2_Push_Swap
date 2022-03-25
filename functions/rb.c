/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheidi <fheidi@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:38:43 by fheidi            #+#    #+#             */
/*   Updated: 2022/03/21 21:16:21 by fheidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	null(void *nul)
{
	(void) nul;
}

void	rb(t_stack *stack)
{
	t_node	*next;
	int		*buff;

	if (stack->b->size > 1)
	{
		buff = malloc(sizeof(int));
		*buff = *((int *) stack->b->first->content);
		next = stack->b->first->next;
		node_add_back(stack->b, buff);
		delete_node(stack->b, stack->b->first, null);
		stack->b->first = next;
		ft_putstr_fd("rb\n", 1);
	}
}
