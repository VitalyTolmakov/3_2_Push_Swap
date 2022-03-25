/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheidi <fheidi@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:38:33 by fheidi            #+#    #+#             */
/*   Updated: 2022/03/21 21:15:19 by fheidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack *stack)
{
	t_node	*next;
	int		*buff;

	if (stack->a->size > 1)
	{
		buff = malloc(sizeof(int));
		*buff = *((int *) stack->a->first->content);
		next = stack->a->first->next;
		node_add_back(stack->a, buff);
		delete_node(stack->a, stack->a->first, free);
		stack->a->first = next;
		ft_putstr_fd("ra\n", 1);
	}
}
