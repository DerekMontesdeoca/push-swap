/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intlist_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 21:26:06 by dmontesd          #+#    #+#             */
/*   Updated: 2025/06/14 19:27:12 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intlist.h"
#include "libft/libft.h"

void	intlist_node_make(t_intlist_node *node, int32_t n)
{
	ft_memset(node, 0, sizeof(t_intlist_node));
	node->data = n;
}
