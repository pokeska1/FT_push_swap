/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soft_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarian <jmarian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 22:06:04 by jmarian           #+#    #+#             */
/*   Updated: 2021/08/03 00:31:02 by jmarian          ###   ########.fr       */
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
//определение куда вставить число из стека а в стек б
/*void	ft_good_plase(t_all *all)
{
	organaizer(all);
	all->error = 1;
	all->j = all->lenb;
	while(all->error != 0)
	{
		if (all->i + 1 < all->lenb)
		{
			if (all->num[0] < all->numb[all->i] && all->num[0] > all->numb[all->i + 1])
				all->error = 0;
		}
		else
			break;
		all->i++;
	}
	while(all->error != 0)
	{
		if (all->j > 0)
		{
			if (all->num[0] < all->numb[all->j - 1] && all->num[0] > all->numb[all->j])
				all->error = 0;
		}
		else
			break;
		all->j--;
	}
	if (all->i > (all->lenb - all->j))
		while (all->i >= 0)
		{
			all->numb = rb(all->numb, all->lenb);
			all->i--;
		}
	else
	{
		while ((all->lenb - all->j) >  all->lenb)
		{
			all->numb = rrb(all->numb, all->lenb);
			all->j++;
		}
	}
}*/
