/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:25:47 by flafi             #+#    #+#             */
/*   Updated: 2023/04/14 01:47:41 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	int				i;
	unsigned char	chr;

	chr = (unsigned char) c;
	i = 0;
	while (len--)
	{
		((unsigned char *) s)[i] = chr;
		i++;
	}
	return (s);
}
