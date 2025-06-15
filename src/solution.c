/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 01:29:40 by dmontesd          #+#    #+#             */
/*   Updated: 2025/06/15 19:53:09 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solution.h"
#include "array.h"
#include "push_swap.h"
#include "solution_internal.h"

static void	push_zero_to_top(t_split_insert *si)
{
	size_t					index;
	t_circular_distances	distances;

	intlist_index(&si->push_swap->a, 0, &index);
	distances = circular_distances(index, si->push_swap->a.len);
	if (distances.up <= distances.down)
		while (distances.up--)
			push_swap_ra(si->push_swap);
	else
		while (distances.down--)
			push_swap_rra(si->push_swap);
}

bool	split_then_insert(t_push_swap *ps)
{
	t_split_insert	split_insert;
	bool			ok;

	ok = false;
	if (split_insert_make(&split_insert, ps))
	{
		if (split_insert.lis.size != split_insert.numbers.size)
		{
			push_non_lis_to_b_and_pivot_split(&split_insert);
			insert_sort_to_a(&split_insert);
		}
		push_zero_to_top(&split_insert);
		split_insert_destroy(&split_insert);
		ok = true;
	}
	return (ok);
}
