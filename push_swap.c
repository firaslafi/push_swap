/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:31:35 by flafi             #+#    #+#             */
/*   Updated: 2023/09/18 18:46:24 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to create a new node
t_stack	*ft_createnode(int data)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (new_node)
	{
		new_node->data = data;
		new_node->next = NULL;
		new_node->index = 0;
	}
	return (new_node);
}

// fn insert a node at the end
void	ft_insert_node(t_stack **head, int data, int tmp)
{
	t_stack	*new_node;
	t_stack	*current;

	new_node = ft_createnode(data);
	if (!new_node)
	{
		ft_putstr_fd("Memory allocation failed!", 1);
		exit(0);
	}
	if (tmp == 0)
	{
		*head = new_node;
	}
	else
	{
		current = *head;
		while (current->next)
		{
			current = current->next;
		}
		current->next = new_node;
	}
}

// filling stack a obviously
void	ft_fill_stacka(t_stack **head, t_tab *tab)
{
	int	i;

	i = 0;
	while (tab->len > i)
	{
		ft_insert_node(head, (int)tab->array[i], i);
		i++;
	}
}

void	ft_alloc_sort(t_tab *tab, t_stack *stacks)
{
	ft_fill_stacka(&stacks->a, tab);
	ft_copynmatch(tab, stacks->a);
	stacks->size = tab->len;
	stacks->b = NULL;
	if (stacks->size == 2)
	{
		sa(stacks->a);
	}
	else if (stacks->size == 4)
	{
		sorting_4(stacks);
	}
	else if (stacks->size == 3)
		ft_casethree(&stacks->a);
	else if (stacks->size == 5)
		sort_stack_5(&stacks->a, &stacks->b, stacks->size);
	else
	{
		k_sort1(stacks, stacks->size);
		k_sort2(stacks, stacks->size);
	}
}

int	main(int argc, char **argv)
{
	t_tab	*tab;
	t_stack	stacks;

	if (argc < 2)
		exit(1);
	tab = (struct s_tab *)malloc(sizeof(struct s_tab));
	if (!tab)
		return (0);
	if (argc == 2)
	{
		ft_isnumber_onestring(argv, tab);
		ft_fillarr_onestr(argv, tab);
	}
	if (argc > 2)
	{
		ft_isnumber_array(argc - 1, argv, tab);
		ft_fillarr_array(argv, tab);
	}
	ft_alloc_sort(tab, &stacks);
	return (0);
}

// ft_print_stk(stacks->a);
// ft_print_stk(stacks->b);
// free_stack(&stacks.a);
// ft_print_stk(stacks->a);
// free_stack(&stacks->b);
// free(stacks);
// free(tab->array);
// free(tab);
// system("leaks push_swap");

// void	free_stack(t_stack **stack)
// {
// 	t_stack	*tmp;

// 	if (!stack || !(*stack))
// 		return ;
// 	while ((*stack)->next)
// 	{
// 		tmp = (*stack)->next;
// 		free(*stack);
// 		*stack = tmp;
// 	}
// 	*stack = NULL;
// }
// free_stack(&stacks->a);
// free_stack(&stacks->b);
// free(stacks);
// void	free_stack(t_stack **stack)
// {
// 	t_stack	*tmp;

// 	if (!stack || !(*stack))
// 		return ;
// 	while ((*stack)->next)
// 	{
// 		tmp = (*stack)->next;
// 		free(*stack);
// 		*stack = tmp;
// 	}
// 	*stack = NULL;
// }
/**************************************/
/*void	ft_print_stk(t_stack *stk)
{
	t_stack	*tmp;

	if (stk == NULL || stk == NULL)
	{
		ft_printf("!Stack\n");
		return ;
	}
	tmp = stk;
	ft_printf("Stack nodes:\n");
	while (tmp != NULL)
	{
		ft_printf("Number: %i ===> Index: %i\n", tmp->data, tmp->index);
		tmp = tmp->next;
	}
}*/
/**************************************/