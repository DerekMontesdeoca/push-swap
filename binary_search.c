/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 04:37:32 by dmontesd          #+#    #+#             */
/*   Updated: 2025/05/29 21:22:26 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

int32_t	*lower_bound(int32_t *arr, size_t size, int32_t elem)
{
	size_t	mid;

	if (size == 0)
		return (arr);
	mid = size / 2;
	if (elem <= arr[mid])
		return (lower_bound(arr, mid, elem));
	else
		return (lower_bound(&arr[mid + 1], size - mid - 1, elem));
}

size_t	*lower_bound_idx(
	size_t *indices,
	int32_t *data,
	size_t size,
	int32_t elem
) {
	size_t	mid;

	if (size == 0)
		return (indices);
	mid = size / 2;
	if (elem <= data[indices[mid]])
		return (lower_bound_idx(indices, data, mid, elem));
	else
		return (lower_bound_idx(&indices[mid + 1], data, size - mid - 1, elem));
}
