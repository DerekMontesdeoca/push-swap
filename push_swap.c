/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:15:32 by dmontesd          #+#    #+#             */
/*   Updated: 2025/06/14 19:01:17 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <assert.h>
#include "libft/libft.h"
#include "push_swap.h"
#include "intlist.h"
#include "map.h"
#include "algo.h"

static bool	fill_map(int32_t *sorted_numbers, size_t size, t_map *map)
{
	size_t				i;
	t_map_insert_return	status;

	i = 0;
	while (i < size)
	{
		status = map_insert(map, sorted_numbers[i], i);
		if (status == MAP_INSERT_FULL)
			return (false);
		++i;
	}
	return (true);
}

static void	push_swap_fill_nodes(t_push_swap *ps, int32_t *numbers)
{
	size_t	i;
	int32_t	*index;

	i = 0;
	while (i < ps->n_numbers)
	{
		index = map_lookup(&ps->indices, numbers[ps->n_numbers - 1 - i]);
		assert(index != NULL);
		intlist_node_make(&ps->nodes[i], *index);
		intlist_insert(&ps->a, &ps->nodes[i]);
		++i;
	}
}

bool	push_swap_make(t_push_swap *ps, int	*numbers, size_t size)
{
	bool	err;

	err = false;
	*ps = (t_push_swap){};
	ps->n_numbers = size;
	ps->nodes = ft_calloc(size, sizeof(t_intlist_node));
	ps->sorted_numbers = malloc(sizeof(int [size]));
	err |= !map_make(&ps->indices, size);
	err |= ps->nodes == NULL || ps->sorted_numbers == NULL;
	if (!err)
	{
		err |= !mergesort(numbers, ps->sorted_numbers, size);
		if (!err)
		{
			err |= !fill_map(ps->sorted_numbers, size, &ps->indices);
			push_swap_fill_nodes(ps, numbers);
		}
	}
	if (err)
		push_swap_destroy_contents(ps);
	return (!err);
}

void	push_swap_destroy_contents(t_push_swap *ps)
{
	free(ps->nodes);
	free(ps->sorted_numbers);
	op_vector_destroy_contents(&ps->ops);
	map_destroy_contents(&ps->indices);
	*ps = (t_push_swap){};
}
