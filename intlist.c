/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intlist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 21:13:46 by dmontesd          #+#    #+#             */
/*   Updated: 2025/06/14 19:27:45 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "intlist.h"

void	intlist_insert(t_intlist *lst, t_intlist_node *node)
{
	if (lst->head == NULL)
	{
		lst->head = node;
		node->next = node;
		node->prev = node;
	}
	else
	{
		node->prev = lst->head->prev;
		node->next = lst->head;
		lst->head->prev->next = node;
		lst->head->prev = node;
		lst->head = node;
	}
	++lst->len;
}

t_intlist_node	*intlist_pop(t_intlist *lst)
{
	t_intlist_node	*removed;

	if (lst->head == NULL)
		return (NULL);
	if (lst->len == 1)
	{
		removed = lst->head;
		lst->head = NULL;
	}
	else
	{
		removed = lst->head;
		lst->head->next->prev = lst->head->prev;
		lst->head->prev->next = lst->head->next;
		lst->head = lst->head->next;
	}
	--lst->len;
	return (removed);
}

void	intlist_rotate(t_intlist *lst)
{
	if (lst->head != NULL)
		lst->head = lst->head->next;
}

void	intlist_rrotate(t_intlist *lst)
{
	if (lst->head != NULL)
		lst->head = lst->head->prev;
}

void	intlist_swap(t_intlist *lst)
{
	t_intlist_node	*temp;

	if (lst->len >= 2)
	{
		temp = lst->head->next;
		lst->head->next = temp->next;
		lst->head->next->prev = lst->head;
		temp->prev = lst->head->prev;
		temp->prev->next = temp;
		temp->next = lst->head;
		temp->next->prev = temp;
		lst->head = lst->head->prev;
	}
}
