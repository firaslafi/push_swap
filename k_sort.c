/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:10:49 by flafi             #+#    #+#             */
/*   Updated: 2023/09/10 23:54:50 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	k_sort1(t_stacks *stacks, int length)
{
	int	i;
	int	range;

	i = 0;
	range = ft_sqrt(length) * 14 / 10;
	while (stacks->a)
	{
		if (stacks->a->index <= i)
		{
			pb(&stacks->a, &stacks->b);
			rb(&stacks->b);
			i++;
		}
		else if (stacks->a->index <= i + range)
		{
			pb(&stacks->a, &stacks->b);
			i++;
		}
		else
			ra(&stacks->a);
	}
}

void	k_sort2(t_stacks *stacks, int length)
{
	int	rb_count;
	int	rrb_count;

	while (length - 1 >= 0)
	{
		rb_count = count_r(stacks->b, length - 1);
		rrb_count = (length + 3) - rb_count;
		if (rb_count <= rrb_count)
		{
			while (stacks->b->index != length - 1)
				rb(&stacks->b);
			pa(&stacks->a, &stacks->b);
			length--;
		}
		else
		{
			while (stacks->b->index != length - 1)
				rrb(&stacks->b);
			pa(&stacks->a, &stacks->b);
			length--;
		}
	}
}

int	count_r(t_stack *stack, int index)
{
	int	counter;

	counter = 0;
	while (stack && stack->index != index)
	{
		stack = stack->next;
		counter++;
	}
	return (counter);
}

void	ft_casethree(t_stack **a)
{
	if ((*a)->index > (*a)->next->index
		&& (*a)->index > (*a)->next->next->index)
	{
		ra(a);
		if ((*a)->index > (*a)->next->index)
			sa(*a);
	}
	else if ((*a)->index < (*a)->next->index
		&& (*a)->index > (*a)->next->next->index)
	{
		rra(a);
	}
	else if ((*a)->index > (*a)->next->index
		&& (*a)->index < (*a)->next->next->index)
	{
		sa(*a);
	}
	else if ((*a)->index < (*a)->next->index
		&& (*a)->index < (*a)->next->next->index)
	{
		rra(a);
		sa(*a);
	}
}

void	sort_stack_5(t_stack **stack_a, t_stack **stack_b, int length)
{
	while (length > 3)
	{
		if ((*stack_a)->index == 0 || (*stack_a)->index == 1)
		{
			pb(stack_a, stack_b);
			length--;
		}
		else
			ra(stack_a);
	}
	if (is_sorted(*stack_a) == 0)
		ft_casethree(stack_a);
	while (length != 5)
	{
		if ((*stack_b)->index == 1 || length == 4)
		{
			pa(stack_a, stack_b);
			length++;
		}
		else
			rb(stack_b);
	}
}
