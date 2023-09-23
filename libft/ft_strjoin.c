/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 04:54:03 by flafi             #+#    #+#             */
/*   Updated: 2023/09/07 23:57:04 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	i;
	size_t	l1;
	size_t	l2;

	if (!s1)
	{
		s1 = (char *) malloc(1 * sizeof(char));
		*s1 = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	result = (char *) malloc(l1 + l2 + 1);
	if (!result)
		return (NULL);
	i = -1;
	while (++i <= l1)
		result[i] = s1[i];
	i = -1;
	while (++i <= l2)
		result[l1 + i] = s2[i];
	return (result[l1 + l2] = '\0', free(s1), result);
}
