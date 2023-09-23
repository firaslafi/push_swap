/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 04:26:00 by flafi             #+#    #+#             */
/*   Updated: 2023/04/12 18:11:37 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elemsize)
{
	void	*ptr;

	ptr = malloc(nelem * elemsize);
	if (ptr)
		ft_bzero(ptr, (nelem * elemsize));
	return (ptr);
}
