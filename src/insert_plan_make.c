/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_plan_make.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 01:46:53 by dmontesd          #+#    #+#             */
/*   Updated: 2025/06/13 14:47:06 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solution_internal.h"

void	insert_plan_make_a_up_b_down(
	t_insert_plan *ip,
	t_circular_distances *a,
	t_circular_distances *b
) {
	*ip = (t_insert_plan){};
	ip->pa = 1;
	ip->ra = a->up;
	ip->rrb = b->down;
}

void	insert_plan_make_a_down_b_up(
	t_insert_plan *ip,
	t_circular_distances *a,
	t_circular_distances *b
) {
	*ip = (t_insert_plan){};
	ip->pa = 1;
	ip->rra = a->down;
	ip->rb = b->up;
}

void	insert_plan_make_both_up(
	t_insert_plan *ip,
	t_circular_distances *a,
	t_circular_distances *b
) {
	*ip = (t_insert_plan){};
	ip->pa = 1;
	if (a->up < b->up)
	{
		ip->rr = a->up;
		ip->rb = b->up - a->up;
	}
	else
	{
		ip->rr = b->up;
		ip->ra = a->up - b->up;
	}
}

void	insert_plan_make_both_down(
	t_insert_plan *ip,
	t_circular_distances *a,
	t_circular_distances *b
) {
	*ip = (t_insert_plan){};
	ip->pa = 1;
	if (a->down < b->down)
	{
		ip->rrr = a->down;
		ip->rrb = b->down - a->down;
	}
	else
	{
		ip->rrr = b->down;
		ip->rra = a->down - b->down;
	}
}
