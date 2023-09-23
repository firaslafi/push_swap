/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 00:05:47 by flafi             #+#    #+#             */
/*   Updated: 2023/07/24 20:33:26 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	void			*ptr;
	unsigned char	chr;
	int				i;
	int				len;

	len = ft_strlen(s) + 1;
	ptr = ft_calloc(len, 1);
	if (!ptr)
		return (free(ptr), NULL);
	i = 0;
	while (len--)
	{
		chr = (unsigned char) s[i];
		((unsigned char *) ptr)[i] = chr;
		i++;
	}
	return ((char *) ptr);
}
