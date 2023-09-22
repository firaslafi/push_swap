/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_arg_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 20:58:57 by flafi             #+#    #+#             */
/*   Updated: 2023/09/22 21:30:32 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
int	ft_nb_arr_helper(char **array, t_tab *tab)
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
				ft_error("Invalid numerical input");
				exit(0);
			}
		}
		j = 0;
		i++;
	}
	tab->len = i;
	return (1);
}

// handling the validation of the input when it is not a single string
int	ft_isnumber_array(int count, char **argv, t_tab *tab)
{
	char	**array;
	char	*str;

	str = ft_fill_str(count, argv);
	if (!ft_checksign(str))
		return (0);
	array = ft_split(str, ' ');
	ft_nb_arr_helper(array, tab);
	free_split(array);
	return (free(str), 1);
}

// fillin struct array case not one str
int	ft_fillarr_array(char **argv, t_tab *tab)
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
	if (ft_issorted(tab))
		exit(0);
	return (1);
}
