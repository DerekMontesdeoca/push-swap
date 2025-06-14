/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_distances.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 00:09:27 by dmontesd          #+#    #+#             */
/*   Updated: 2025/06/14 19:25:25 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solution_internal.h"
#include "cmp.h"

t_distance_combination_index	min_distance_combination(
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
	distance_combinations.as_struct.a_down_b_up = distances_a->down
		+ distances_b->up;
	distance_combinations.as_struct.a_up_b_down = distances_a->up
		+ distances_b->down;
	return (min_index(
			distance_combinations.as_array,
			sizeof(distance_combinations.as_array)
			/ sizeof(distance_combinations.as_array[0]),
			sizeof(distance_combinations.as_array[0]),
			size_t_cmp
		));
}

size_t	min_distance_to_top(size_t index, size_t len)
{
	t_circular_distances	distances;

	distances = circular_distances(index, len);
	if (distances.up <= distances.down)
		return (distances.up);
	else
		return (distances.down);
}

t_circular_distances	circular_distances(size_t index, size_t len)
{
	t_circular_distances	distances;

	distances.up = index;
	distances.down = len - index;
	return (distances);
}
