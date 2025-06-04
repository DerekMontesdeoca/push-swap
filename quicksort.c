/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 05:05:45 by dmontesd          #+#    #+#             */
/*   Updated: 2025/05/31 16:02:56 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

static void	swap(int32_t *a, int32_t *b)
{
	int32_t	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	quicksort(int32_t *arr, size_t size, int (*cmp)(int32_t, int32_t))
{
	int32_t	pivot;
	size_t	i;
	size_t	j;

	if (size <= 1)
		return ;
	pivot = arr[size / 2];
	i = -1;
	j = size;
	while (true)
	{
		++i;
		while (cmp(arr[i], pivot) < 0)
			++i;
		--j;
		while (cmp(arr[j], pivot) > 0)
			--j;
		if (i >= j)
			break;
		swap(&arr[i], &arr[j]);
	}
	quicksort(arr, i, cmp);
	quicksort(arr + i, size - i, cmp);
}
