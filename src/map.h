/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:02:55 by dmontesd          #+#    #+#             */
/*   Updated: 2025/06/13 22:40:57 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>

typedef enum e_map_insert_return
{
	MAP_INSERT_OK,
	MAP_INSERT_DUPLICATE_KEY,
	MAP_INSERT_FULL,
}	t_map_insert_return;

typedef struct s_entry
{
	int32_t	key;
	int32_t	value;
	bool	is_used;
}	t_entry;

typedef struct s_map
{
	t_entry	*entries;
	size_t	cap;
	size_t	len;
}	t_map;

/**
 * Creates a map, silently increasing the capacity of cap to the next nearest
 * power of 2.
 */
bool				map_make(t_map *m, size_t cap);

t_map_insert_return	map_insert(t_map *m, int32_t key, int32_t value);

/**
 * If not exists create default and return value ptr.
 * @return Pointer to value or NULL if map is full.
 */
int32_t				*map_upsert(t_map *m, int32_t key, int32_t default_v);

int32_t				*map_lookup(t_map *m, int32_t key);

void				map_destroy_contents(t_map *m);

bool				map_from_array(int32_t *arr, size_t size, t_map *map_out);

#endif
