/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 02:23:14 by dmontesd          #+#    #+#             */
/*   Updated: 2025/06/07 16:09:25 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intlist.h"
#include "push_swap.h"

bool	push_swap_ra(t_push_swap *ps)
{
	if (ps->a.len > 1)
	{
		intlist_rotate(&ps->a);
		return (op_vector_push(&ps->ops, OP_RA));
	}
	return (true);
}

bool	push_swap_rb(t_push_swap *ps)
{
	if (ps->b.len > 1)
	{
		intlist_rotate(&ps->b);
		return (op_vector_push(&ps->ops, OP_RB));
	}
	return (true);
}

bool	push_swap_rr(t_push_swap *ps)
{
	if (ps->a.len > 1 || ps->b.len > 1)
	{
		intlist_rotate(&ps->a);
		intlist_rotate(&ps->b);
		return (op_vector_push(&ps->ops, OP_RR));
	}
	return (true);
}
