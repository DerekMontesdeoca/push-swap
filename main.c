/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 01:28:34 by dmontesd          #+#    #+#             */
/*   Updated: 2025/04/30 02:55:39 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "libft/libft.h"
#include "push_swap.h"

bool make_stacks(int n_nbrs, char **strs, t_intlist *node_arr, t_stacks *stacks);
void	push_swap(t_stacks *stacks);

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
		err = !make_stacks(argc - 1, &argv[1], &stacks);
		if (!err)
			push_swap(&stacks);
		free(node_arr);
	}
	if (err)
		ft_printf("Error\n");
	return (0);
}

bool make_stacks(int n_nbrs, char **strs, t_intlist *node_arr, t_stacks *stacks)
{
	int	i;
	int	n;

	i = 0;
	while (i < n_nbrs)
	{
		if (!ft_strtoi(strs[i], &n))
			return (false);
		node_arr[i].data = n;
		if (i > 0)
			node_arr[i].next = &node_arr[i - 1];
		++i;
	}
	stacks->a = &node_arr[n_nbrs - 1];
	stacks->b = NULL;
}

void	push_swap(t_stacks *stacks)
{

}
