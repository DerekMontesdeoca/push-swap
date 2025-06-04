/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:15:17 by dmontesd          #+#    #+#             */
/*   Updated: 2025/05/31 04:54:37 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
#include "map.h"
#include "libft/libft.h"
#include "algo.h"

/**
 * Capacity must be a multiple of 2.
 */
bool	map_make(t_map *m, size_t cap)
{
	size_t	pow2_cap;
	size_t	max_cap;

	max_cap = (SIZE_MAX >> 1) + 1;
	if (max_cap / 2 <= cap)
		return (false);
	cap += cap + 1;
	if (cap > max_cap)
		return (false);
	pow2_cap = 1;
	while (pow2_cap < cap && pow2_cap != max_cap)
		pow2_cap <<= 1;
	if (pow2_cap == max_cap && pow2_cap < cap)
		return (false);
	m->entries = ft_calloc(pow2_cap, sizeof(m->entries[0]));
	if (m->entries == NULL)
		return (false);
	m->len = 0;
	m->cap = pow2_cap;
	return (true);
}

t_map_insert_return	map_insert(t_map *m, int32_t key, int32_t value)
{
	uint32_t	i;

	if (m->len * 2 >= m->cap)
		return (MAP_INSERT_FULL);
	i = hash(key) & (m->cap - 1);
	while (m->entries[i].is_used)
	{
		if (m->entries[i].key == key)
			return (MAP_INSERT_DUPLICATE_KEY);
		i = (i + 1) & (m->cap - 1);
	}
	m->entries[i].key = key;
	m->entries[i].value = value;
	m->entries[i].is_used = true;
	++m->len;
	return (MAP_INSERT_OK);
}

int32_t	*map_upsert(t_map *m, int32_t key, int32_t default_v)
{
	uint32_t	i;

	if (m->len * 2 >= m->cap)
		return (NULL);
	i = hash(key) & (m->cap - 1);
	while (m->entries[i].is_used)
	{
		if (m->entries[i].key == key)
			return (&m->entries[i].value);
		i = (i + 1) & (m->cap - 1);
	}
	m->entries[i].key = key;
	m->entries[i].value = default_v;
	m->entries[i].is_used = true;
	++m->len;
	return (&m->entries[i].value);
}

int32_t	*map_lookup(t_map *m, int32_t key)
{
	uint32_t	i;

	i = hash(key) & (m->cap - 1);
	while (m->entries[i].is_used)
	{
		if (m->entries[i].key == key)
		{
			return (&m->entries[i].value);
		}
		i = (i + 1) & (m->cap - 1);
	}
	return (NULL);
}

void	map_destroy_contents(t_map *m)
{
	free(m->entries);
	*m = (t_map){};
}
