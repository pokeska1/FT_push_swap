/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soft_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarian <jmarian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 22:06:04 by jmarian           #+#    #+#             */
/*   Updated: 2021/08/07 01:45:27 by jmarian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strcpy(char *str)
{
	int		i;
	char	*mimik;

	i = 0;
	mimik = ft_calloc(ft_strlen(str));
	while (str[i])
	{
		mimik[i] = str[i];
		i++;
	}
	free(str);
	return (mimik);
}

int	*ft_strcpy_int(int *num, int len)
{
	int	*sum;
	int	i;

	i = 0;
	sum = NULL;
	sum = ft_calloc_int(sum, len);
	while (i < len)
	{
		sum[i] = num[i];
		i++;
	}
	free(num);
	return (sum);
}

void	ft_grate_start(t_all *all)
{
	all->p.counte = 0;
	all->lena = 0;
	all->error = 0;
	all->i = 0;
	all->j = 0;
	all->check = 0;
	all->len_full = 0;
	all->lena = 0;
	all->lenb = 0;
	all->buf = 0;
	all->maxint = 0;
	all->minimum = 0;
	all->max = 0;
	all->pointer_int = 0;
	all->which_int = 0;
	all->result = 0;
	all->atoi = 0;
	all->a.len = 0;
	all->a.midel_stackfull = 0;
	all->a.midel_stacka = 0;
	all->a.midel_stackb = 0;
	all->a.lower_pointer = 0;
}
