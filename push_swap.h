/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:47:17 by flafi             #+#    #+#             */
/*   Updated: 2023/09/07 21:25:11 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <limits.h>
# include <stdio.h>

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
	long			*array;
}					t_tab;

long				ft_atol(const char *str);
void				swap(t_stack *stack);
void				sa(t_stack *stack_a);
void				sb(t_stack *stack_b);
void				ss(t_stack *stack_a, t_stack *stack_b);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				rotate(t_stack **stack);
void				ra(t_stack **stack);
void				rb(t_stack **stack);
void				rr(t_stack **stacka, t_stack **stackb);
void				rra(t_stack **stack);
void				rrb(t_stack **stack);
void				rrr(t_stack **stacka, t_stack **stackb);
int					ft_sqrt(int nb);
int					ft_isdigitsign(char c);
int					ft_checksign(char *str);
int					ft_issorted(long *array);
int					is_sorted(t_stack *stack_a);
int					ft_checkduplicate_limit(t_tab *tab);
void				k_sort1(t_stacks *stacks, int length);
void				k_sort2(t_stacks *stacks, int length);
int					count_r(t_stack *stack, int index);
void				ft_casethree(t_stack **a);
void				sort_stack_5(t_stack **stack_a, t_stack **stack_b,
						int length);
int					*ft_bubblesort(int *arr, int n);
void				ft_match(int *arr_cpy, t_stack *stack);
void				ft_copynmatch(t_tab *tab, t_stack *stack);
int					ft_isnumber_onestring(char **argv, t_tab *tab);
int					ft_fillarr_array(char **argv, t_tab *tab);
int					ft_isnumber_array(int count, char **argv, t_tab *tab);
int					ft_nb_arr_helper(char **array, t_tab *tab);
char				*ft_fill_str(int count, char **argv);
int					ft_fillarr_onestr(char **argv, t_tab *tab);
#endif