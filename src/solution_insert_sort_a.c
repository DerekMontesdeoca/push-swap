/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_insert_sort_a.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 19:04:58 by dmontesd          #+#    #+#             */
/*   Updated: 2025/06/15 19:52:37 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solution_internal.h"

static void	insert_sort_execute_plan(
	t_split_insert *si,
	t_insert_plan insert_plan
) {
	while (insert_plan.ra--)
		push_swap_ra(si->push_swap);
	while (insert_plan.rb--)
		push_swap_rb(si->push_swap);
	while (insert_plan.rra--)
		push_swap_rra(si->push_swap);
	while (insert_plan.rrb--)
		push_swap_rrb(si->push_swap);
	while (insert_plan.rr--)
		push_swap_rr(si->push_swap);
	while (insert_plan.rrr--)
		push_swap_rrr(si->push_swap);
	while (insert_plan.pa--)
		push_swap_pa(si->push_swap);
}

void	insert_sort_to_a(t_split_insert *si)
{
	t_insert_plan	insert_plan;

	while (si->push_swap->b.len > 0)
	{
		insert_plan_make(&insert_plan, si->push_swap);
		insert_sort_execute_plan(si, insert_plan);
	}
}
