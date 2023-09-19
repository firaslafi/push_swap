/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:04:38 by flafi             #+#    #+#             */
/*   Updated: 2023/09/19 21:04:14 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "checker.h"

#include "stdio.h"

// *******************************************//
void	ft_print_stk(t_stack *stk)
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
}
// *******************************************//
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

void ft_runmove(char *move, t_stack *stacks)
{
	if (ft_strncmp(move, "ra\n", 3) == 0)
			rotate(&stacks->a);
	else if (ft_strncmp(move, "rb\n", 3) == 0)
			rotate(&stacks->b);
	else if (ft_strncmp(move, "rr\n", 3) == 0)
			rr_checker(&stacks->a, &stacks->b);
	else if (ft_strncmp(move, "pa\n", 3) == 0)
			push(&stacks->b, &stacks->a);
	else if (ft_strncmp(move, "pb\n", 3) == 0)
			push(&stacks->a, &stacks->b);
	else if (ft_strncmp(move, "sa\n", 3) == 0)
			swap(stacks->a);
	else if (ft_strncmp(move, "sb\n", 3) == 0)
			swap(stacks->b);
	else if (ft_strncmp(move, "ss\n", 3) == 0)
			ss_checker(stacks->a, stacks->b);
	else if (ft_strncmp(move, "rra\n", 3) == 0)
			rev_rotate(&stacks->a);
	else if (ft_strncmp(move, "rrb\n", 3) == 0)
			rev_rotate(&stacks->b);
	else if (ft_strncmp(move, "rrr\n", 3) == 0)
			rrr_checker(&stacks->a, &stacks->b);
	else
		{
			printf("incorrect move error!!!!\n");
			exit(0);
		}
}
int read_moves(t_stack *stacks)
{
	char *move;
	int run;
	
	move = get_next_line(0);

	while(move)
	{
		
		// printf("%s", move);
		ft_runmove(move, stacks);
		// ft_print_stk(stacks->a);
		move = get_next_line(0);
	}
	return (0);
}


int main(int argc, char **argv)
{
	t_tab	*tab;
	t_stack	stacks;

	if (argc < 2)
		exit(1);
	tab = (struct s_tab *)malloc(sizeof(struct s_tab));
	if (!tab)
		return (0);
	stacks.b = malloc(sizeof(struct s_stack));
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

	ft_fill_stacka(&stacks.a, tab);
	read_moves(&stacks);
    ft_print_stk(stacks.a);


    return 0;
}
