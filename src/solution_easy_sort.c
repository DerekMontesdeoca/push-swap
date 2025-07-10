/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_easy_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 00:56:37 by dmontesd          #+#    #+#             */
/*   Updated: 2025/07/10 04:48:46 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intlist.h"
#include "solution.h"

static bool	rotate_and_swap(
		t_push_swap *ps,
		bool is_sorted,
		bool should_rotate_up
) {
	if (is_sorted)
	{
		if (should_rotate_up)
			return (push_swap_ra(ps));
		else
			return (push_swap_rra(ps));
	}
	else
	{
		if (ps->a.head->next->data == 1)
		{
			if (!push_swap_ra(ps))
				return (false);
		}
		else
			if (!push_swap_rra(ps))
				return (false);
		return (push_swap_sa(ps));
	}
}

static bool	easy_sort_3(t_push_swap *ps)
{
	t_intlist	a_copy;
	bool		should_rotate_up;
	bool		is_sorted;

	a_copy = ps->a;
	should_rotate_up = ps->a.head->next->data == 0;
	if (a_copy.head->data != 0)
	{
		if (should_rotate_up)
			intlist_rotate(&a_copy);
		else
			intlist_rrotate(&a_copy);
	}
	is_sorted = intlist_is_sorted(a_copy);
	if (!rotate_and_swap(ps, is_sorted, should_rotate_up))
		return (false);
	return (true);
}

static bool	easy_split(t_push_swap *ps)
{
	if (ps->a.head->data == 0)
	{
		if (!push_swap_pb(ps))
			return (false);
		if (ps->b.len > 1)
			if (!push_swap_rb(ps))
				return (false);
	}
	else if (ps->a.head->data == 1)
	{
		if (!push_swap_pb(ps))
			return (false);
	}
	else
		if (!push_swap_ra(ps))
			return (false);
	return (true);
}

static bool	easy_sort_up_to_5(t_push_swap *ps)
{
	size_t	i;

	i = ps->n_numbers;
	while (i--)
		if (!easy_split(ps))
			return (false);
	if (!easy_sort_3(ps))
		return (false);
	i = 2;
	while (i--)
		if (!push_swap_pa(ps))
			return (false);
	return (true);
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
