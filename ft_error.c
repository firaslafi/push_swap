/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 22:46:51 by flafi             #+#    #+#             */
/*   Updated: 2023/09/23 18:22:02 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	(void)str;
	return (EXIT_FAILURE);
}

int	ft_errorx(char *str)
{
	ft_putstr_fd("Error\n", 2);
	(void)str;
	exit(0);
	return (EXIT_FAILURE);
}
