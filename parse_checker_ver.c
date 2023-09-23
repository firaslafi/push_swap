/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_checker_ver.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 20:30:26 by flafi             #+#    #+#             */
/*   Updated: 2023/09/22 21:07:59 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// fillin struct array case one str
int	ft_fillarr_onestr_chc(char **argv, t_tab *tab)
{
	int		i;
	char	**str;

	str = ft_split(argv[1], ' ');
	if (!*argv[1])
		ft_error("e\n");
	tab->array = (long *)malloc((sizeof(long) * tab->len));
	if (!tab->array)
		return (0);
	i = 0;
	while (str[i])
	{
		tab->array[i] = ft_atol(str[i]);
		i++;
	}
	tab->array[i] = '\0';
	ft_checkduplicate_limit(tab);
	free_split(str);
	return (1);
}

int	ft_fillarr_array_chc(char **argv, t_tab *tab)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	tab->array = malloc((sizeof(long) * (tab->len)));
	if (!tab->array)
		exit(0);
	while (argv[i])
	{
		tab->array[j] = ft_atol(argv[i]);
		i++;
		j++;
	}
	tab->array[j] = '\0';
	ft_checkduplicate_limit(tab);
	return (1);
}

int	is_sorted_checker(t_stack *stack_a)
{
	t_stack	*stack_aa;

	stack_aa = stack_a;
	while (stack_aa->next)
	{
		if (stack_aa->data > stack_aa->next->data)
			return (0);
		stack_aa = stack_aa->next;
	}
	return (1);
}

void	ft_error_checker(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(0);
}

// filling stack a obviously
void	ft_fill_stacka_checker(t_stack **head, t_tab *tab)
{
	int	i;

	i = 0;
	while (tab->len > i)
	{
		ft_insert_node(head, (int)tab->array[i], i);
		i++;
	}
}
