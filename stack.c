/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontesd <dmontesd@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 02:56:03 by dmontesd          #+#    #+#             */
/*   Updated: 2025/05/06 04:42:49 by dmontesd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft/libft.h"
#include "push_swap.h"

void push(t_intlist **stack, t_intlist *new_node)
{
	new_node->next = *stack;
	*stack = new_node;
}

t_intlist	*pop(t_intlist **stack)
{
	t_intlist *temp;

	if (*stack == NULL)
		return (NULL);
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = NULL;
	return (temp);
}

void	rotate(t_intlist **stack)
{
	t_intlist	**cur;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	cur = stack;
	while (*cur != NULL)
		cur = &(*cur)->next;
	*cur = *stack;
	*stack = (*stack)->next;
	(*cur)->next = NULL;
	ft_printf("rotate\n");
}

void	rrotate(t_intlist **stack)
{
	t_intlist	**cur;
	
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	cur = stack;
	while ((*cur)->next != NULL)
		cur = &(*cur)->next;
	(*cur)->next = *stack;
	*stack = *cur;
	*cur = NULL;
	ft_printf("rrotate\n");
}

void swap(t_intlist **stack)
{
	t_intlist	*temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	ft_printf("swap\n");
}
