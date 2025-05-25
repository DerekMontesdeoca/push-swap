/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 01:28:34 by dmontesd          #+#    #+#             */
/*   Updated: 2025/05/06 04:47:59 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "libft/libft.h"
#include "push_swap.h"

void	push_swap(t_stacks *stacks, int size);

int main(int argc, char **argv)
{
	t_intlist	*node_arr;
	t_stacks	stacks;
	bool		err;

	if (argc == 1)
		return (ft_printf("\n"), 0);
	err = false;
	node_arr = malloc(sizeof(t_intlist[argc - 1]));
	if (node_arr == NULL)
		err = true;
	if (node_arr != NULL)
	{
		err = !make_stacks(argc - 1, &argv[1], node_arr, &stacks);
		if (!err)
			push_swap(&stacks, argc - 1);
		free(node_arr);
	}
	if (err)
		ft_printf("Error\n");
	return (0);
}

void	push_swap(t_stacks *stacks, int size)
{
	/* stacks_print(&stacks->a, &stacks->b); */
	f(&stacks->a, &stacks->b, size, true);
	/* stacks_print(&stacks->a, &stacks->b); */
}
