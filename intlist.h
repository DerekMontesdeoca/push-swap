/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intlist.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 21:04:44 by dmontesd          #+#    #+#             */
/*   Updated: 2025/05/28 05:21:14 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTLIST_H
# define INTLIST_H

# include <stddef.h>

typedef struct s_intlist_node
{
	int						data;
	struct s_intlist_node	*next;
	struct s_intlist_node	*prev;
}	t_intlist_node;

void			intlist_node_make(t_intlist_node *node, int n);

typedef struct s_intlist
{
	t_intlist_node	*head;
	size_t			len;
}	t_intlist;

void			intlist_insert(t_intlist *lst, t_intlist_node *node);

void			intlist_rotate(t_intlist *lst);

void			intlist_rrotate(t_intlist *lst);

void			intlist_swap(t_intlist *lst);

t_intlist_node	*intlist_pop(t_intlist *lst);

#endif
