/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:31:35 by flafi             #+#    #+#             */
/*   Updated: 2023/09/01 01:04:21 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// checking the is it sign or digit
int	ft_isdigitsign(char c)
{
	if (ft_isdigit(c) || c == '+' || c == '-')
		return (1);
	else
		return (0);
}
// checking the sign +/- , handling i = 0
int	ft_checksign(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i - 1] != ' ' && i != 0)
			{
				printf("Error\n");
				printf("Sign problem\n");
				return (0);
			}
		}
		i++;
	}
	return (1);
}
int	ft_issorted(long long *array)
{
	int	i;

	i = 1;
	while (array[i])
	{
		if (array[i - 1] > array[i])
		{
			printf("not sorted, do stuff!\n");
			return (0);
		}
		i++;
	}
	printf("Stack is Sorted! nothing to do.\n");
	return (1);
}
// handling the validation of the input when it is a single string
int	ft_isnumber_onestring(char **argv, t_tab *tab)
{
	char	**array;
	int		i;
	int		j;

	if (!ft_checksign(argv[1]))
		return (0);
	array = ft_split(argv[1], ' ');
	i = 0;
	j = 0;
	while (array[i])
	{
		while (array[i][j])
		{
			if (ft_isdigitsign(array[i][j]))
				j++;
			else
			{
				printf("Error: %c it is not digit or sign\n", array[i][j]);
				return (0);
			}
		}
		j = 0;
		i++;
	}
	tab->len = i;
	return (1);
}
// filling str to use split on it later on with ' '
char	*ft_fill_str(int count, char **argv)
{
	int		i;
	char	*result;

	i = 1;
	result = ft_strdup("");
	while (count--)
	{
		result = ft_strjoin(result, argv[i]);
		result = ft_strjoin(result, " ");
		i++;
	}
	return (result);
}
// helper function to loop through the splited array
int	ft_nb_arr_helper(char **array)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (array[i])
	{
		while (array[i][j])
		{
			if (ft_isdigitsign(array[i][j]))
				j++;
			else
			{
				printf("Error\n");
				printf("Invalid numerical input\n");
				return (0);
			}
		}
		j = 0;
		i++;
	}
	return (1);
}
// handling the validation of the input when it is not a single string
int	ft_isnumber_array(int count, char **argv)
{
	char	**array;
	char	*str;

	str = ft_fill_str(count, argv);
	if (!ft_checksign(str))
		return (0);
	array = ft_split(str, ' ');
	ft_nb_arr_helper(array);
	return (1);
}
// fillin struct array case one str
int	ft_fillarr_onestr(char **argv, t_tab *tab)
{
	int		i;
	char	**str;

	str = ft_split(argv[1], ' ');
	tab->array = (long long *)malloc((sizeof(long long) * tab->len));
	if (!tab->array)
		return (0);
	i = 0;
	while (str[i])
	{
		tab->array[i] = ft_atol(str[i]);
		i++;
	}
	if (ft_issorted(tab->array))
		exit(0);
	return (1);
}
// fillin struct array case not one str
int	ft_fillarr_array(char **argv, t_tab *tab)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	tab->array = (long long *)malloc((sizeof(long long) * tab->len));
	if (!tab->array)
		return (0);
	while (argv[i])
	{
		printf("before=%s\n", argv[i]);
		tab->array[j] = ft_atol(argv[i]);
		printf("after=%lli\n", tab->array[j]);
		i++;
		j++;
	}
	tab->len = j;
	j = 0;
	if (ft_issorted(tab->array))
		exit(0);
	return (1);
}
// checking for duplicate numbers and INT boundries
int	ft_checkduplicate_limit(t_tab *tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < tab->len)
	{
		if (tab->array[i] < INT_MIN || tab->array[i] > INT_MAX)
		{
			printf("int out of boundries!\n");
			exit(1);
		}
		j = i + 1;
		while (j < tab->len)
		{
			if (tab->array[i] == tab->array[j])
			{
				printf("duplicate found!\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
	return (1);
}
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
void	ft_insertNode(t_stack **head, int data)
{
	t_stack	*newNode;
	t_stack	*current;

	newNode = ft_createnode(data);
	if (!newNode)
	{
		printf("Memory allocation failed!\n");
		return ;
	}
	if (*head == NULL)
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
		// newNode->next = *head;
		// head->prev = newNode;
	}
}
// filling stack a obviously
void	ft_fill_stacka(t_stack **head, t_tab *tab)
{
	int	i;

	i = 0;
	while (tab->len > i)
	{
		ft_insertNode(head, (int)tab->array[i]);
		i++;
	}
}
// bubble sort to set indexs
int	*ft_bubblesort(int *arr, int n)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	int swapped = 1; // Initialize swapped to 1 to enter the loop
	while (i < n - 1 && swapped)
	{
		swapped = 0; // Reset the swapped flag at the beginning of each pass
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				// Swap arr[j] and arr[j + 1]
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = 1; // Set the swapped flag to indicate a swap occurred
			}
			j++;
		}
		i++;
	}
	return (arr);
}
// matching copies and real stack int
void	ft_match(int *arr_cpy, t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (stack->next)
	{
		while (arr_cpy[i])
		{
			if (arr_cpy[i] == stack->data)
			{
				stack->index = i;
				break ;
			}
			i++;
		}
		i = 0;
		stack = stack->next;
		if (!stack->next)
		{
			while (arr_cpy[j])
			{
				if (arr_cpy[j] == stack->data)
				{
					stack->index = j;
					break ;
				}
				j++;
			}
		}
	}
}

// making a copy of the numbers, sorting them
// and setting them to their place + isSorted
void	ft_something(t_tab *tab, t_stack *stack)
{
	int	i;
	int	*arr_cpy;

	i = 0;
	arr_cpy = malloc(tab->len * sizeof(int));
	while (tab->array[i])
	{
		arr_cpy[i] = tab->array[i];
		i++;
	}
	arr_cpy = ft_bubblesort(arr_cpy, tab->len);
	ft_match(arr_cpy, stack);
	free(arr_cpy);
}
// push to fill stack for testing purposes only !!!!!
void	pushh(t_stack **top, int data, int index)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (new_node == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	new_node->data = data;
	new_node->index = index;
	new_node->next = *top;
	*top = new_node;
}
void ft_casethree(t_stack *stack)
{
	if (stack->data > stack->next->data)
}
int	main(int argc, char **argv)
{
	t_tab		*tab;
	t_stack		*head;
	t_stacks	*stacks;
	t_stack		*current;
	t_stack		*stackb;

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
		printf("one signle string input\n");
		ft_isnumber_onestring(argv, tab);
		ft_fillarr_onestr(argv, tab);
	}
	if (argc > 2)
	{
		printf("multiple input\n");
		ft_isnumber_array(argc - 1, argv);
		ft_fillarr_array(argv, tab);
	}
	ft_checkduplicate_limit(tab);
	stacks = (struct s_stacks *)malloc(sizeof(struct s_stacks));
	if (!stacks)
		exit(1);
	stacks->a = NULL;
	stacks->b = NULL;
	head = NULL;
	ft_fill_stacka(&stacks->a, tab);
	// ft_fill_stacka(&head, tab);
	ft_something(tab, stacks->a);
	current = stacks->a;
	stackb = (struct s_stack *)malloc(sizeof(struct s_stack));
	// t_stack *stackc = (struct s_stack *)malloc(sizeof(struct s_stack));
	stackb->data = 0;
	stackb->next = NULL;
	stackb->index = 0;
	pushh(&stackb, 1, 1);
	pushh(&stackb, 2, 2);
	pushh(&stackb, 3, 3);
	pushh(&stackb, 4, 4);
	pushh(&stackb, 5, 5);
	// sa(current);
	// rotate(&stackb);
	// ra(&stackb);
	// pb(&(stacks->a), &stackb);
	// pa(&(stacks->a), &stackb);
	current = head;
	while (current)
	{
		printf("number = %i and index = %i\n", current->data, current->index);
		current = current->next;
	}
	printf("\n");
	return (0);
}
