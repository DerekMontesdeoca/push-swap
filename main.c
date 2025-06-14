/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 01:28:34 by dmontesd          #+#    #+#             */
/*   Updated: 2025/06/14 01:38:57 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "libft/libft.h"
#include "push_swap.h"
#include "solution.h"

int main(int argc, char **argv)
{
	t_push_swap	push_swap;
	int32_t		*numbers;
	bool		ok;

	if (argc == 1)
		return (ft_printf("\n"), 0);
	ok = false;
	numbers = parse_numbers(argv + 1, argc - 1);
	if (numbers != NULL)
	{
		if (push_swap_make(&push_swap, numbers, argc - 1))
		{
			if (split_then_insert(&push_swap))
			{
				if (push_swap_print_ops(&push_swap))
					ok = true;
			}
			push_swap_destroy_contents(&push_swap);
		}
		free(numbers);
	}
	if (ok)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}
