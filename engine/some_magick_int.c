/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_magick_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarian <jmarian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:30:19 by jmarian           #+#    #+#             */
/*   Updated: 2021/07/20 23:22:33 by jmarian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_make_int(int argc, char **argv, t_all *all)
{
	all->i = 0;
	all->j = 1;
	//all->num = (int *)malloc(sizeof(int) * argc);
	all->num = ft_calloc_int(all->num, argc);
	if (!all->num)
	{
		free(all->num);
		all->error = -1;
		return;
	}
	while (all->j != argc)
	{
		if(!is_digit(argv[all->j]))
		{
			free(all->num);
			all->error = -1;
			return;
		}
		all->num[all->i] = ft_atoi(argv[all->j]);
		all->i++;
		all->j++;
	}
}

void	ft_sort_first(int *num, int len)
{
	int	i;

	i = 0;
	while (ft_numbers_sorted(num, len))
	{
		if(num[i] > num[i + 1])
		i++;
	}
	
}

