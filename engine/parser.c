/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarian <jmarian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 22:37:58 by jmarian           #+#    #+#             */
/*   Updated: 2021/07/21 02:03:46 by jmarian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_two_num(t_all *all, int flag) // если флаг 0 то по возрастанию если 1 то по убыванию
{
	if (flag == 0)
	{
		if (all->num[0] > all->num[1])
			all->num = ra(all->num, all->lena);
	}
	else
		if (all->numb[0] < all->numb[1])
			all->numb = ra(all->numb, all->lenb - 1);
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
	return(num);
}

void	ft_meh(t_all *all, int len) // вставляем в нужное мессто число 
{
	if (all->check == 2)
		{
			pa(all, len);
			all->num = ra(all->num, all->lena);
		}
		else if (all->check == 1)
		{
			all->buf = ft_more_nide(all->num, all->lena, all->numb[0]);
			while (1)
			{
				if(all->numb[0] < all->num[0] && all->numb[0] > all->num[all->lena - 1])
					break;
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
	all->check = ft_min_max_midl(all);
	if (len == 4)
		ft_meh(all, len);
	else
	{
		ft_two_num(all, 1);
		ft_meh(all, len);
		all->check = ft_min_max_midl(all);
		ft_meh(all, len);
		//pa(all, len);
	}
}

void	ft_parser(t_all *all, int len)
{
	all->lenb = 1;
	all->lena = len;
	all->numb = ft_calloc_int(all->numb,  all->lenb);
	//malloc(sizeof(int) * all->lenb);
	if (len == 1)
	{
		ft_write("OK\n");
		return;
	}
	else if (len == 2)
		ft_two_num(all, 0);
	else if (len == 3)
	 	all->num = ft_three_num(all->num);
	else if (len <= 5)
	 	ft_five_num(all, len);
	// else if (len <= 99)
	// 	ft_one_hundred_num(num, len);
	// else if (len > 99)
	// 	ft_five_hundred_num(num, len);
	
	// #################### сортировка к норме 
	all->buf = ft_min(all->num, len);
	while (!ft_numbers_sorted(all->num, len))
	{
		if (ft_rra_or_ra(all, all->buf) == 1)
			all->num = rra(all->num, len);
		else
			all->num = ra(all->num, len);
	}
	// #################### конец сортировки к норме 

	
	if (ft_numbers_sorted(all->num, len))
		ft_write("OK\n");
	//free(all->num);
	//free(all->numb);
}
