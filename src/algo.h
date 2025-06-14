/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 03:38:32 by dmontesd          #+#    #+#             */
/*   Updated: 2025/06/14 19:31:49 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Reusable general functions for a variety of purposes.
 */

#ifndef ALGO_H
# define ALGO_H

# include <stdint.h>
# include <stddef.h>
# include <stdbool.h>
# include <stdio.h>

/**
 * Internal
 * Holds the data required to calculate thhe longest increasing subsequence
 * of an array of int32_t.
 */
typedef struct s_lis
{
	int32_t	*data;
	size_t	*tails;
	ssize_t	*indices;
	size_t	cap;
	size_t	len;
}	t_lis;

/**
 * Longest increasing subsequence algorithm using patience sorting.
 */
bool		lis(
				int32_t *arr,
				size_t size,
				int32_t **data_out,
				size_t *size_out
				);

/**
 * LIS on a circular array. See Longest increasing subsequence.
 */
bool		circular_lis(
				int32_t *arr,
				size_t size,
				int32_t **data_out,
				size_t *size_out
				);

/**
 * Lower bound binary search.
 */
int32_t		*lower_bound(int32_t *arr, size_t size, int32_t elem);

/**
 * Lower bound binary search of indices.
 */
size_t		*lower_bound_idx(
				size_t *indices,
				int32_t *data,
				size_t size,
				int32_t elem
				);

/**
 * Simple and fast non-cryptographic hash function for uint32_t.
 */
uint32_t	hash(uint32_t n);

/**
 * Quick sort implementation on array of int32_t.
 */
void		quicksort(
				int32_t *arr,
				size_t size,
				int (*cmp)(int32_t, int32_t)
				);

/**
 * Stable (n log n) sorting for best, average and worst case on array of
 * int32_t.
 */
bool		mergesort(int32_t *src, int32_t *dest, size_t size);

#endif
