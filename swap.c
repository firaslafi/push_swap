/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 23:21:49 by flafi             #+#    #+#             */
/*   Updated: 2023/08/25 23:32:03 by flafi            ###   ########.fr       */
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
    printf("sa\n");
}

void sb(t_stack *stack_b)
{
    swap(stack_b);
    printf("sb\n");
}
void ss(t_stack *stack_a, t_stack *stack_b)
{
    swap(stack_a);
    swap(stack_b);
    printf("ss\n");
}