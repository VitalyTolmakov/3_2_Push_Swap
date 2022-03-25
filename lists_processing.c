/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fheidi <fheidi@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:47:11 by fheidi            #+#    #+#             */
/*   Updated: 2022/03/22 23:30:34 by fheidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*create_list(void)
{
	t_lst	*list;

	list = (t_lst *)malloc(sizeof(t_lst));
	if (list == NULL)
		return (NULL);
	list->first = NULL;
	list->last = NULL;
	list->size = 0;
	return (list);
}

void	clear_list(t_lst *list, void (*del)(void*))
{
	t_node	*current;
	t_node	*buff;

	if (list != NULL && del != NULL)
	{
		current = list->first;
		while (current != NULL)
		{
			buff = current->next;
			delete_node(list, current, del);
			current = buff;
		}
		free(list);
	}
}

void	delete_node(t_lst *list, t_node *node, void (*del)(void*))
{
	if (node != NULL)
	{
		del(node->content);
		free(node);
		list->size--;
	}
	if (list->size == 0)
	{
		list->first = NULL;
		list->last = NULL;
	}
}

void	node_add_front(t_lst *list, void *content)
{
	t_node	*node;

	node = create_node(content);
	if (list->first == NULL)
	{
		list->first = node;
		list->last = node;
	}
	else
	{
		node->next = list->first;
		list->first->prev = node;
		list->first = node;
	}
	list->size++;
}

void	node_add_back(t_lst *list, void *content)
{
	t_node	*node;

	node = create_node(content);
	if (list->first == NULL)
	{
		list->first = node;
		list->last = node;
	}
	else
	{
		node->prev = list->last;
		list->last->next = node;
		list->last = node;
	}
	list->size++;
}
