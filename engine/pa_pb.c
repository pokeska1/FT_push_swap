/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarian <jmarian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 13:06:45 by jmarian           #+#    #+#             */
/*   Updated: 2021/08/04 00:07:14 by jmarian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa_two(t_all *all, int len)
{
	(void)len;
	all->buf = all->numb[0];
	if (all->numb)
		free(all->numb);
	all->numb = NULL;
	all->numb = ft_strcpy_int(all->mimik, all->lenb);
	all->i = 0;
	all->j = 1;
	all->mimiktwo[0] = all->buf;
	while (all->j != all->lena)
	{
		all->mimiktwo[all->j] = all->num[all->i];
		all->i++;
		all->j++;
	}
	organaizer(all);
	if (all->num)
		free(all->num);
	all->num = ft_strcpy_int(all->mimiktwo, all->lena);
}

void	pa(t_all *all, int len)
{
	ft_write("pa\n");
	all->lenb--;
	all->lena++;
	all->mimik = ft_calloc_int(all->mimik, all->lenb);
	all->mimiktwo = ft_calloc_int(all->mimiktwo, all->lena);
	all->i = 0;
	all->j = 1;
	while (all->j != all->lenb)
	{
		all->mimik[all->i] = all->numb[all->j];
		all->i++;
		all->j++;
	}
	pa_two(all, len);
}

void	pb_two(t_all *all, int len)
{
	(void)len;
	all->buf = all->num[0];
	if (all->num)
	{
		free(all->num);
		all->num = NULL;
	}
	all->num = ft_strcpy_int(all->mimik, all->lena);
	all->i = 0;
	all->j = 1;
	all->mimiktwo[0] = all->buf;
	while (all->j != all->lenb - 1)
	{
		all->mimiktwo[all->j] = all->numb[all->i];
		all->i++;
		all->j++;
	}
	organaizer(all);
	if (all->numb)
	{
		free(all->numb);
		all->numb = NULL;
	}
	all->numb = ft_strcpy_int(all->mimiktwo, all->lenb - 1);
}

void	pb(t_all *all, int len)
{
	ft_write("pb\n");
	all->lenb++;
	all->lena--;
	all->mimik = ft_calloc_int(all->mimik, all->lena);
	all->mimiktwo = ft_calloc_int(all->mimiktwo, all->lenb - 1);
	all->i = 0;
	all->j = 1;
	while (all->j < all->lena + 1)
	{
		all->mimik[all->i] = all->num[all->j];
		all->i++;
		all->j++;
	}
	pb_two(all, len);
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
