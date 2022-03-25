/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheidi <fheidi@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:44:41 by fheidi            #+#    #+#             */
/*   Updated: 2022/03/22 23:28:58 by fheidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Transform integer list to index list

t_index	stack_indexing(t_lst *stack)
{
	t_node	*current;
	t_index	index;
	size_t	i;

	i = 0;
	index.pointer = (int *) malloc(stack->size * sizeof(int));
	index.size = stack->size;
	current = stack->first;
	while (current != NULL)
	{
		index.pointer[i++] = *((int *) current->content);
		current = current->next;
	}
	return (index);
}

// Sorting by index

void	sort_by_index(t_index *index)
{
	int		current;
	int		buff;
	int		min;
	int		i;

	current = 0;
	while (current < index->size)
	{
		i = current;
		min = i;
		while (i < index->size)
		{
			if (index->pointer[i] < index->pointer[min])
				min = i;
			i++;
		}
		buff = index->pointer[current];
		index->pointer[current] = index->pointer[min];
		index->pointer[min] = buff;
		current++;
	}
}

// Search by index (in sorted list)

int	find_index(t_index *index, int number)
{
	int	i;

	i = 0;
	while (i < index->size)
	{
		if (index->pointer[i] == number)
			return (i);
		else
			i++;
	}
	return (0);
}
