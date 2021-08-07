/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarian <jmarian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 12:57:32 by jmarian           #+#    #+#             */
/*   Updated: 2021/08/07 02:05:00 by jmarian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*sa(int *str)
{
	int	i;
	int	mimik;
	int	remimik;

	ft_write("sa\n");
	i = 0;
	mimik = str[0];
	remimik = str[1];
	str[0] = remimik;
	str[1] = mimik;
	return (str);
}

int	*sb(int *str)
{
	int	i;
	int	mimik;
	int	remimik;

	ft_write("sb\n");
	i = 0;
	if (!str[i])
		return (str);
	mimik = str[0];
	remimik = str[1];
	str[0] = remimik;
	str[1] = mimik;
	return (str);
}

void	ss(int *stra, int *strb)
{
	int	flag;

	flag = 1;
	write(1, "ss", 2);
	write(1, "\n", 1);
	stra = sa(stra);
	strb = sb(strb);
}
