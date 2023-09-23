/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:01:19 by flafi             #+#    #+#             */
/*   Updated: 2023/04/14 01:59:06 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int	i;

	i = 0;
	while (n--)
	{
		if (((unsigned char *) s1)[i] == ((unsigned char *) s2)[i])
			i++;
		else
			return (((unsigned char *) s1)[i] - ((unsigned char *) s2)[i]);
	}
	return (0);
}
