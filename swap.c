/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 23:21:49 by flafi             #+#    #+#             */
/*   Updated: 2023/08/22 00:58:46 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_stack *stack)
{
    int tmp;
    
    if (stack == NULL || stack->next == NULL)
        return ;
    tmp = stack->data;
    stack->data = stack->next->data;
    stack->next->data = tmp;
    tmp = stack->index;
    stack->index = stack->next->index;
    stack->next->index = tmp;
}
void sa(t_stack *stack_a)
{
    swap(stack_a);
    ft_putstr_fd("sa\n", 1);
}

void sb(t_stack *stack_b)
{
    swap(stack_b);
    ft_putstr_fd("sb\n", 1);
}
void ss(t_stack *stack_a, t_stack *stack_b)
{
    swap(stack_a);
    swap(stack_b);
    ft_putstr_fd("ss\n", 1);
}