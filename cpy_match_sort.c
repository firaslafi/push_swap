/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_match_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 23:11:20 by flafi             #+#    #+#             */
/*   Updated: 2023/09/18 18:38:46 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// bubble sort to set indexss
int	*ft_bubblesort(int *arr, int n)
{
	int	temp;
	int	i;
	int	j;
	int	swapped;

	i = 0;
	swapped = 1;
	while (i < n - 1 && swapped)
	{
		swapped = 0;
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = 1;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

void	ft_set_index(int *arr_cpy, t_stack **stack)
{
	int	i;

	i = 0;
	while (arr_cpy[i])
	{
		if (arr_cpy[i] == (*stack)->data)
		{
			(*stack)->index = i;
			break ;
		}
		i++;
	}
}

// matching copies and real stack int
void	ft_match(int *arr_cpy, t_stack *stack, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		while (j < len)
		{
			if (arr_cpy[j] == stack->data)
			{
				stack->index = j;
				break ;
			}
			j++;
		}
		j = 0;
		i++;
		if (stack->next)
			stack = stack->next;
		ft_set_index(arr_cpy, &stack);
	}
}

// making a copy of the numbers, sorting them
// and setting them to their place + isSorted
void	ft_copynmatch(t_tab *tab, t_stack *stack)
{
	int	i;
	int	*arr_cpy;

	i = 0;
	arr_cpy = malloc(tab->len * sizeof(int));
	if (!arr_cpy)
		exit(1);
	while (i < tab->len)
	{
		arr_cpy[i] = tab->array[i];
		i++;
	}
	arr_cpy = ft_bubblesort(arr_cpy, tab->len);
	ft_match(arr_cpy, stack, tab->len);
}

	// free(arr_cpy);