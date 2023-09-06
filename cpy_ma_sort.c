/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_ma_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 23:11:20 by flafi             #+#    #+#             */
/*   Updated: 2023/09/06 23:19:22 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// bubble sort to set indexss
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
// void ft_set_index(int *arr_cpy, t_stack *stack)
// {
//     int i;

//     i = 0;
//     while (arr_cpy[i])
//     {
//         if (arr_cpy[i] == stack->data)
//         {
//             stack->index = i;
//             break ;
//         }
//         i++;
//     }
// }
// matching copies and real stack int
void	ft_match(int *arr_cpy, t_stack *stack)
{
	int	i;

	i = 0;
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
			while (arr_cpy[i])
			{
				if (arr_cpy[i] == stack->data)
				{
					stack->index = i;
					break ;
				}
				i++;
			}
		}
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
	while (tab->array[i])
	{
		arr_cpy[i] = tab->array[i];
		i++;
	}
	arr_cpy = ft_bubblesort(arr_cpy, tab->len);
	ft_match(arr_cpy, stack);
	free(arr_cpy);
}