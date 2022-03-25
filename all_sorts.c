/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_sorts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheidi <fheidi@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:40:43 by fheidi            #+#    #+#             */
/*   Updated: 2022/03/23 22:57:33 by fheidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3_stack(t_stack *stacks)
{
	int		first;
	int		second;
	int		third;

	first = *((int *) stacks->a->first->content);
	second = *((int *) stacks->a->first->next->content);
	third = *((int *) stacks->a->last->content);
	if (first > second && second < third && first < third)
		sa(stacks);
	else if (first > second && second > third)
	{
		sa(stacks);
		rra(stacks);
	}
	else if (first < second && second > third && first < third)
	{
		sa(stacks);
		ra(stacks);
	}
	else if (first > second && second < third && first > third)
		ra(stacks);
	else if (first < second && second > third && first > third)
		rra(stacks);
}

static void	sort_4_5(t_stack *stacks, int median)
{
	int		pb_count;
	t_lst	*a;
	t_lst	*b;

	a = stacks->a;
	b = stacks->b;
	pb_count = 0;
	while (pb_count < median)
	{
		if (*((int *) a->first->content) < median)
		{
			pb(stacks);
			pb_count++;
		}
		else
			rra(stacks);
	}
	sort_3_stack(stacks);
	if (median > 1)
	{
		if (*((int *) b->first->content) < *((int *) b->last->content))
			sb(stacks);
		pa(stacks);
	}
	pa(stacks);
}

void	sort_small_stack(t_stack *stacks)
{
	int		first;
	int		last;

	first = *((int *) stacks->a->first->content);
	last = *((int *) stacks->a->last->content);
	if (stacks->a->size == 2 && first > last)
		ra(stacks);
	else if (stacks->a->size == 3)
		sort_3_stack(stacks);
	else if (stacks->a->size == 4)
		sort_4_5(stacks, 1);
	else if (stacks->a->size == 5)
		sort_4_5(stacks, 2);
}

void	sort_big_stack(t_stack *stacks)
{
	int		size;
	int		max_bits;
	int		top;
	int		i;
	int		j;

	size = stacks->a->size;
	max_bits = 0;
	while ((size - 1) >> max_bits != 0)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			top = *((int *) stacks->a->first->content);
			if (((top >> i) & 1) == 1)
				ra(stacks);
			else
				pb(stacks);
		}
		while (stacks->b->first != NULL)
			pa(stacks);
	}
}
