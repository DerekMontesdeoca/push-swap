/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 02:16:15 by dmontesd          #+#    #+#             */
/*   Updated: 2025/06/14 12:14:46 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "checker.h"

bool	check_solution(t_push_swap *push_swap, bool *result)
{
	char		*line;
	t_op		op;
	bool		ok;

	while (true)
	{
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
			break;
		else
		{
			ok = op_from_string(&op, line);
			if (ok)
				ok = push_swap_run_op(push_swap, op);
			free(line);
		}
		if (!ok)
			break;
	}
	if (ok)
		*result = intlist_is_sorted(push_swap->a) && push_swap->b.len == 0;
	return (ok);
}
