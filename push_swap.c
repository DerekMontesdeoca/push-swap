/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:15:32 by dmontesd          #+#    #+#             */
/*   Updated: 2025/05/27 22:16:44 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"

bool ft_strtoi(const char *str, int *n)
{
	char	*endptr;

	if (str == NULL || *str == '\0')
		return (false);
	long long nbr = strtoll(str, &endptr, 10);
	if (*endptr != '\0' || nbr > INT_MAX || nbr < INT_MIN)
		return (false);
	*n = (int)nbr;
	return (true);
}

bool make_push_swap(
	t_push_swap *ps,
	int n_nbrs,
	char **strs,
	t_intlist_node *node_arr
) {
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
		else
			node_arr[i].next = NULL;
		++i;
	}
	ps->a = &node_arr[n_nbrs - 1];
	ps->b = NULL;
	return (true);
}


bool	stacks_print(t_intlist_node **as, t_intlist_node **bs)
{
	t_intlist_node	*a;
	t_intlist_node	*b;
	bool		err;

	err = ft_printf("\n____________  ____________\n") == -1;
	a = *as;
	b = *bs;
	while (!err && (a != NULL || b != NULL))
	{
		if (a != NULL)
			err |= ft_printf("%12d  ", a->data) == -1;
		else
			err |= ft_printf("%12s  ", "") == -1;
		if (b != NULL)
			err |= ft_printf("%12d\n", b->data) == -1;
		else
			err |= ft_printf("%12s\n", "") == -1;
		if (a != NULL)
			a = a->next;
		if (b != NULL)
			b = b->next;
	}
	err |= ft_printf("\n") == -1;
	return (!err);
}
