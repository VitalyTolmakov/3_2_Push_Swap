/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheidi <fheidi@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:41:44 by fheidi            #+#    #+#             */
/*   Updated: 2022/03/23 23:34:38 by fheidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	put_error(char *str)
{
	ft_putstr_fd(str, 1);
	return (0);
}

int	dup_checker(t_index *tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < tab->size)
	{
		j = i + 1;
		while (j < tab->size)
		{
			if (tab->pointer[i] == tab->pointer[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	sort_checker(t_index *tab)
{
	int	i;

	i = 0;
	while (i + 1 < tab->size)
	{
		if (tab->pointer[i] > tab->pointer[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	checker_result(t_lst *lst)
{
	t_node	*current;
	int		i;

	i = 0;
	current = lst->first;
	while (current != NULL && current->next != NULL)
	{
		if (*((int *)current->content) > *((int *)current->next->content))
			return (0);
		current = current->next;
	}
	return (1);
}
