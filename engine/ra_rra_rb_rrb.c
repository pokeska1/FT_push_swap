/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rra_rb_rrb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarian <jmarian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 02:04:38 by jmarian           #+#    #+#             */
/*   Updated: 2021/08/07 02:05:32 by jmarian          ###   ########.fr       */
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

int	*ra(int	*num, int len)
{
	int	*mimik;
	int	i;
	int	j;

	ft_write("ra\n");
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
