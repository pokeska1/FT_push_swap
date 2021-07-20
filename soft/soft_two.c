/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soft_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarian <jmarian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 21:40:30 by jmarian           #+#    #+#             */
/*   Updated: 2021/07/21 01:44:56 by jmarian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			if (str[i] == '-' && (str[i + 1] < 48 || str[i  + 1] > 57))
				return(0);
		i++;
	}
	return(1);
}

void	ft_write(char *str)
{
	int	i;

	i = ft_strlen(str);
	write(1, str, i);
}

int	*ft_calloc_int(int *num, int len)
{
	int	i;

	num = malloc(sizeof(int) * len);
	i = 0;
	while (i != len)
	{
		num[i] = 0;
		i++;
	}
	return(num);
}

int	ft_rra_or_ra_numb(int i, int len)
{
	len /= 2;
	if (i > len)
		return(1);
	return(0);
}

int	ft_rra_or_ra(t_all *all, int i)
{
	int	len;

	len = all->len_full;
	len /= 2;
	if (i > len)
		return(1);
	return(0);
}

void	organaizer(t_all *all)
{
	all->i = 0;
	all->j = 0;
}
