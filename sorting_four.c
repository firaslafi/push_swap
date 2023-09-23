/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:43:36 by flafi             #+#    #+#             */
/*   Updated: 2023/09/18 18:46:55 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_4(t_stack *stacks)
{
	int	n;

	n = stacks->size;
	while (stacks->a->index != 0)
		ra(&stacks->a);
	pb(&stacks->a, &stacks->b);
	if (!is_sorted(stacks->a))
		ft_casethree(&stacks->a);
	pa(&stacks->a, &stacks->b);
}
