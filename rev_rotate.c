/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 21:32:28 by flafi             #+#    #+#             */
/*   Updated: 2023/09/07 21:19:54 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;
	t_stack	*head;
	t_stack	*before_last;

	if ((*stack)->next == NULL)
		return ;
	head = (*stack);
	tmp = (*stack)->next;
	last = (*stack);
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = head;
	(*stack) = last;
}

void	rra(t_stack **stack)
{
	rev_rotate(stack);
	printf("rra\n");
}

void	rrb(t_stack **stack)
{
	rev_rotate(stack);
	printf("rrb\n");
}

void	rrr(t_stack **stacka, t_stack **stackb)
{
	rev_rotate(stacka);
	rev_rotate(stackb);
	printf("rrr\n");
}
