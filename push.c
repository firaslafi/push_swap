/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 23:55:30 by flafi             #+#    #+#             */
/*   Updated: 2023/09/03 00:38:31 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(t_stack **source, t_stack **destination)
{
    t_stack *tmp;
    t_stack *current;
    
    if (source == NULL)
        return ;


    tmp = (*source)->next; // stack b @
    current = *source; // head of b
    current->next = *destination;
    (*destination) = current; // update head of stack a
    *source = tmp; // update stack b @
}

void pa(t_stack **stack_a, t_stack **stack_b)
{
    push(stack_b, stack_a);
    printf("pa\n");
}
void pb(t_stack **stack_a, t_stack **stack_b)
{
    push(stack_a, stack_b);
    printf("pb\n");
}