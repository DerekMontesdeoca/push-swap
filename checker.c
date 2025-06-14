/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 22:16:51 by dmontesd          #+#    #+#             */
/*   Updated: 2025/06/14 19:43:42 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"
#include "libft/libft.h"
#include "checker.h"

static inline int	fail(void)
{
	return (ft_printf("KO\n") < 0);
}

static inline int	succeed(void)
{
	return (ft_printf("OK\n") < 0);
}

static bool	run_checker(char **args, size_t size)
{
	t_push_swap	push_swap;
	bool		ok;
	bool		solution_ok;
	int32_t		*numbers;

	ok = false;
	numbers = parse_numbers(args, size);
	if (numbers != NULL)
	{
		if (push_swap_make(&push_swap, numbers, size))
		{
			if (check_solution(&push_swap, &solution_ok))
			{
				if (solution_ok)
					ok = succeed();
				else
					ok = fail();
			}
			push_swap_destroy_contents(&push_swap);
		}
		free(numbers);
	}
	return (ok);
}

int	main(int argc, char **argv)
{
	bool		ok;

	if (argc == 1)
		ok = succeed();
	else
		ok = run_checker(argv + 1, argc - 1);
	if (!ok)
	{
		ft_fprintf(STDERR_FILENO, "Error\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
