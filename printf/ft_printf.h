/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 01:23:54 by flafi             #+#    #+#             */
/*   Updated: 2023/08/04 21:05:43 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

void	ft_convert_hexa(unsigned long num, char format);
int		ft_printf(const char *c, ...);
int		ft_p_hexa(va_list ptr);
int		ft_print_char(va_list ptr, int *count);
int		ft_print_string(va_list ptr);
int		ft_print_digit(va_list ptr, int *count);
int		ft_print_unsigned(va_list ptr, int *count);
int		ft_putnbr_fd_unsigned(unsigned int n, int fd);
int		ft_decimaltohexadecimal(unsigned long long decimal,
			char format, int *count);
int		ft_hexa_digit_integer(va_list ptr, char format, int *count);
int		ft_print_pointer(va_list ptr, char format, int *count);
#endif