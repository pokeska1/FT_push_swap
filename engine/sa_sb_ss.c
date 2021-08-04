/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarian <jmarian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 12:57:32 by jmarian           #+#    #+#             */
/*   Updated: 2021/08/04 02:09:44 by jmarian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*rrb(int *num, int len)
{
	int	*mimik;
	int	i;
	int	j;

	ft_write("rrb\n");
	mimik = NULL;
	i = 0;
	j = 1;
	mimik = ft_calloc_int(mimik, len);
	mimik[0] = num[len - 1];
	while (j < len)
	{
		mimik[j] = num [i];
		i++;
		j++;
	}
	free(num);
	//num = ft_strcpy_int(mimik, len);
	return (mimik);
}

int	*rra(int *num, int len)
{
	int	*mimik;
	int	i;
	int	j;

	ft_write("rra\n");
	mimik = NULL;
	i = 0;
	j = 1;
	mimik = ft_calloc_int(mimik, len);
	mimik[0] = num[len - 1];
	while (j < len)
	{
		mimik[j] = num [i];
		i++;
		j++;
	}
	free(num);
	return (mimik);
}

int	*rb(int	*num, int len)
{
	int	*mimik;
	int	i;
	int	j;

	ft_write("rb\n");
	mimik = NULL;
	i = 1;
	j = 0;
	mimik = ft_calloc_int(mimik, len);
	mimik[len - 1] = num [0];
	while (j < len - 1)
	{
		mimik[j] = num [i];
		i++;
		j++;
	}
	if (num)
		free(num);
	return (mimik);
}

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
