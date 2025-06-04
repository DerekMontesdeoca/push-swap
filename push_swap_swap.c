/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 02:07:13 by dmontesd          #+#    #+#             */
/*   Updated: 2025/05/29 02:14:34 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intlist.h"
#include "push_swap.h"

void	push_swap_sa(t_push_swap *ps)
{
	intlist_swap(&ps->a);
	if (ps->a.len >= 2)
		op_vector_push(&ps->ops, OP_SA);
}

void	push_swap_sb(t_push_swap *ps)
{
	intlist_swap(&ps->b);
	if (ps->b.len >= 2)
		op_vector_push(&ps->ops, OP_SA);
}

void	push_swap_ss(t_push_swap *ps)
{
	intlist_swap(&ps->a);
	intlist_swap(&ps->b);
	if (ps->a.len >= 2 || ps->b.len >= 2)
		op_vector_push(&ps->ops, OP_SS);
}
