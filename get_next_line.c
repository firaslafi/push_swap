/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:48:06 by flafi             #+#    #+#             */
/*   Updated: 2023/08/01 22:43:18 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr_gnl(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char) c)
			return (i);
		i++;
	}
	return (0);
}

char	*ft_substr(char **s, unsigned int start, size_t len)
{
	size_t		i;
	char		*str;

	i = 0;
	str = NULL;
	if (!(*s))
		return (NULL);
	if (start >= ft_strlen(*s))
		return (ft_strdup(""));
	if (ft_strlen(*s) - (int)start < len)
		len = ft_strlen(*s) - start;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	while (len-- && (*s)[start])
	{
		str[i++] = (*s)[start++];
	}
	if ((*s)[start] == '\0')
	{
		free(*s);
	*s = NULL;
	}
	str[i] = '\0';
	return (str);
}

int	ft_schr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char) c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_read_line(int *found, int fd, char **tmp)
{
	char		*buff;
	int			size_read;

	size_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(*tmp), *tmp = NULL, -1);
	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (-1);
	while (size_read != 0)
	{
		size_read = read(fd, buff, BUFFER_SIZE);
		if (size_read == -1)
			return (free(buff), free(*tmp), *tmp = NULL, -1);
		buff[size_read] = '\0';
		if (size_read != 0)
			*tmp = ft_strjoin_gnl(*tmp, buff);
		*found = ft_schr(*tmp, '\n');
		if (*found != 0)
			break ;
	}
	free(buff);
	return (size_read);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*line;
	int			found;
	int			size_read;

	found = 0;
	line = NULL;
	size_read = -1;
	size_read = ft_read_line(&found, fd, &tmp);
	if (size_read == -1)
		return (NULL);
	if (size_read == 0 && found == 0)
	{
		if (tmp)
			line = ft_substr(&tmp, 0, ft_strlen(tmp));
		return (free(tmp), tmp = NULL, line);
	}
	line = ft_substr(&tmp, 0, ft_strchr_gnl(tmp, '\n') + 1);
	tmp = ft_substr(&tmp, ft_strchr_gnl(tmp, '\n') + 1,
			(ft_strlen(tmp) - ft_strchr_gnl(tmp, '\n') + 1));
	return (line);
}
