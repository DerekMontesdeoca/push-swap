/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 22:26:41 by dmontesd          #+#    #+#             */
/*   Updated: 2025/06/14 19:13:31 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>
#include "map.h"
#include "libft/libft.h"

static inline bool	ft_isspace(char c)
{
	return (c == '\v' || c == '\n' || c == '\t' || c == ' ' || c == '\f'
		|| c == '\r');
}

static bool	ft_strtoll10(const char *ptr, long long *n_out)
{
	bool				is_negative;
	long long			n_lim;
	unsigned long long	cutoff;

	is_negative = false;
	while (ft_isspace(*ptr))
		++ptr;
	if (*ptr == '+' || *ptr == '-')
		is_negative = *(ptr++);
	cutoff = LLONG_MAX;
	if (is_negative)
		cutoff = -(unsigned long long)LLONG_MIN;
	n_lim = cutoff % 10;
	cutoff /= 10;
	*n_out = 0;
	while (*ptr != '\0')
	{
		if (!ft_isdigit(*ptr))
			return (false);
		if (*n_out > (long long)cutoff
			|| (*n_out == (long long)cutoff && *ptr - '0' > n_lim))
			return (false);
		*n_out = *n_out * 10 + (*(ptr++) - '0');
	}
	return (true);
}

static bool	parse_numbers_inner(
		t_map *map,
		char **args,
		size_t size,
		int32_t *numbers_out
) {
	long long			lln;
	size_t				i;

	i = 0;
	while (i < size)
	{
		if (!ft_strtoll10(args[i], &lln) || lln > INT32_MAX || lln < INT32_MIN)
			return (false);
		if (map_insert(map, lln, 1) != MAP_INSERT_OK)
			return (false);
		numbers_out[i] = lln;
		++i;
	}
	return (true);
}

int32_t	*parse_numbers(char **strs, size_t size)
{
	int32_t	*numbers;
	t_map	map;

	if (size == 0)
		return (NULL);
	numbers = NULL;
	if (map_make(&map, size))
	{
		numbers = malloc(sizeof(int32_t[size]));
		if (numbers != NULL)
		{
			if (!parse_numbers_inner(&map, strs, size, numbers))
			{
				free(numbers);
				numbers = NULL;
			}
		}
		map_destroy_contents(&map);
	}
	return (numbers);
}
