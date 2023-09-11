/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 03:09:14 by flafi             #+#    #+#             */
/*   Updated: 2023/05/12 00:02:17 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_format(char c, va_list ptr, int *count)
{
	int	i;

	i = 0;
	if (c == '%')
	{
		ft_putchar_fd('%', 1);
		(*count)++;
	}
	else if (c == 'c')
		ft_print_char(ptr, count);
	else if (c == 's')
		return (*count + ft_print_string(ptr));
	else if (c == 'p')
		return (ft_print_pointer(ptr, 'x', count));
	else if (c == 'u')
		return (ft_print_unsigned(ptr, count));
	else if (c == 'i' || c == 'd')
		return (ft_print_digit(ptr, count));
	else if (c == 'x' || c == 'X')
		return (ft_hexa_digit_integer(ptr, c, count));
	return ((*count) + i);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	ptr;

	i = 0;
	count = 0;
	va_start(ptr, s);
	while (s[i])
	{
		if (s[i] != '%')
		{
			ft_putchar_fd(s[i], 1);
			i++;
			count++;
		}
		else
		{
			i++;
			count = check_format(s[i], ptr, &count);
			i++;
		}
	}
	va_end(ptr);
	return (count);
}
