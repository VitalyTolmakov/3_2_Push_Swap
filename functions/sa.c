/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheidi <fheidi@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:39:21 by fheidi            #+#    #+#             */
/*   Updated: 2022/03/21 21:32:04 by fheidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack *stack)
{
	t_lst	*a;
	int		buff;

	if (stack->a->size > 1)
	{
		a = stack->a;
		buff = *((int *) a->first->next->content);
		*((int *) a->first->next->content) = *((int *) a->first->content);
		*((int *) a->first->content) = buff;
		ft_putstr_fd("sa\n", 1);
	}
}
