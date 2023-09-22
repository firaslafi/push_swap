/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:04:47 by flafi             #+#    #+#             */
/*   Updated: 2023/09/22 21:43:52 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "./push_swap.h"
# include "get_next_line.h"

void	rr_checker(t_stack **stacka, t_stack **stackb);
void	ss_checker(t_stack *stack_a, t_stack *stack_b);
void	rrr_checker(t_stack **stacka, t_stack **stackb);
int		ft_fillarr_onestr_chc(char **argv, t_tab *tab);
int		ft_fillarr_array_chc(char **argv, t_tab *tab);
void	ft_fill_stacka_checker(t_stack **head, t_tab *tab);
int		is_sorted_checker(t_stack *stack_a);
void	ft_error_checker(void);
void	check_sorted_andprint(t_stack stacks);
#endif