/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 02:41:50 by dmontesd          #+#    #+#             */
/*   Updated: 2025/06/08 14:03:58 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include "cmp.h"

int	size_t_cmp(void *a, void *b)
{
	if (*(size_t *)a > *(size_t *)b)
		return (1);
	if (*(size_t *)a < *(size_t *)b)
		return (-1);
	else
		return (0);
}

void	*max(void *arr, size_t nmemb, size_t size, t_cmp_func cmp)
{
	size_t			i;
	unsigned char	*b_arr;
	void			*max;

	assert(nmemb != 0);
	if (nmemb == 1)
		return (arr);
	max = arr;
	b_arr = arr;
	i = 1;
	while(i < nmemb)
	{
		if (cmp(max, b_arr + size * i) < 0)
			max = b_arr + size * i;
		++i;
	}
	return (max);
}

void	*min(void *arr, size_t nmemb, size_t size, t_cmp_func cmp)
{
	size_t			i;
	unsigned char	*b_arr;
	void			*min;

	assert(nmemb != 0);
	if (nmemb == 1)
		return (arr);
	min = arr;
	b_arr = arr;
	i = 1;
	while(i < nmemb)
	{
		if (cmp(min, b_arr + size * i) > 0)
			min = b_arr + size * i;
		++i;
	}
	return (min);
}

size_t	min_index(void *arr, size_t nmemb, size_t size, t_cmp_func cmp)
{
	unsigned char	*minimum;

	minimum = min(arr, nmemb, size, cmp);
	return (((minimum - (unsigned char *)arr)) / size);
}
