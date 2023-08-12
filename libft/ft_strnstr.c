/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 03:33:18 by flafi             #+#    #+#             */
/*   Updated: 2023/04/13 03:45:58 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_length;
	size_t	i;
	size_t	j;

	needle_length = ft_strlen(needle);
	i = -1;
	if (needle_length == 0)
		return ((char *)haystack);
	if (ft_strlen(haystack) < needle_length || len < needle_length)
		return (NULL);
	while (++i < len - needle_length + 1)
	{
		if (haystack[i] == needle[0])
		{
			j = -1;
			while (++j < needle_length)
			{
				if (haystack[i + j] != needle[j])
					break ;
			}
			if (j == needle_length)
				return ((char *)(haystack + i));
		}
	}
	return (NULL);
}
