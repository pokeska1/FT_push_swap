/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarian <jmarian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 21:38:06 by jmarian           #+#    #+#             */
/*   Updated: 2021/07/22 03:14:38 by jmarian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_five_hundred_num(t_all *all, int len)
{
	(void)all;
	(void)len;
}

void	ft_make_sort_stek(t_all *all, int len)
{
	int	*steck;
	int	x;

	organaizer(all);
	steck = NULL;
	steck = ft_calloc_int(steck, len);
	all->i = ft_min(all->num, len);
	steck[all->j] = all->num[all->i];
	all->i = 0;
	x = 1;
	while (all->j != len - 1)
	{
		if (steck[all->j] + x == all->num[all->i] && all->i != len)
		{
			all->j++;
			steck[all->j] = all->num[all->i];
			all->i = 0;
			x = 1;
		}
		else if(all->i == len)
		{
			all->i = 0;
			x++;
		}
		else
			all->i++;
	}
	all->steck = ft_strcpy_int(steck, len);
}
