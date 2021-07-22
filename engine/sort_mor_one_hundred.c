/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mor_one_hundred.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarian <jmarian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 03:31:43 by jmarian           #+#    #+#             */
/*   Updated: 2021/07/22 03:31:02 by jmarian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	make_stack_lother(t_all *all, int i)
{
	int	*new;
	int	x;
	int	j;

	x = 0;
	j = 0;
	new = NULL;
	new = ft_calloc_int(new, all->lena);
	while (j != all->lena)
	{
		if (x != i)
		{
			new[j] = all->steck[x];
			j++;
		}
		x++;
	}
	free(all->steck);
	all->steck = new;
}

int	wich_one(int i, int j, int sum, t_all *all)
{
	if (i < sum && j < sum)
	{
		if (i < j)
		{
			make_stack_lother(all, i);
			return (i);
		}
		else if (j < i)
		{
			make_stack_lother(all, j);
			return (j);
		}
	}
	else if (i > sum && j < sum)
	{
		if (((all->len_full + 1) - i) < j)
		{
			make_stack_lother(all, i);
			return (i - (all->len_full + 1));
		}
		else if (((all->len_full + 1) - i) > j)
		{
			make_stack_lother(all, j);
			return (j);
		}
	}
	else if (i < sum && j > sum)
	{
		if (i < ((all->len_full + 1) - j))
		{
			make_stack_lother(all, i);
			return (i);
		}
		else if (((all->len_full + 1) - j) < i)
		{
			make_stack_lother(all, j);
			return (j - (all->len_full + 1));
		}
	}
	else
	{
		if (i > j)
		{
			make_stack_lother(all, i);
			return (i - (all->len_full + 1));
		}
		else
		{
			make_stack_lother(all, j);
			return (j - (all->len_full + 1));
		}
	}
	return (0);
}

void	ft_one_hundred_num(t_all *all, int len)
{
	int	i;

	organaizer(all);
	while(all->steck[0] != all->num[all->i])
		all->i++;
	if (0 + 1 < all->len_full)
		while(all->steck[all->check + 1] != all->num[all->j])
			all->j++;
	else
		all->j = all->i;
	i = ((all->len_full + 1) / 2);
	i = wich_one(all->i, all->j , i, all);
	if (i >= 0)
	{
		while (i != 0)
		{
			all->num = ra(all->num, len);
			i--;
		}
	}
	else if (i <= 0)
	{
		while (i < -1)
		{
			all->num = rra(all->num, len);
			i++;
		}
	}
	pb(all, all->lenb);
	while (all->lena != 1)
	{
		all->check++;
		ft_one_hundred_num(all, len);
	}
}
