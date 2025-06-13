/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_print_ops.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 14:00:39 by dmontesd          #+#    #+#             */
/*   Updated: 2025/06/09 19:46:09 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"
#include "libft/libft.h"

static void	strjoin(char *buf, t_op_vector *ops)
{
	size_t	i;
	char	*end;

	end = buf;
	i = 0;
	while (i < ops->len)
	{
		end += ft_strlcpy(end, op_to_string(ops->data[i]), 4);
		end[-1] = '\n';
		++i;
	}
	*end = '\0';
}

bool	push_swap_print_ops(t_push_swap *ps)
{
	char	*buf;
	bool	ok;

	ok = false;
	buf = malloc(ps->ops.len * sizeof(char[4]) + sizeof(char));
	if (buf == NULL)
		ft_printf("malloc: allocation error\n");
	else
	{
		strjoin(buf, &ps->ops);
		if (ft_printf("%s", buf) < 0)
			ft_fprintf(STDERR_FILENO, "printf: error printing\n");
		else
			ok = true;
		free(buf);
	}
	return (ok);
}
