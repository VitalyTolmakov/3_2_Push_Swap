/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheidi <fheidi@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:39:30 by fheidi            #+#    #+#             */
/*   Updated: 2022/03/21 21:31:40 by fheidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sb(t_stack *stack)
{
	t_lst	*b;
	int		buff;

	if (stack->b->size > 1)
	{
		b = stack->b;
		buff = *((int *) b->first->next->content);
		*((int *) b->first->next->content) = *((int *) b->first->content);
		*((int *) b->first->content) = buff;
		ft_putstr_fd("sb\n", 1);
	}
}
