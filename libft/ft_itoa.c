/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 03:10:19 by flafi             #+#    #+#             */
/*   Updated: 2023/04/14 23:31:30 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nalloc(int n)
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

static void	fill_num(char *s, int i, int n)
{
	while (n > 0)
	{
		s[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
}

static char	*ft_finish(char *s, int num_to_alloc, int sign)
{
	s[num_to_alloc + (sign < 0)] = '\0';
	if (sign == -1)
	{
		s[0] = '-';
		return (s);
	}
	return (s);
}

char	*ft_itoa(int n)
{
	int		sign;
	int		i;
	char	*s;

	i = 0;
	sign = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == -0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		sign *= -1;
		n *= sign;
	}
	if (n == 1 || sign > 0)
		s = malloc(ft_nalloc(n) + 1);
	else
		s = malloc(ft_nalloc(n) + 2);
	if (!s)
		return (NULL);
	i = ft_nalloc(n) - (sign > 0);
	fill_num(s, i, n);
	return (ft_finish(s, ft_nalloc(n), sign));
}
