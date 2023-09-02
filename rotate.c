/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 00:04:25 by flafi             #+#    #+#             */
/*   Updated: 2023/09/03 00:38:31 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;
	t_stack	*head;

	if ((*stack)->next == NULL)
		return ;
	current = (*stack);
	head = (*stack);
	tmp = (*stack)->next;
	while (current->next)
		current = current->next;
	current->next = head;
	head->next = NULL;
	*stack = tmp;
}

void	ra(t_stack **stack)
{
	rotate(stack);
	printf("ra\n");
}

void	rb(t_stack **stack)
{
	rotate(stack);
	printf("rb\n");
}
void	rr(t_stack **stacka, t_stack **stackb)
{
	rotate(stacka);
	rotate(stackb);
	printf("rr\n");
}