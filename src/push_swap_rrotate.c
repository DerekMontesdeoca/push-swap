/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rrotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 02:29:39 by dmontesd          #+#    #+#             */
/*   Updated: 2025/06/07 14:23:42 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	push_swap_rra(t_push_swap *ps)
{
	if (ps->a.len > 1)
	{
		intlist_rrotate(&ps->a);
		return (op_vector_push(&ps->ops, OP_RRA));
	}
	return (true);
}

bool	push_swap_rrb(t_push_swap *ps)
{
	if (ps->b.len > 1)
	{
		intlist_rrotate(&ps->b);
		return (op_vector_push(&ps->ops, OP_RRB));
	}
	return (true);
}

bool	push_swap_rrr(t_push_swap *ps)
{
	if (ps->a.len > 1 || ps->b.len > 1)
	{
		intlist_rrotate(&ps->a);
		intlist_rrotate(&ps->b);
		return (op_vector_push(&ps->ops, OP_RRR));
	}
	return (true);
}
