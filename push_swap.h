/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:47:17 by flafi             #+#    #+#             */
/*   Updated: 2023/08/19 00:18:47 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <limits.h>

# include "../libft/libft.h"


	
	typedef struct s_node
	{
		int	data;
		struct s_node	*next;
		struct s_node	*prev;

	}	t_node;


typedef struct s_tab
{
	int	len;
	long long	*array;
}	t_tab;

long long	ft_atol(const char *str);