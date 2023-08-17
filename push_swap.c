/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:31:35 by flafi             #+#    #+#             */
/*   Updated: 2023/08/17 21:05:25 by flafi            ###   ########.fr       */
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
	printf("len=%i\n", tab->len);
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
int	ft_fillarr_onestr(int argc, char **argv, t_tab *tab)
{
	int		i;
	char	**str;

	str = ft_split(argv[1], ' ');
	tab->array = (int *)malloc((sizeof(int) * tab->len));
	if (!tab->array)
		return (0);
	i = 0;
	while (str[i])
	{
		tab->array[i] = ft_atoi(str[i]);
		i++;
	}
	i = 0;
	while (tab->array[i])
	{
		printf("tab=%i\n", tab->array[i]);
		i++;
	}
	return (1);
}
// fillin struct array case not one str
int	ft_fillarr_array(int argc, char **argv, t_tab *tab)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	tab->array = (int *)malloc((sizeof(int) * tab->len));
	if (!tab->array)
		return (0);
	while (argv[i])
	{
		tab->array[j] = ft_atoi(argv[i]);
		i++;
		j++;
	}
	tab->len = j;
	j = 0;
	return (1);
	// finish tomorrow
}
int	ft_checkduplicate_limit(t_tab *tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < tab->len - 1)
	{
		if (tab->array[i] < INT_MIN || tab->array[i] > INT_MAX)
			{
				printf("int out of boundries!\n");
				return (0); 
			}
		j = i + 1;
		while (j < tab->len)
		{
			if (tab->array[i] == tab->array[j])
				{
					printf("duplicate found!\n");
					return (0); 
				}
			j++;
		}
		i++;
	}
	return (1); 
}
					
int	main(int argc, char **argv)
{
	t_tab	*tab;

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
		ft_fillarr_onestr(argc, argv, tab);
	}
	if (argc > 2)
	{
		printf("multiple input\n");
		ft_isnumber_array(argc - 1, argv);
		ft_fillarr_array(argc, argv, tab);
	}
	ft_checkduplicate_limit(tab);
	return (0);
}
