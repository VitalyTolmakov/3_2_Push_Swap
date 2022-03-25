/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheidi <fheidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:55:57 by fheidi            #+#    #+#             */
/*   Updated: 2022/03/25 18:33:14 by fheidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stacks;
	t_index	index;

	stacks = stack_init();
	if (argc > 1 && parse_fill(argv, &stacks))
	{
		index = stack_indexing(stacks.a);
		if (index.pointer && dup_checker(&index) && !sort_checker(&index)
			&& stack_norm(stacks.a, &index))
		{
			if (stacks.a->size > 5)
				sort_big_stack(&stacks);
			else
				sort_small_stack(&stacks);
		}
		else
		{
			if (!sort_checker(&index))
				put_error("Error\n");
			free(index.pointer);
		}
	}
	clear_list(stacks.a, free);
	clear_list(stacks.b, free);
	return (0);
}
