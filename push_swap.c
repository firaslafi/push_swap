/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:31:35 by flafi             #+#    #+#             */
/*   Updated: 2023/08/12 23:17:40 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_vfirst(char c)
{
	if (c == '+' || c == '-')
		return (1);
	if (ft_isdigit(c))
		return (1);
	else
		return (0);
}
int ft_check_initials(char **array)
{
	int i;

	i = 0;
	while(array[i])
	{
		if (!ft_vfirst(array[i][0]))
			return (0);
		i++;
	}
	return (1);
}

int ft_checksign(char *str)
{
	int i;
	
	i = 0;
	while (str[i])
	{
		
		if (str[i] == '+' || str[i]  == '-')
		{
			if (str[i - 1] == ' ' || i == 0)
				i++;
			else
				return (0);
		}
		
	}
}

int ft_isnumber_string(char **argv)
{
	char **array;
	int i;
	int j;
	
	ft_checksign(argv[1]);
	array = ft_split(argv[1], ' ');
	i = 0;
	j = 0;
	
	while(array[i])
	{
		while(array[i][j])
		{
			if (ft_isdigit(array[i][j]))
				j++;
			else
			{printf("Error: %c it is not digit or sign\n", array[i][j]);
				return (0);}
		}
		j = 0 ;
		i++;
	}
	return (1);
}

int ft_fill_array(int count, char **argv)
{
	char **array;
	int i;
	int j;
	char *str;
	
	str = ft_strdup("");
	i = 1;
	while(count--)
	{
		str = ft_strjoin(str, argv[i]);
		str = ft_strjoin(str, " ");
		i++;
	}
	array = ft_split(str, ' ');
	i = 0;
	j = 0;
	while(array[i])
	{
		while(array[i][j])
		{
			if (ft_isdigit(array[i][j]))
				{
					j++;
					
				}
			else
				{printf("Error\n");
				return (0);}
		}
		printf("result = %s\n", array[i]);
		j = 0 ;
		i++;
	}
	i = 0;

	return (1);
}




int main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("Error\n");
		return (0);
	} else if (argc == 2)
	{
		printf("one signle string input\n");
		ft_isnumber_string(argv);
	}
	else 
	{
		printf("multiple input\n");
		ft_fill_array(argc - 1 , argv);
	}
	
	return (0);
}

// check before + or - there is a space