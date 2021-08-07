/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarian <jmarian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 22:37:58 by jmarian           #+#    #+#             */
/*   Updated: 2021/08/07 03:22:35 by jmarian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// если флаг 0 то по возрастанию если 1 то по убыванию
void	ft_two_num(t_all *all, int flag)
{
	if (flag == 0)
	{
		if (all->num[0] > all->num[1])
			all->num = ra(all->num, all->lena);
	}
	else
		if (all->numb[0] < all->numb[1])
			all->numb = rb(all->numb, all->lenb - 1);
}

int	*ft_three_num(int *num)
{
	if (num[0] > num[1] && num[1] < num[2] && num[0] < num[2])
		num = sa(num);
	else if (num[0] > num[1] && num[1] > num[2] && num[0] > num[2])
	{
		num = sa(num);
		num = rra(num, 3);
	}
	else if (num[0] > num[1] && num[1] < num[2] && num[0] > num[2])
		num = ra(num, 3);
	else if (num[0] < num[1] && num[1] > num[2] && num[2] > num[0])
	{
		num = sa(num);
		num = ra(num, 3);
	}
	else if (num[0] < num[1] && num[1] > num[2] && num[2] < num[0])
		num = rra(num, 3);
	return (num);
}

void	ft_five_num(t_all *all, int len)
{
	if (len == 4)
		pb(all, len);
	else if (len == 5)
	{
		pb(all, len);
		pb(all, len);
	}
	all->num = ft_three_num(all->num);
	if (len == 4)
	{
		all->check = ft_min_max_midl(all);
		ft_meh(all, len);
	}
	else
	{
		ft_two_num(all, 1);
		all->check = ft_min_max_midl(all);
		ft_meh(all, len);
		all->check = ft_min_max_midl(all);
		ft_meh(all, len);
	}
}

//главный движок плюс определение пойнтов на перевод макс int в топ
void	ft_vip_parser_len_more_fife(t_all *all, int len)
{
	all->a.len = all->lena / 5;
	all->p.pointera = ft_calloc_int(all->p.pointera, all->a.len);
	all->p.pointerb = ft_calloc_int(all->p.pointerb, all->a.len);
	all->p.stack_a = ft_calloc_int(all->p.stack_a, all->a.len);
	all->p.stack_b = ft_calloc_int(all->p.stack_b, all->a.len);
	ft_make_adrees_pointer(all);
	ft_one_hundred_num(all, len);
	organaizer(all);
	all->maxint = all->numb[0];
	while (all->j != all->len_full)
	{
		if (all->numb[all->j] > all->maxint)
		{
			all->maxint = all->numb[all->j];
			all->pointer_int = all->j;
		}
		all->j++;
	}
}

//разделение по числам
void	ft_parser(t_all *all, int len)
{
	if (len == 1)
		return ;
	else if (len == 2)
		ft_two_num(all, 0);
	else if (len == 3)
		all->num = ft_three_num(all->num);
	else if (len <= 5)
		ft_five_num(all, len);
	else if (len > 5)
	{
		ft_vip_parser_len_more_fife(all, len);
		ft_vip_parser_len_more_fife_par_two(all);
	}
	all->buf = ft_min(all->num, len);
	while (!ft_numbers_sorted(all->num, len))
	{
		if (ft_rra_or_ra(all, all->buf) == 1)
			all->num = rra(all->num, len);
		else
			all->num = ra(all->num, len);
	}
	if (all->numb)
		free(all->numb);
	all->numb = NULL;
}
