/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheidi <fheidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:37:53 by fheidi            #+#    #+#             */
/*   Updated: 2022/03/25 18:43:31 by fheidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "gnl/get_next_line.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*z1;
	unsigned char	*z2;

	z1 = (unsigned char *)s1;
	z2 = (unsigned char *)s2;
	if (*z1 == '\0')
		return (-1);
	if (*z2 == '\0')
		return (-1);
	while (*z1 != '\0' || *z2 != '\0')
	{
		if (*z1 != *z2)
			return (*z1 - *z2);
		z1++;
		z2++;
	}
	return (0);
}

int	stack_moving(char *line, t_stack *stacks)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa(stacks);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(stacks);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(stacks);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa(stacks);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(stacks);
	else if (ft_strcmp(line, "ra\n") == 0)
		ra(stacks);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(stacks);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(stacks);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra(stacks);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(stacks);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(stacks);
	else
		return (0);
	return (1);
}

void	gnl_to_stacks_and_print_oko(t_stack *stacks, unsigned int stacka_size)
{
	char	*line;
	int		invalid_cmd;

	invalid_cmd = 0;
	line = get_next_line(0);
	while (line != NULL)
	{
		if (stack_moving(line, stacks) == 0)
		{
			invalid_cmd = 1;
			break ;
		}
		free(line);
		line = get_next_line(0);
	}
	free(line);
	if (invalid_cmd == 1)
		put_error("Error\n");
	else if (checker_result(stacks->a) && stacka_size == stacks->a->size)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack	stacks;
	t_index	index;

	stacks = stack_init();
	if (argc > 1 && parse_fill(argv, &stacks))
	{
		index = stack_indexing(stacks.a);
		if (index.pointer && dup_checker(&index) && !sort_checker(&index))
		{
			gnl_to_stacks_and_print_oko(&stacks, stacks.a->size);
		}
		else
		{
			if (!sort_checker(&index))
				put_error("Error\n");
		}
		free(index.pointer);
	}
	clear_list(stacks.a, free);
	clear_list(stacks.b, free);
	return (0);
}
