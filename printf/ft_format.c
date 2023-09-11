/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 03:31:18 by flafi             #+#    #+#             */
/*   Updated: 2023/05/12 01:45:56 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_num(int n)
{
	int	i;

	if (n < 0)
		n = -n;
	i = 0;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

int	ft_print_char(va_list ptr, int *count)
{
	ft_putchar_fd(va_arg(ptr, int), 1);
	*count += 1;
	return (*count);
}

int	ft_print_string(va_list ptr)
{
	return (ft_putstr_fd(va_arg(ptr, char *), 1));
}

int	ft_print_digit(va_list ptr, int *count)
{
	int	num;

	num = va_arg(ptr, int);
	ft_putnbr_fd(num, 1);
	if (num == -2147483648)
	{
		return ((*count) + 11);
	}
	if (num >= 0)
		return ((*count) + ft_num(num));
	else
		return ((*count) + ft_num(num) + 1);
}

int	ft_print_unsigned(va_list ptr, int *count)
{
	unsigned int	num;
	int				len;

	num = va_arg(ptr, unsigned int);
	ft_putnbr_fd_unsigned(num, 1);
		len = 0;
	while (num > 9)
	{
		num = num / 10;
		len++;
	}
	return ((*count) + len + 1);
}
