/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 01:28:34 by dmontesd          #+#    #+#             */
/*   Updated: 2025/06/08 14:46:50 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "libft/libft.h"
#include "map.h"
#include "push_swap.h"
#include "solution.h"

static bool	parse_numbers(
		t_map *map,
		char **args,
		size_t size,
		int32_t *numbers_out
) {
	long long			lln;
	size_t				i;
	char				*endptr;

	i = 0;
	while (i < size)
	{
		lln = strtoll(args[i], &endptr, 10);
		if (*endptr != '\0' || lln > INT32_MAX || lln < INT32_MIN)
		{
			ft_fprintf(STDERR_FILENO, "number out of int32 range\n");
			return (false);
		}
		if (map_insert(map, lln, 1) != MAP_INSERT_OK)
		{
			ft_fprintf(STDERR_FILENO, "duplicate number %d\n", (int)lln);
			return (false);
		}
		numbers_out[i] = lln;
		++i;
	}
	return (true);
}

int main(int argc, char **argv)
{
	t_push_swap	push_swap;
	int32_t		*numbers;
	t_map		map;
	bool		ok;

	if (argc == 1)
		return (ft_printf("\n"), 0);
	ok = false;
	numbers = malloc(sizeof(int32_t[argc - 1]));
	ok = map_make(&map, argc - 1);
	if (numbers != NULL && ok)
	{
		ok = false;
		if (parse_numbers(&map, argv + 1, argc - 1, numbers))
			if (push_swap_make(&push_swap, numbers, argc - 1))
			{
				if (split_then_insert(&push_swap))
				{
					if (push_swap_print_ops(&push_swap))
						ok = true;
				}
				push_swap_destroy_contents(&push_swap);
			}
	}
	free(numbers);
	map_destroy_contents(&map);
	if (ok)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}
