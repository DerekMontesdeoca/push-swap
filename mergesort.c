/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergesort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:47:18 by dmontesd          #+#    #+#             */
/*   Updated: 2025/06/13 14:03:17 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "libft/libft.h"

static void	merge(int32_t *dest, int32_t *tmp, size_t start, size_t end);

bool mergesort(int32_t *src, int32_t *dest, size_t size)
{
	int32_t	*temp;

	temp = malloc(sizeof(int32_t[size]));
	if (temp == NULL)
		return (false);
	ft_memcpy(dest, src, sizeof(int32_t[size]));
	ft_memcpy(temp, src, sizeof(int32_t[size]));
	merge(dest, temp, 0, size);
	free(temp);
	return (true);
}

static void merge(int32_t *dest, int32_t *tmp, size_t start, size_t end)
{
	size_t	mid;
	size_t	i;
	size_t	left;
	size_t 	right;

	if (end - start <= 1)
		return;
	mid = (end - start) / 2 + start;
	merge(tmp, dest, start, mid);
	merge(tmp, dest, mid, end);
	i = start;
	left = start;
	right = mid;
	while (left != mid && right != end)
	{
		if (tmp[left] <= tmp[right])
			dest[i++] = tmp[left++];
		else
			dest[i++] = tmp[right++];
	}
	i = (int32_t *)ft_mempcpy(
		&dest[i], &tmp[left], sizeof(int32_t[mid - left])) - dest;
	ft_mempcpy(&dest[i], &tmp[right], sizeof(int32_t[end - right]));
}
