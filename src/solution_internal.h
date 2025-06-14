/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_internal.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:05:57 by dmontesd          #+#    #+#             */
/*   Updated: 2025/06/14 19:40:13 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLUTION_INTERNAL_H
# define SOLUTION_INTERNAL_H

# include <stddef.h>
# include "push_swap.h"
# include "array.h"

/**
 * State required to perform the split_insert algorithm that solves push swap.
 */
typedef struct s_split_insert
{
	t_push_swap	*push_swap;
	t_int_array	numbers;		/**< All numbers on push_swap. */
	t_int_array	lis;			/**< in-order numbers. */
	t_map		non_lis;		/**< out-of-order numbers. */
}	t_split_insert;

bool							split_insert_make(
									t_split_insert *si,
									t_push_swap *push_swap
									);

void							split_insert_destroy(t_split_insert *si);

/**
 * Push out-of-order elements to b while splitting them up and down based on
 * the median of the out-of-order numbers.
 */
bool							push_non_lis_to_b_and_pivot_split(
									t_split_insert *si
									);

/**
 * Insert sort elements from b to a based on how many moves each require to
 * go into their sorted position.
 */
void							insert_sort_to_a(
									t_split_insert *si
									);

/**
 * Holds the distance to a particular position in a circular data structure.
 */
typedef struct s_circular_distances
{
	size_t	up;
	size_t	down;
}	t_circular_distances;

/**
 * Push swap holds 2 circular data structures. In order to move an element to a
 * sorted position from b to a, both data structures need to move: b moves the
 * element to the top, while a moves the position where it goes to the top.
 * This struct contains the number of moves required in each way push swap can 
 * be moved to the desired positions.
 */
typedef struct s_distance_combinations
{
	size_t	both_up;
	size_t	both_down;
	size_t	a_up_b_down;
	size_t	a_down_b_up;
}	t_distance_combinations;

/**
 * Enum that gives a name to each index of the u_distance_combinations union.
 */
typedef enum e_distance_combination_index
{
	DISTANCE_COMBINATION_INDEX_BOTH_UP = 0,
	DISTANCE_COMBINATION_INDEX_BOTH_DOWN = 1,
	DISTANCE_COMBINATION_INDEX_A_UP_B_DOWN = 2,
	DISTANCE_COMBINATION_INDEX_A_DOWN_B_UP = 3,
}	t_distance_combination_index;

/**
 * Allows the user to reinterpret the fields of the t_distance_combinations as
 * an array. This makes it convenient to apply min and max functions on the
 * array.
 */
union u_distance_combinations
{
	t_distance_combinations	as_struct;
	size_t					as_array[4];
};

t_circular_distances			circular_distances(size_t index, size_t len);

/**
 * Calculate which of the possible ways of movements of push swap will take the
 * least amount of moves to get to the desired position.
 */
t_distance_combination_index	min_distance_combination(
									t_circular_distances *distances_a,
									t_circular_distances *distances_b
									);

size_t							min_distance_to_top(size_t index, size_t len);

/**
 * Moves required to insert from b to a. The order of this doesn't matter as
 * long as push a is done last.
 */
typedef struct s_insert_plan
{
	size_t	ra;
	size_t	rb;
	size_t	rra;
	size_t	rrb;
	size_t	rr;
	size_t	rrr;
	size_t	pa;
}	t_insert_plan;

/**
 * Makes the insert plan with the least movements by comparing all posibilities.
 */
void							insert_plan_make(
									t_insert_plan *ip,
									t_push_swap *push_swap
									);

void							insert_plan_make_a_up_b_down(
									t_insert_plan *ip,
									t_circular_distances *a,
									t_circular_distances *b
									);

void							insert_plan_make_a_down_b_up(
									t_insert_plan *ip,
									t_circular_distances *a,
									t_circular_distances *b
									);

void							insert_plan_make_both_up(
									t_insert_plan *ip,
									t_circular_distances *a,
									t_circular_distances *b
									);

void							insert_plan_make_both_down(
									t_insert_plan *ip,
									t_circular_distances *a,
									t_circular_distances *b
									);

/**
 * @returns the sum of all the moves.
 */
size_t							insert_plan_moves(t_insert_plan *ip);

#endif
