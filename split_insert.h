/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_insert.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:23:53 by dmontesd          #+#    #+#             */
/*   Updated: 2025/06/03 02:20:36 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_INSERT_H
# define SPLIT_INSERT_H

# include "push_swap.h"
# include "array.h"

typedef struct s_circular_distances
{
	size_t	up;
	size_t	down;
}	t_circular_distances;

typedef struct s_distance_combinations
{
	size_t	both_up;
	size_t	both_down;
	size_t	a_up_b_down;
	size_t	a_down_b_up;
}	t_distance_combinations;

typedef enum e_distance_combination_index
{
	DISTANCE_COMBINATION_INDEX_BOTH_UP = 0,
	DISTANCE_COMBINATION_INDEX_BOTH_DOWN = 1,
	DISTANCE_COMBINATION_INDEX_A_UP_B_DOWN = 2,
	DISTANCE_COMBINATION_INDEX_A_DOWN_B_UP = 3,
}	t_distance_combination_index;

union u_distance_combinations
{
	t_distance_combinations	as_struct;
	size_t					as_array[4];
};

typedef struct s_insert_plan
{
	size_t	pb;
	size_t	ra;
	size_t	rra;
	size_t	rb;
	size_t	rrb;
	size_t	rr;
	size_t	rrr;
}	t_insert_plan;

typedef struct s_split_insert
{
	t_push_swap	*push_swap;
	t_int_array	numbers;
	t_int_array	lis;
	t_map	non_lis;
}	t_split_insert;

bool	split_insert_make(t_split_insert *si, t_push_swap *push_swap);

bool	push_non_lis_to_b_and_pivot_split(t_split_insert *si);

void	split_insert_destroy(t_split_insert *si);

void	insert_sort_to_a(t_split_insert *si);

#endif
