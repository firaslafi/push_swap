/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 23:55:30 by flafi             #+#    #+#             */
/*   Updated: 2023/09/11 23:09:09 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// stack b @
// head of b
// update head of stack a
// update stack b @
void	push(t_stack **source, t_stack **destination)
{
	t_stack	*tmp;
	t_stack	*current;

	if (source == NULL)
		return ;
	tmp = (*source)->next;
	current = *source;
	current->next = *destination;
	(*destination) = current;
	*source = tmp;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}
