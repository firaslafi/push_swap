/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 22:46:51 by flafi             #+#    #+#             */
/*   Updated: 2023/09/18 13:35:34 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	// ft_printf("%s\n", str);
	(void)str;
	return (EXIT_FAILURE);
}
