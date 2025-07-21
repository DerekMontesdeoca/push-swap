/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 01:28:34 by dmontesd          #+#    #+#             */
/*   Updated: 2025/07/21 15:43:07 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "libft/libft.h"
#include "push_swap.h"
#include "solution.h"

static bool	solution(t_push_swap *push_swap)
{
	bool	ok;

	if (push_swap->n_numbers <= 5)
		ok = easy_sort(push_swap);
	else
		ok = split_then_insert(push_swap);
	if (!ok)
		return (false);
	return (push_swap_print_ops(push_swap));
}

static bool	create_push_swap(int32_t *numbers, int argc)
{
	t_push_swap	push_swap;
	bool		ok;

	ok = false;
	if (push_swap_make(&push_swap, numbers, argc - 1))
	{
		ok = solution(&push_swap);
		push_swap_destroy_contents(&push_swap);
	}
	return (ok);
}

int	main(int argc, char **argv)
{
	int32_t		*numbers;
	bool		ok;

	if (argc == 1)
		return (ft_printf("\n"), 0);
	ok = false;
	numbers = parse_numbers(argv + 1, argc - 1);
	if (numbers != NULL)
	{
		ok = create_push_swap(numbers, argc);
		free(numbers);
	}
	if (ok)
		return (EXIT_SUCCESS);
	else
		return (ft_fprintf(STDERR_FILENO, "Error\n"), EXIT_FAILURE);
}
