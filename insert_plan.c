/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_plan.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 21:06:09 by dmontesd          #+#    #+#             */
/*   Updated: 2025/06/14 19:28:57 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include "solution_internal.h"

static t_insert_plan	calculate_insert_plan(
	size_t index_a,
	size_t len_a,
	size_t index_b,
	size_t len_b
) {
	t_insert_plan					insert_plan;
	t_circular_distances			distances_a;
	t_circular_distances			distances_b;
	t_distance_combination_index	combination_type;

	distances_a = circular_distances(index_a, len_a);
	distances_b = circular_distances(index_b, len_b);
	combination_type = min_distance_combination(&distances_a, &distances_b);
	if (combination_type == DISTANCE_COMBINATION_INDEX_A_DOWN_B_UP)
		insert_plan_make_a_down_b_up(&insert_plan, &distances_a, &distances_b);
	else if (combination_type == DISTANCE_COMBINATION_INDEX_A_UP_B_DOWN)
		insert_plan_make_a_up_b_down(&insert_plan, &distances_a, &distances_b);
	else if (combination_type == DISTANCE_COMBINATION_INDEX_BOTH_UP)
		insert_plan_make_both_up(&insert_plan, &distances_a, &distances_b);
	else if (combination_type == DISTANCE_COMBINATION_INDEX_BOTH_DOWN)
		insert_plan_make_both_down(&insert_plan, &distances_a, &distances_b);
	else
		assert(false && "Unreachable code");
	return (insert_plan);
}

void	insert_plan_make(t_insert_plan *ip, t_push_swap *push_swap)
{
	size_t			i;
	t_intlist_node	*node_b;
	t_insert_plan	current_plan;
	size_t			insert_index_a;

	i = 0;
	node_b = push_swap->b.head;
	while (i < push_swap->b.len)
	{
		insert_index_a = intlist_sorted_insert_index(
				&push_swap->a,
				node_b->data
				);
		current_plan = calculate_insert_plan(
				insert_index_a,
				push_swap->a.len,
				i,
				push_swap->b.len
				);
		if (i == 0 || insert_plan_moves(&current_plan) < insert_plan_moves(ip))
			*ip = current_plan;
		node_b = node_b->next;
		++i;
	}
}

size_t	insert_plan_moves(t_insert_plan *ip)
{
	return (ip->pa + ip->ra + ip->rb + ip->rra + ip->rrb + ip->rr + ip->rrr);
}
