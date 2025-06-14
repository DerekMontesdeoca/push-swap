/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:45:54 by dmontesd          #+#    #+#             */
/*   Updated: 2025/06/14 22:36:27 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include "libft/libft.h"
#include "push_swap.h"

const char	*op_to_string(t_op op)
{
	if (op == OP_PA)
		return ("pa");
	if (op == OP_PB)
		return ("pb");
	if (op == OP_RA)
		return ("ra");
	if (op == OP_RB)
		return ("rb");
	if (op == OP_RR)
		return ("rr");
	if (op == OP_RRR)
		return ("rrr");
	if (op == OP_RRA)
		return ("rra");
	if (op == OP_RRB)
		return ("rrb");
	if (op == OP_SA)
		return ("sa");
	if (op == OP_SB)
		return ("sb");
	if (op == OP_SS)
		return ("ss");
	assert(false && "Unreachable code");
}

bool	op_from_string(t_op *op, char *str)
{
	if (ft_strncmp(str, "pa\n", 3) == 0)
		*op = OP_PA;
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		*op = OP_PB;
	else if (ft_strncmp(str, "ra\n", 3) == 0)
		*op = OP_RA;
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		*op = OP_RB;
	else if (ft_strncmp(str, "rr\n", 3) == 0)
		*op = OP_RR;
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		*op = OP_RRR;
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		*op = OP_RRA;
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		*op = OP_RRB;
	else if (ft_strncmp(str, "sa\n", 3) == 0)
		*op = OP_SA;
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		*op = OP_SB;
	else if (ft_strncmp(str, "ss\n", 3) == 0)
		*op = OP_SS;
	else
		return (false);
	return (true);
}
