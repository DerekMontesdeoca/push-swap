/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 02:15:06 by dmontesd          #+#    #+#             */
/*   Updated: 2025/06/07 14:20:06 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include "intlist.h"
#include "push_swap.h"

bool	push_swap_pa(t_push_swap *ps)
{
	t_intlist_node	*node;

	if (ps->b.len > 0)
	{
		node = intlist_pop(&ps->b);
		assert(node != NULL);
		intlist_insert(&ps->a, node);
		return (op_vector_push(&ps->ops, OP_PA));
	}
	return (true);
}		

bool	push_swap_pb(t_push_swap *ps)
{
	t_intlist_node	*node;

	if (ps->a.len > 0)
	{
		node = intlist_pop(&ps->a);
		assert(node != NULL);
		intlist_insert(&ps->b, node);
		return (op_vector_push(&ps->ops, OP_PB));
	}
	return (true);
}
