/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_arg_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 20:57:36 by flafi             #+#    #+#             */
/*   Updated: 2023/09/10 23:53:35 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
				exit(1);
			}
		}
		j = 0;
		i++;
	}
	return (free_split(array), tab->len = i, 1);
}

// fillin struct array case one str
int	ft_fillarr_onestr(char **argv, t_tab *tab)
{
	int		i;
	char	**str;

	str = ft_split(argv[1], ' ');
	tab->array = (long *)malloc((sizeof(long) * tab->len));
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
	free_split(str);
	return (1);
}
