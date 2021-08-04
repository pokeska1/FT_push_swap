/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soft_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarian <jmarian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 22:05:48 by jmarian           #+#    #+#             */
/*   Updated: 2021/08/02 23:34:07 by jmarian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_min(int *num, int len)
{
	int	i;
	int	buf;
	int	j;

	i = 0;
	j = 0;
	buf = 10000000;
	while (i != len)
	{
		if (num[i] < buf)
		{
			buf = num[i];
			j = i;
		}
		i++;
	}
	return (j);
}

int	ft_more_nide(int *num, int len, int numer)
{
	int	i;
	int	buf;
	int	j;

	i = 0;
	j = 0;
	buf = 10000000;
	while (i != len)
	{
		if (num[i] < buf && num[i] > numer)
		{
			buf = num[i];
			j = i;
		}
		i++;
	}
	return (j);
}

// если numb[0] самое большое число то 2 если меньшее 0  нето не другое 1
int	ft_min_max_midl(t_all *all)
{
	organaizer(all);
	if (all->numb[0] > all->num[0] && all->numb[0] > all->num[1]
		&& all->numb[0] > all->num[2])
		return (2);
	if (all->numb[0] < all->num[0] && all->numb[0] < all->num[1]
		&& all->numb[0] < all->num[2])
		return (0);
	organaizer(all);
	return (1);
}

int	is_digit_char(char c)
{
	if (c < 48 || c > 57)
	{
		if (c == '-')
			return (1);
		else
			return (0);
	}
	return (1);
}

void	organaizer(t_all *all)
{
	all->i = 0;
	all->j = 0;
	all->result = 0;
}
