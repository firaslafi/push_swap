/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 03:10:59 by flafi             #+#    #+#             */
/*   Updated: 2023/04/13 03:53:29 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_start(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		if (!ft_strchr(set, s1[i]))
			return (i);
		i++;
	}
	return (i);
}

static size_t	ft_end(char const *s1, char const *set)
{
	size_t	i;

	i = ft_strlen(s1) - 1;
	while (s1[i])
	{
		if (!ft_strchr(set, s1[i]))
			return (i);
		i--;
		if (i == 0)
		{
			return (i);
			break ;
		}
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	startpos;
	size_t	endpos;
	size_t	i;
	size_t	j;

	i = 0;
	startpos = ft_start(s1, set);
	endpos = ft_end(s1, set);
	j = startpos;
	if (startpos == ft_strlen(s1) && i == 0)
		return (ft_strdup(""));
	result = malloc(((endpos - startpos) + 2));
	if (!result)
		return (NULL);
	if (ft_strlen(s1) == 0)
		return (result);
	while (i <= (endpos - startpos))
	{
		result[i++] = s1[j++];
	}
	result[i] = '\0';
	return (result);
}
