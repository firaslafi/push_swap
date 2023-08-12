/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:14:18 by flafi             #+#    #+#             */
/*   Updated: 2023/04/13 03:12:16 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	init_dstsize;

	init_dstsize = ft_strlen(dst);
	i = 0;
	j = init_dstsize;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && j < (dstsize - 1))
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	if (i < dstsize)
		dst[j] = '\0';
	if (init_dstsize < dstsize)
		return (init_dstsize + ft_strlen(src));
	else
		return (dstsize + ft_strlen(src));
}
