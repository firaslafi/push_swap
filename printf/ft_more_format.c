/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_more_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 21:58:23 by flafi             #+#    #+#             */
/*   Updated: 2023/08/02 21:08:18 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_decimaltohexadecimal(unsigned long long decimal, char format, int *count)
{
	unsigned long long	remainder;

	if (decimal == 0)
		return (1);
	else
	{
		(*count)++;
		remainder = decimal % 16;
		ft_decimaltohexadecimal(decimal / 16, format, count);
		if (remainder < 10)
			ft_putchar_fd(remainder + 48, 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd(remainder + 87, 1);
			else
				ft_putchar_fd(remainder + 55, 1);
		}
	}
	return (*count);
}

int	ft_hexa_digit_integer(va_list ptr, char format, int *count)
{
	unsigned int	number;
	int				i;

	number = (unsigned int)va_arg(ptr, unsigned int);
	if (number == 0)
	{
		ft_putchar_fd('0', 1);
		return ((*count) + 1);
	}
	i = *count;
	ft_decimaltohexadecimal(number, format, &i);
	return (i);
}

int	ft_print_pointer(va_list ptr, char format, int *count)
{
	unsigned long long	pointer;
	int					i;

	i = 0;
	pointer = (unsigned long long)va_arg(ptr, unsigned long long);
	if (!pointer)
	{
		ft_putstr_fd("0x0", 1);
		return ((*count) + 3);
	}
	ft_putstr_fd("0x", 1);
	i = ft_decimaltohexadecimal(pointer, format, &i);
	return ((*count) + i + 2);
}
