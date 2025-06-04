/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 03:38:32 by dmontesd          #+#    #+#             */
/*   Updated: 2025/05/31 07:04:53 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

# include <stdint.h>
# include <stddef.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct s_lis
{
	int32_t	*data;
	size_t	*tails;
	ssize_t	*indices;
	size_t	cap;
	size_t	len;
}	t_lis;

/**
 * Lower bound binary search.
 */
int32_t	*lower_bound(int32_t *arr, size_t size, int32_t elem);

/**
 * Lower bound binary search of indices.
 */
size_t	*lower_bound_idx(
			size_t *indices,
			int32_t *data,
			size_t size,
			int32_t elem
			);

/**
 * Longest increasing subsequence algorithm using patience sorting.
 */
bool	lis(int32_t *arr, size_t size, int32_t **data_out, size_t *size_out);

/**
 * LIS on a circular array.
 */
bool	circular_lis(
			int32_t *arr,
			size_t size,
			int32_t **data_out,
			size_t *size_out
			);

/**
 * Simple and fast non-cryptographic hash function for uint32_t.
 */
uint32_t	hash(uint32_t n);

void		quicksort(
				int32_t *arr,
				size_t size,
				int (*cmp)(int32_t, int32_t)
				);

#endif
