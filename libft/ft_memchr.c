/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:34:20 by flafi             #+#    #+#             */
/*   Updated: 2023/04/16 03:47:48 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cmp(char *s, int c)
{
	if (*s == (char) c)
		return (1);
	else
		return (0);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n--)
	{
		if (ft_cmp((char *)s, c))
			return ((void *)s);
		else
			s++;
	}
	return (NULL);
}
