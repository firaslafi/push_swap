/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:02:04 by flafi             #+#    #+#             */
/*   Updated: 2023/09/18 18:46:45 by flafi            ###   ########.fr       */
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
	if (((*str == '+') && (str[i + 1] == '\0')) || ((*str == '-') && (str[i
					+ 1] == '\0')))
		ft_error("bb");
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i - 1] != ' ' && i != 0)
			{
				ft_error("Sign problem");
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int	ft_issorted(t_tab *tab)
{
	int	i;

	i = 1;
	while (i < tab->len)
	{
		if (tab->array[i - 1] > tab->array[i])
		{
			return (0);
		}
		i++;
	}
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
		if (tab->array[i] < -2147483648 || tab->array[i] > 2147483647)
		{
			ft_error("int out of boundries!\n");
			exit(1);
		}
		j = i + 1;
		while (j < tab->len)
		{
			if (tab->array[i] == tab->array[j])
			{
				ft_error("duplicate found!");
				exit(1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	is_sorted(t_stack *stack_a)
{
	t_stack	*stack_aa;

	stack_aa = stack_a;
	while (stack_aa->next)
	{
		if (stack_aa->index > stack_aa->next->index)
			return (0);
		stack_aa = stack_aa->next;
	}
	return (1);
}
