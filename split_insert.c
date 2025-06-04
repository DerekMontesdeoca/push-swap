/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:25:10 by dmontesd          #+#    #+#             */
/*   Updated: 2025/06/03 05:10:56 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <assert.h>
#include "split_insert.h"
#include "algo.h"
#include "cmp.h"

static int	lt(int32_t a, int32_t b)
{
	if (a < b)
		return (-1);
	if (a > b)
		return (1);
	return (0);
}

static void intlist_to_arr(
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
			{
				non_lis_arr[size++] = si->numbers.arr[i];
			}
			++i;
		}
		quicksort(non_lis_arr, size, lt);
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

t_distance_combination_index min_distance_combination(
	t_circular_distances *distances_a,
	t_circular_distances *distances_b
) {
	union u_distance_combinations	distance_combinations;

	distance_combinations.as_struct.both_up = *(size_t *)max(
		(size_t []){distances_a->up, distances_b->up},
		2, sizeof(distances_a->up), size_t_cmp
	);
	distance_combinations.as_struct.both_down = *(size_t *)max(
		(size_t []){distances_a->down, distances_b->down},
		2, sizeof(distances_a->down), size_t_cmp
	);
	distance_combinations.as_struct.a_down_b_up =
		distances_a->down + distances_b->up;
	distance_combinations.as_struct.a_up_b_down =
		distances_a->up + distances_b->down;
	return (min_index(
		distance_combinations.as_array, 
		sizeof(distance_combinations.as_array) 
			/ sizeof(distance_combinations.as_array[0]),
		sizeof(distance_combinations.as_array[0]),
		size_t_cmp
	));
}

t_circular_distances circular_distances(size_t index, size_t len)
{
	t_circular_distances	distances;

	distances.up = index;
	distances.down = len - index;
	return (distances);
}

void	make_a_up_b_down(
		t_insert_plan *ip,
		t_circular_distances *a,
		t_circular_distances *b
) {
	*ip = (t_insert_plan){};
	ip->pb = 1;
	ip->ra = a->up;
	ip->rrb = b->down;
}

void	make_a_down_b_up(
		t_insert_plan *ip,
		t_circular_distances *a,
		t_circular_distances *b
) {
	*ip = (t_insert_plan){};
	ip->pb = 1;
	ip->rra = a->down;
	ip->rb = b->up;
}

void	make_both_up(
		t_insert_plan *ip,
		t_circular_distances *a,
		t_circular_distances *b
) {
	*ip = (t_insert_plan){};
	ip->pb = 1;
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

void	make_both_down(
		t_insert_plan *ip,
		t_circular_distances *a,
		t_circular_distances *b
) {
	*ip = (t_insert_plan){};
	ip->pb = 1;
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

t_insert_plan calculate_insert_plan(
		size_t index_a,
		size_t len_a,
		size_t index_b,
		size_t len_b
) {
	t_insert_plan					insert_plan;
	t_circular_distances 			distances_a;
	t_circular_distances			distances_b;
	t_distance_combination_index	combination_type;

	distances_a = circular_distances(index_a, len_a);
	distances_b = circular_distances(index_b, len_b);
	combination_type = min_distance_combination(&distances_a, &distances_b);
	if (combination_type == DISTANCE_COMBINATION_INDEX_A_DOWN_B_UP)
		make_a_down_b_up(&insert_plan, &distances_a, &distances_b);
	else if (combination_type == DISTANCE_COMBINATION_INDEX_A_UP_B_DOWN)
		make_a_up_b_down(&insert_plan, &distances_a, &distances_b);
	else if (combination_type == DISTANCE_COMBINATION_INDEX_BOTH_UP)
		make_both_up(&insert_plan, &distances_a, &distances_b);
	else if (combination_type == DISTANCE_COMBINATION_INDEX_BOTH_DOWN)
		make_both_down(&insert_plan, &distances_a, &distances_b);
	else
		assert(false && "Unreachable code");
	return (insert_plan);
}

size_t	get_insert_index(t_intlist *lst, int32_t value)
{
	t_intlist_node	*node;
	size_t			i;

	if (lst->len <= 1)
		return (0);
	i = 0;
	node = lst->head;
	while (i < lst->len)
	{
		if (node->data > value && node->prev->data < value)
			break;
		if (node->data < node->prev->data
				&& (value < node->data || value > node->prev->data))
			break;
		node = node->next;
		++i;
	}
	return (i);
}

size_t	insert_plan_moves(t_insert_plan *ip)
{
	return (ip->pb + ip->ra + ip->rb + ip->rra + ip->rrb + ip->rr + ip->rrr);
}

void	make_insert_plan(t_insert_plan *ip, t_split_insert *split_insert)
{
	size_t			i;
	t_intlist_node	*node;
	t_insert_plan	current_plan;
	size_t			insert_index_b;

	i = 0;
	node = split_insert->push_swap->b.head;
	while (i < split_insert->push_swap->b.len)
	{
		insert_index_b = get_insert_index(
				&split_insert->push_swap->a, node->data);
		current_plan = calculate_insert_plan(
				i, split_insert->push_swap->a.len,
				insert_index_b, split_insert->push_swap->b.len);
		if (i == 0 || insert_plan_moves(&current_plan) < insert_plan_moves(ip))
			*ip = current_plan;
		node = node->next;
		++i;
	}
}

void	insert_sort_execute_plan(t_split_insert *si, t_insert_plan insert_plan)
{
	while (insert_plan.ra--)
		push_swap_ra(si->push_swap);
	while (insert_plan.rb--)
		push_swap_rb(si->push_swap);
	while (insert_plan.rra--)
		push_swap_rra(si->push_swap);
	while(insert_plan.rrb--)
		push_swap_rrb(si->push_swap);
	while(insert_plan.rr--)
		push_swap_rr(si->push_swap);
	while(insert_plan.rrr--)
		push_swap_rrr(si->push_swap);
	while(insert_plan.pb--)
		push_swap_pb(si->push_swap);
}

void	insert_sort_to_a(t_split_insert *si)
{
	t_insert_plan	insert_plan;

	while (si->push_swap->b.len > 0)
	{
		make_insert_plan(&insert_plan, si);
		insert_sort_execute_plan(si, insert_plan);
	}
}
