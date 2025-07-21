/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_easy_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 00:56:37 by dmontesd          #+#    #+#             */
/*   Updated: 2025/07/21 15:46:10 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intlist.h"
#include "push_swap.h"
#include "solution.h"

static bool	easy_sort_3(t_push_swap *ps)
{
	int	elems[3];

	elems[0] = ps->a.head->data;
	elems[1] = ps->a.head->next->data;
	elems[2] = ps->a.head->prev->data;
	if (elems[0] < elems[1] && elems[0] < elems[2] && elems[1] > elems[2])
		return (push_swap_rra(ps) && push_swap_sa(ps));
	else if (elems[0] > elems[1] && elems[0] > elems[2] && elems[1] < elems[2])
		return (push_swap_ra(ps));
	else if (elems[0] > elems[1] && elems[0] > elems[2] && elems[1] > elems[2])
		return (push_swap_sa(ps) && push_swap_rra(ps));
	else if (elems[0] > elems[1] && elems[0] < elems[2])
		return (push_swap_sa(ps));
	else if (elems[0] < elems[1] && elems[0] > elems[2])
		return (push_swap_rra(ps));
	else
		return (true);
}

static bool	sort_other_5(t_push_swap *ps)
{
	size_t	i;

	if (!easy_sort_3(ps))
		return (false);
	if (ps->b.len > 1 && ps->b.head->data < ps->b.head->next->data)
		if (!push_swap_sb(ps))
			return (false);
	i = ps->b.len;
	while (i--)
		if (!push_swap_pa(ps))
			return (false);
	return (true);
}

static bool	easy_sort_up_to_5(t_push_swap *ps)
{
	size_t	i;
	size_t	to_find;

	to_find = 2;
	i = ps->n_numbers;
	while (i--)
	{
		if (ps->a.head->data == 0 || ps->a.head->data == 1)
		{
			if (!push_swap_pb(ps))
				return (false);
			if (--to_find == 0)
				break ;
			continue ;
		}
		if (!push_swap_ra(ps))
			return (false);
	}
	return (sort_other_5(ps));
}

bool	easy_sort(t_push_swap *ps)
{
	if (intlist_is_sorted(ps->a))
		return (true);
	if (ps->n_numbers == 2)
		return (push_swap_sa(ps));
	if (ps->n_numbers == 3)
		return (easy_sort_3(ps));
	else
		return (easy_sort_up_to_5(ps));
}
