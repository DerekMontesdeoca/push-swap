/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 02:41:50 by dmontesd          #+#    #+#             */
/*   Updated: 2025/06/03 03:15:22 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmp.h"

int	int32_t_cmp(void *a, void *b)
{
	int32_t	int32_a;
	int32_t	int32_b;

	int32_a = *(int32_t *)a;
	int32_b = *(int32_t *)b;
	if (int32_a > int32_b)
		return (1);
	if (int32_a < int32_b)
		return (-1);
	else
		return (0);
}

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

	if (nmemb <= 1)
		return (arr);
	max = arr;
	b_arr = arr;
	i = 1;
	while(i < nmemb)
	{
		if (cmp(max, b_arr + size * i) > 0)
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

	if (nmemb <= 1)
		return (arr);
	min = arr;
	b_arr = arr;
	i = 1;
	while(i < nmemb)
	{
		if (cmp(min, b_arr + size * i) < 0)
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
