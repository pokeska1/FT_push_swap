/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarian <jmarian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 21:38:06 by jmarian           #+#    #+#             */
/*   Updated: 2021/08/07 00:18:27 by jmarian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_make_sort_stek(t_all *all, int len)
{
//	int			*steck;
	
	long int	x;

	organaizer(all);
	// steck = NULL;
	// steck = ft_calloc_int(steck, len);
	// all->i = ft_min(all->num, len);
	// steck[all->j] = all->num[all->i];
//	all->i = 0;
	x = 0;// 1
	/*
	steck[all->j] = all->num[all->i];
	
	while (all->i != len - 1)
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
			
		if((all->i + 1 != len) && steck[all->j] > all->num[all->i])
		{
			steck[all->j + 1] = steck[all->j];
			steck[all->j] = all->num[all->i];
			all->i = 0;
			all->j++;
		}
		all->i++;
	}
	*/
	int *mimik;

	mimik = NULL;
	if (all->lena == all->len_full || all->lena == 0)
	{
		all->steck = ft_calloc_int(all->steck, len);
		while (x < len)
		{
			all->steck[x] = all->num[x];
			x++;
		}
		while (all->i !=  len - 1)
		{
			if ((all->i + 1 !=  len - 1) && all->steck[all->i] > all->steck[all->i + 1])
			{
				x =	all->steck[all->i];
				all->steck[all->i] = all->steck[all->i + 1];
				all->steck[all->i + 1] = x;
				all->i = 0;
			}
			else
				all->i++;
			if ((all->i ==  len - 1) && all->steck[all->i] < all->steck[all->i - 1])
			{
				x =	all->steck[all->i];
				all->steck[all->i] = all->steck[all->i - 1];
				all->steck[all->i - 1] = x;
				all->i = 0;
			}
		}
	}
	else
	{
		int y;

		y = 0;
		mimik = ft_calloc_int(mimik, all->lena);
		while (x < all->lena)
		{
			if (all->steck[y] != all->numb[0])
			{
				mimik[x] = all->steck[y];
				x++;
			}
			y++;
		}
		free(all->steck);
		all->steck = NULL;
		all->steck = ft_strcpy_int(mimik, all->lena);
	}
}
