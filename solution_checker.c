/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 02:16:15 by dmontesd          #+#    #+#             */
/*   Updated: 2025/06/14 02:37:12 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "checker.h"

bool	parse_command(char *line, t_command *command);

bool	run_command(t_push_swap *push_swap, t_command *command);

bool	intlist_is_sorted(t_intlist *lst);

bool	check_solution(t_push_swap *push_swap, bool *result)
{
	char		*line;
	t_command	command;
	bool		ok;

	while (true)
	{
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
			break;
		else
		{
			ok = parse_command(line, &command);
			if (ok)
				ok = run_command(push_swap, &command);
			free(line);
		}
		if (!ok)
			break;
	}
	if (ok)
		*result = intlist_is_sorted(&push_swap->a) && push_swap->b.len == 0;
	return (ok);
}
