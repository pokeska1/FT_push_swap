/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarian <jmarian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 13:06:45 by jmarian           #+#    #+#             */
/*   Updated: 2021/07/20 22:30:03 by jmarian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_all *all, int len)
{
	ft_write("pa\n");
	all->lenb--;
	all->lena++;
	all->mimik = ft_calloc_int(all->mimik, all->lena);
	all->mimiktwo = ft_calloc_int(all->mimiktwo, all->lenb);
	all->i = 0;
	all->j = 1;
	while (all->j != len)
	{
		all->mimik[all->i] = all->numb[all->j];
		all->i++;
		all->j++;
	}
	all->buf = all->numb[0];
//	free(all->numb);
	all->numb = all->mimik;
	all->i = 0;
	all->j = 1;
	all->mimiktwo[0] = all->buf;
	while (all->j != len)
	{
		all->mimiktwo[all->j] = all->num[all->i];
		all->i++;
		all->j++;
	}
	organaizer(all);
	//free(all->num);
	all->num = all->mimiktwo;
}

void	pb(t_all *all, int len)
{
	ft_write("pb\n");
	all->lenb++;
	all->lena--;
	all->mimik = ft_calloc_int(all->mimik, all->lena);
	all->mimiktwo = ft_calloc_int(all->mimiktwo, all->lenb);
	all->i = 0;
	all->j = 1;
	while (all->j != len)
	{
		all->mimik[all->i] = all->num[all->j];
		all->i++;
		all->j++;
	}
	all->buf = all->num[0];
	free(all->num);
	all->num = all->mimik;
	all->i = 0;
	all->j = 1;
	all->mimiktwo[0] = all->buf;
	while (all->j != len)
	{
		all->mimiktwo[all->j] = all->numb[all->i];
		all->i++;
		all->j++;
	}
	free(all->numb);
	organaizer(all);
	all->numb = all->mimiktwo;
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
	free(num);
	return(mimik);
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
	//mimik = malloc (sizeof(int) * len);
	mimik[0] = num[len - 1];
	while (j < len)
	{
		mimik[j] = num [i];
		i++;
		j++;
	}
	free(num);
	return(mimik);
}
