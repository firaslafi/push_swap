/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:48:09 by flafi             #+#    #+#             */
/*   Updated: 2023/08/01 22:42:15 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	counter;

	if (!s)
		return (0);
	counter = 0;
	while (s[counter])
	{
		counter++;
	}
	return (counter);
}

void	*ft_calloc(size_t nelem, size_t elemsize)
{
	void	*ptr;

	ptr = malloc(nelem * elemsize);
	if (!ptr)
		return (NULL);
	if (ptr)
		ft_bzero(ptr, (nelem * elemsize));
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	int	i;

	i = 0;
	while (n--)
	{
		((unsigned char *) s)[i] = (char) '\0';
		i++;
	}
}

char	*ft_strdup(const char *s)
{
	void			*ptr;
	unsigned char	chr;
	int				i;
	int				len;

	len = ft_strlen(s) + 1;
	ptr = ft_calloc(len, 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (len--)
	{
		chr = (unsigned char) s[i];
		((unsigned char *) ptr)[i] = chr;
		i++;
	}
	return ((char *) ptr);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
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
