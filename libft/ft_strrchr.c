/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:48:18 by flafi             #+#    #+#             */
/*   Updated: 2023/04/13 03:42:22 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*ptr;

	len = ft_strlen(s);
	ptr = NULL;
	while (len >= 0)
	{
		if (s[len] == (char) c)
		{
			ptr = (char *) &s[len];
			return (ptr);
		}
		else
		len--;
	}
	return (ptr);
}
