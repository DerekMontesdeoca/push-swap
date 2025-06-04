/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_from_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 20:15:15 by dmontesd          #+#    #+#             */
/*   Updated: 2025/05/30 20:28:45 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

bool	map_from_array(int32_t *arr, size_t size, t_map *map_out)
{
	size_t	i;
	bool	ok;

	ok = false;
	if (map_make(map_out, size))
	{
		i = 0;
		ok = true;
		while (i < size)
		{
			if (map_insert(map_out, arr[i], 0) == MAP_INSERT_FULL)
			{
				ok = false;
				break;
			}
			++i;
		}
	}
	if (!ok)
		map_destroy_contents(map_out);
	return (ok);
}
