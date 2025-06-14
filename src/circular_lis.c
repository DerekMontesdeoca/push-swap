/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_lis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 21:25:25 by dmontesd          #+#    #+#             */
/*   Updated: 2025/06/14 19:30:30 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "algo.h"
#include "array.h"
#include "libft/libft.h"

static bool	max_lis(
		int32_t *double_arr, int32_t **lis_arr, size_t size,
		t_int_array *arr_out
) {
	size_t	i;
	size_t	max_len;
	size_t	max_len_index;
	size_t	lis_size;

	i = 0;
	max_len = 0;
	while (i < size)
	{
		if (!lis(double_arr + i, size, &lis_arr[i], &lis_size))
			return (false);
		if (lis_size > max_len)
		{
			max_len = lis_size;
			max_len_index = i;
		}
		++i;
	}
	arr_out->arr = lis_arr[max_len_index];
	arr_out->size = max_len;
	lis_arr[max_len_index] = NULL;
	return (true);
}

bool	circular_lis(
	int32_t *arr,
	size_t size,
	int32_t **data_out,
	size_t *size_out
) {
	int32_t		*double_arr;
	int32_t		**lis_arr;
	t_int_array	result;
	bool		ok;

	ok = false;
	double_arr = malloc(sizeof(int32_t [size * 2]));
	lis_arr = ft_calloc(size, sizeof(int32_t *));
	if (double_arr != NULL && lis_arr != NULL)
	{
		ft_mempcpy(ft_mempcpy(double_arr, arr, sizeof(int32_t[size])),
			arr, sizeof(int32_t[size]));
		if (max_lis(double_arr, lis_arr, size, &result))
		{
			*data_out = result.arr;
			*size_out = result.size;
			ok = true;
		}
	}
	while (size--)
		free(lis_arr[size]);
	free(double_arr);
	free(lis_arr);
	return (ok);
}
