/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:25:10 by dmontesd          #+#    #+#             */
/*   Updated: 2025/06/14 19:07:22 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <assert.h>
#include "solution_internal.h"
#include "algo.h"
#include "cmp.h"
#include "intlist.h"

static void	intlist_to_arr(
	t_intlist *intlist,
	int32_t *arr_out,
	size_t *size_out
) {
	size_t			i;
	t_intlist_node	*ptr;

	i = 0;
	ptr = intlist->head;
	while (i < intlist->len)
	{
		arr_out[i] = ptr->data;
		ptr = ptr->next;
		++i;
	}
	*size_out = intlist->len;
}

static bool	find_pivot(t_split_insert *si, int32_t *pivot_out)
{
	size_t	i;
	int32_t	*non_lis_arr;
	size_t	size;
	bool	ok;

	ok = false;
	size = si->numbers.size - si->lis.size;
	non_lis_arr = malloc(sizeof(int32_t[size]));
	if (non_lis_arr)
	{
		i = 0;
		size = 0;
		while (i < si->numbers.size)
		{
			if (map_lookup(&si->non_lis, si->numbers.arr[i]) != NULL)
				non_lis_arr[size++] = si->numbers.arr[i];
			++i;
		}
		quicksort(non_lis_arr, size, int32_t_lt);
		*pivot_out = non_lis_arr[size / 2];
		ok = true;
		free(non_lis_arr);
	}
	return (ok);
}

bool	push_non_lis_to_b_and_pivot_split(t_split_insert *si)
{
	size_t			i;
	int32_t			pivot;

	if (!find_pivot(si, &pivot))
		return (false);
	i = 0;
	while (i < si->numbers.size - si->lis.size)
	{
		if (map_lookup(&si->non_lis, si->push_swap->a.head->data) != NULL)
		{
			push_swap_pb(si->push_swap);
			if (si->push_swap->b.head->data < pivot)
				push_swap_rb(si->push_swap);
			++i;
		}
		else
			push_swap_ra(si->push_swap);
	}
	return (true);
}

void	split_insert_destroy(t_split_insert *si)
{
	map_destroy_contents(&si->non_lis);
	free(si->lis.arr);
	free(si->numbers.arr);
}

bool	split_insert_make(t_split_insert *si, t_push_swap *push_swap)
{
	bool	ok;

	ok = false;
	*si = (t_split_insert){};
	si->push_swap = push_swap;
	si->numbers.size = push_swap->a.len;
	si->numbers.arr = malloc(sizeof(int32_t[si->numbers.size]));
	if (si->numbers.arr != NULL)
	{
		intlist_to_arr(&push_swap->a, si->numbers.arr, &si->numbers.size);
		if (circular_lis(si->numbers.arr, si->numbers.size,
				&si->lis.arr, &si->lis.size))
		{
			ok = int_array_diff(&si->numbers, &si->lis, &si->non_lis);
			if (!ok)
				free(si->lis.arr);
		}
		if (!ok)
			free(si->numbers.arr);
	}
	return (ok);
}
