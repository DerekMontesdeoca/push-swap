/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rrotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 02:29:39 by dmontesd          #+#    #+#             */
/*   Updated: 2025/05/31 20:56:27 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_rra(t_push_swap *ps)
{
	if (ps->a.len > 1)
	{
		intlist_rrotate(&ps->a);
		op_vector_push(&ps->ops, OP_RRA);
	}
}

void	push_swap_rrb(t_push_swap *ps)
{
	if (ps->b.len > 1)
	{
		intlist_rrotate(&ps->b);
		op_vector_push(&ps->ops, OP_RRB);
	}
}

void	push_swap_rrr(t_push_swap *ps)
{
	if (ps->a.len > 1 || ps->b.len > 1)
	{
		intlist_rrotate(&ps->a);
		intlist_rrotate(&ps->b);
		op_vector_push(&ps->ops, OP_RRR);
	}
}
