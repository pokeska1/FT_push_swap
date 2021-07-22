/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_it_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarian <jmarian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:46:58 by jmarian           #+#    #+#             */
/*   Updated: 2021/07/22 01:05:09 by jmarian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_is_it_valid(t_all *all, int len)
{
	all->i = 0;
	all->j = 0;
	while (all->j != len)
	{
		if (all->j + 1 < len)
			all->i = all->j + 1;
		else
			break ;
		while (all->i != len)
		{
			if (all->num[all->j] == all->num[all->i])
			{
				printf("%d=%d %d=%d", all->j, all->num[all->j], all->i, all->num[all->i]);
				all->error = -1;
				return ;
			}
			all->i++;
		}
		all->j++;
	}
	all->i = len;
	return ;
}

int	ft_numbers_sorted(int *num, int	len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i != len)
	{
		if (i + 1 < len)
			if (num[i] > num[i + 1])
				return (0);
		i++;
	}
	return (1);
}
