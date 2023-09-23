/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:45:09 by flafi             #+#    #+#             */
/*   Updated: 2023/04/16 00:26:22 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*tmp_node;
	t_list	**tail;

	result = NULL;
	tail = &result;
	if (lst == NULL)
		return (NULL);
	while (lst)
	{
		tmp_node = (t_list *) malloc(sizeof(t_list));
		if (tmp_node == NULL)
		{
			ft_lstclear(&tmp_node, del);
			return (NULL);
		}
	tmp_node->content = f(lst->content);
	tmp_node->next = NULL;
	*tail = tmp_node;
	tail = &(tmp_node->next);
	lst = lst->next;
	}
	return (result);
}
