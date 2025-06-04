/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 02:23:14 by dmontesd          #+#    #+#             */
/*   Updated: 2025/05/31 20:56:45 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intlist.h"
#include "push_swap.h"

void	push_swap_ra(t_push_swap *ps)
{
	if (ps->a.len > 1)
	{
		intlist_rotate(&ps->a);
		op_vector_push(&ps->ops, OP_RA);
	}
}

void	push_swap_rb(t_push_swap *ps)
{
	if (ps->b.len > 1)
	{
		intlist_rotate(&ps->b);
		op_vector_push(&ps->ops, OP_RB);
	}
}

void	push_swap_rr(t_push_swap *ps)
{
	if (ps->a.len > 1 || ps->b.len > 1)
	{
		intlist_rotate(&ps->a);
		intlist_rotate(&ps->b);
		op_vector_push(&ps->ops, OP_RR);
	}
}
