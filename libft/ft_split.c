/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:26:52 by flafi             #+#    #+#             */
/*   Updated: 2023/04/16 02:38:11 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	if (len == 0)
		return (dst);
	while (len--)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

static size_t	word_count(char const *s, char c)
{
	size_t	i;
	size_t	wc;

	i = 0;
	wc = 0;
	if (s[0] == '\0')
		return (0);
	if (s[i] != c)
		wc++;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			if (s[i] == '\0')
				break ;
			wc++;
		}
		i++;
	}
	return (wc);
}

static size_t	word_len(const char *s, size_t i, char c)
{
	size_t	len;

	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

static char	**copy_free(char *chr, char **ptr, char const *s, char c)
{
	int	index;
	int	wl;
	int	i;

	index = 0;
	i = 0;
	while (index < (int)word_count(s, c))
	{
		wl = word_len(s, i, c);
		chr = (char *)malloc((wl + 1) * sizeof(char));
		if (chr == NULL)
		{
			while (index--)
				free(ptr[index]);
			free(ptr);
			return (NULL);
		}
		while (s[i] == c)
			i++;
		ft_strncpy(chr, &s[i], wl);
		chr[wl] = '\0';
		i += wl;
		ptr[index++] = chr;
	}
	return (ptr[index] = NULL, ptr);
}

char	**ft_split(char const *s, char c)
{
	char	*chr;
	char	**ptr;
	int		wc;

	chr = NULL;
	if (!s)
		return (NULL);
	wc = word_count(s, c);
	ptr = (char **)malloc((wc + 1) * sizeof(char *));
	if (ptr == NULL)
		return (NULL);
	return (copy_free(chr, ptr, s, c));
}
