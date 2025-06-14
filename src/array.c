/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:30:25 by dmontesd          #+#    #+#             */
/*   Updated: 2025/06/14 19:43:21 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "array.h"
#include "map.h"

static bool	fill_map(t_map *map, t_int_array *arr);
static void	subtract( t_int_array *minuend, t_map *subtrahend, t_map *result);

bool	int_array_diff(
	t_int_array *minuend,
	t_int_array *subtrahend,
	t_map *out
) {
	t_map	subtrahend_map;
	bool	ok;

	ok = false;
	if (map_make(&subtrahend_map, minuend->size))
	{
		if (fill_map(&subtrahend_map, subtrahend))
		{
			if (map_make(out, minuend->size))
			{
				subtract(minuend, &subtrahend_map, out);
				ok = true;
			}
		}
	}
	map_destroy_contents(&subtrahend_map);
	if (!ok)
		map_destroy_contents(out);
	return (ok);
}

static void	subtract(
		t_int_array *minuend,
		t_map *subtrahend,
		t_map *result
) {
	size_t	i;
	int32_t	*value;

	i = 0;
	while (i < minuend->size)
	{
		value = map_lookup(subtrahend, minuend->arr[i]);
		if (value != NULL && *value > 0)
			--*value;
		else
			map_insert(result, minuend->arr[i], 0);
		++i;
	}
}

static bool	fill_map(t_map *map, t_int_array *arr)
{
	size_t	i;
	int32_t	*value;

	i = 0;
	while (i < arr->size)
	{
		value = map_upsert(map, arr->arr[i], 0);
		if (value == NULL)
			return (false);
		++*value;
		++i;
	}
	return (true);
}
