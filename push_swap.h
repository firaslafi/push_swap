/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:47:17 by flafi             #+#    #+#             */
/*   Updated: 2023/08/27 00:00:00 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <limits.h>
#include <stdio.h>

typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*next;

}					t_stack;

typedef struct s_stacks
{
	t_stack			*a;
	t_stack			*b;
	int				size;
}					t_stacks;

typedef struct s_tab
{
	int				len;
	long long		*array;
}					t_tab;

long long			ft_atol(const char *str);
void				sa(t_stack *stack_a);
void sb(t_stack *stack_b);
void ss(t_stack *stack_a, t_stack *stack_b);
void pa(t_stack **stack_a, t_stack **stack_b);
void pb(t_stack **stack_a, t_stack **stack_b);