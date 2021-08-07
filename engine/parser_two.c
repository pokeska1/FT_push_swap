/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarian <jmarian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 21:38:06 by jmarian           #+#    #+#             */
/*   Updated: 2021/08/07 03:22:39 by jmarian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_stek_second_try(t_all *all, int *mimik, long int x)
{
	int	y;

	y = 0;
	mimik = ft_calloc_int(mimik, all->lena);
	while (x < all->lena)
	{
		if (all->steck[y] != all->numb[0])
		{
			mimik[x] = all->steck[y];
			x++;
		}
		y++;
	}
	free(all->steck);
	all->steck = NULL;
	all->steck = ft_strcpy_int(mimik, all->lena);
}

void	ft_main_sort_engine(t_all *all, int len, long int *x)
{
	if ((all->i + 1 != len - 1) && all->steck[all->i] > all->steck[all->i + 1])
	{
		*x = all->steck[all->i];
		all->steck[all->i] = all->steck[all->i + 1];
		all->steck[all->i + 1] = *x;
		all->i = 0;
	}
	else
		all->i++;
	if ((all->i == len - 1) && all->steck[all->i] < all->steck[all->i - 1])
	{
		*x = all->steck[all->i];
		all->steck[all->i] = all->steck[all->i - 1];
		all->steck[all->i - 1] = *x;
		all->i = 0;
	}
}

void	ft_make_sort_stek(t_all *all, int len)
{
	long int	x;
	int			*mimik;

	organaizer(all);
	x = 0;
	mimik = NULL;
	if (all->lena == all->len_full || all->lena == 0)
	{
		all->steck = ft_calloc_int(all->steck, len);
		while (x < len)
		{
			all->steck[x] = all->num[x];
			x++;
		}
		while (all->i != len - 1)
			ft_main_sort_engine(all, len, &x);
	}
	else
		ft_stek_second_try(all, mimik, x);
}

// вставляем в нужное мессто число
void	ft_meh(t_all *all, int len)
{
	if (all->check == 2)
	{
		pa(all, len);
	}
	else if (all->check == 1 || all->check == 0)
	{
		all->buf = ft_more_nide(all->num, all->lena, all->numb[0]);
		while (1)
		{
			if (all->numb[0] < all->num[0]
				&& all->numb[0] > all->num[all->lena - 1])
				break ;
			if (all->check == 0 && ft_min(all->num, all->lena - 1) == 0)
				break ;
			if (ft_rra_or_ra_numb(all->buf, all->lena) == 1)
				all->num = rra(all->num, all->lena);
			else
				all->num = ra(all->num, all->lena);
		}
		pa(all, len);
	}
	else
		pa(all, len);
}

// само действие смотри в парт 1
void	ft_vip_parser_len_more_fife_par_two(t_all *all)
{
	if (all->pointer_int > all->a.midel_stackfull)
	{
		all->pointer_int = all->len_full - all->pointer_int;
		while (all->pointer_int > 0)
		{
			all->numb = rrb(all->numb, all->len_full);
			all->pointer_int--;
		}
	}
	else
	{
		while (all->pointer_int > 0)
		{
			all->numb = rb(all->numb, all->len_full);
			all->pointer_int--;
		}
	}
	organaizer(all);
	while (all->lenb != 1)
		pa(all, all->lenb);
}
