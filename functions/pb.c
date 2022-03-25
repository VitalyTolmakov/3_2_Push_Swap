/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheidi <fheidi@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:38:24 by fheidi            #+#    #+#             */
/*   Updated: 2022/03/21 21:26:36 by fheidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pb(t_stack *stack)
{
	t_node	*node;
	int		*buff;

	if (stack->a->size > 0)
	{
		buff = malloc(sizeof(int));
		*buff = *((int *) stack->a->first->content);
		node_add_front(stack->b, buff);
		node = stack->a->first->next;
		delete_node(stack->a, stack->a->first, free);
		stack->a->first = node;
		ft_putstr_fd("pb\n", 1);
	}
}
