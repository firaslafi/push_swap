/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 22:06:46 by flafi             #+#    #+#             */
/*   Updated: 2023/09/07 21:27:09 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt_recur(int nb, int i)
{
	if (nb > 2147395600)
		return (0);
	if (i * i == nb)
		return (i);
	if (i * i < nb)
		return (ft_sqrt_recur(nb, i + 1));
	if (nb % i == 0)
		return (i);
	else
		return (i - 1);
	return (0);
}

int	ft_sqrt(int nb)
{
	return (ft_sqrt_recur(nb, 0));
}
