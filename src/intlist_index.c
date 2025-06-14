/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intlist_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 01:38:06 by dmontesd          #+#    #+#             */
/*   Updated: 2025/06/14 19:27:28 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intlist.h"

size_t	intlist_sorted_insert_index(t_intlist *lst, int32_t value)
{
	t_intlist_node	*node;
	size_t			i;

	if (lst->len <= 1)
		return (0);
	i = 0;
	node = lst->head;
	while (i < lst->len)
	{
		if (node->data > value && node->prev->data < value)
			break ;
		if (node->data < node->prev->data
			&& (value < node->data || value > node->prev->data))
			break ;
		node = node->next;
		++i;
	}
	return (i);
}

bool	intlist_index(t_intlist *lst, int32_t value, size_t *index_out)
{
	size_t			i;
	t_intlist_node	*node;

	if (lst->len == 0)
		return (false);
	i = 0;
	node = lst->head;
	while (i < lst->len)
	{
		if (node->data == value)
		{
			*index_out = i;
			return (true);
		}
		node = node->next;
		++i;
	}
	return (false);
}

bool	intlist_is_sorted(t_intlist lst)
{
	if (lst.len <= 1)
		return (true);
	while (--lst.len)
	{
		if (lst.head->data > lst.head->next->data)
			return (false);
		lst.head = lst.head->next;
	}
	return (true);
}
