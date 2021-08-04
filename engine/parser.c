/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarian <jmarian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 22:37:58 by jmarian           #+#    #+#             */
/*   Updated: 2021/08/04 03:39:27 by jmarian          ###   ########.fr       */
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
		all->a.len = all->lena / 5;
		all->p.pointera = ft_calloc_int(all->p.pointera, all->a.len);
		all->p.pointerb = ft_calloc_int(all->p.pointerb, all->a.len);
		all->p.stack_a = ft_calloc_int(all->p.stack_a, all->a.len);
		all->p.stack_b = ft_calloc_int(all->p.stack_b, all->a.len);
		ft_make_adrees_pointer(all);
		// all->check = 0;
		ft_one_hundred_num(all, len);
		//all->i = wich_one(all->j, all->j , ((all->len_full + 1) / 2), all);
		organaizer(all);//checker !
		//узнаем где чейчас макс инт
		int maxint;
		int pointer_int;
		
		maxint = all->numb[0];
		while (all->j != all->len_full)
		{
			if (all->numb[all->j] > maxint)
			{
				maxint = all->numb[all->j];
				pointer_int = all->j;
			}
			all->j++;
		}
		// узнали
		if (pointer_int > all->a.midel_stackfull)
		{
			pointer_int = all->len_full - pointer_int;
			while (pointer_int > 0)
			{
				all->numb = rrb(all->numb, all->len_full);
				pointer_int--;
			}
		}
		else
		{
			while (pointer_int > 0)
			{
				all->numb = rb(all->numb, all->len_full);
				pointer_int--;
			}
		}
		organaizer(all);//checker !
		// while (all->i < all->len_full)
		// {
		// 	printf("%d ,", all->numb[all->i++]);
		// }
		// while (!ft_numbers_sorted_back(all->numb, all->len_full))
		// {
		// 	if (all->i++ > all->len_full)
		// 	{
		// 		printf("MEH~!?");
		// 		exit(1);
		// 	}
			
		// }
		while (all->lenb != 1)
			pa(all, all->lenb);
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
