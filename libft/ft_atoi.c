/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 22:54:23 by flafi             #+#    #+#             */
/*   Updated: 2023/04/16 03:46:07 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(const char *str)
{
	if (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\f'
		|| *str == '\r' || *str == '\v')
		return (1);
	return (0);
}

static int	ft_issign(const char *str)
{
	if (*str == '-' || *str == '+')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (ft_isspace(str))
	{
		str++;
	}
	if (ft_issign(str))
	{
		if (*str == '-')
		{
		sign *= -1;
		str++;
		}
		else
			str++;
	}
	while (ft_isdigit(*str))
	{
	result = result * 10 + *str - '0';
	str++;
	}
	return (result * sign);
}
