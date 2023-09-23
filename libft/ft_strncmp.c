/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:56:28 by flafi             #+#    #+#             */
/*   Updated: 2023/04/13 03:26:58 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	chr1;
	unsigned char	chr2;

	while (n--)
	{
	chr1 = (unsigned char) *s1;
	chr2 = (unsigned char) *s2;
		if (chr1 == chr2 && *s1 != '\0')
		{
			s1++;
			s2++;
		}
		else
			return (chr1 - chr2);
	}
	return (0);
}
