/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:31:35 by flafi             #+#    #+#             */
/*   Updated: 2023/09/10 23:39:34 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to create a new node
t_stack	*ft_createnode(int data)
{
	t_stack	*newNode;

	newNode = (t_stack *)malloc(sizeof(t_stack));
	if (newNode)
	{
		newNode->data = data;
		newNode->next = NULL;
	}
	return (newNode);
}

// fn insert a node at the end
void	ft_insert_node(t_stack **head, int data, int tmp)
{
	t_stack	*newNode;
	t_stack	*current;

	newNode = ft_createnode(data);
	if (!newNode)
	{
		printf("Memory allocation failed!\n");
		return ;
	}
	if (tmp == 0)
	{
		*head = newNode;
	}
	else
	{
		current = *head;
		while (current->next)
		{
			current = current->next;
		}
		current->next = newNode;
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
void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while ((*stack)->next)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}
int	main(int argc, char **argv)
{
	t_tab		*tab;
	t_stacks	*stacks;

	if (argc < 2)
	{
		printf("Error\n");
		return (0);
	}
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
	ft_checkduplicate_limit(tab);
	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (!stacks)
		exit(1);
	ft_fill_stacka(&stacks->a, tab);
	stacks->b = malloc(sizeof(t_stack));
	ft_copynmatch(tab, stacks->a);
	stacks->size = tab->len;
	// free(tab->array);
	// free(tab);
	if (stacks->size == 3)
		ft_casethree(&stacks->a);
	else if (stacks->size == 5)
		sort_stack_5(&stacks->a, &stacks->b, stacks->size);
	else
	{
		k_sort1(stacks, stacks->size);
		k_sort2(stacks, stacks->size);
	}
	// free_stack(&stacks->a);
	// free_stack(&stacks->b);
	// free(stacks);
	system("leaks push_swap");
	return (0);
}
