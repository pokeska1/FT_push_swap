/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mor_one_hundred.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarian <jmarian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 03:31:43 by jmarian           #+#    #+#             */
/*   Updated: 2021/08/07 03:10:48 by jmarian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//сколько действий нужно для вставки числа из стека а в стек b 
void	ft_nide_move_to_place_a_in_b(t_all *all, int num, int i, int len)
{
	ft_point_for_arr_a(all, num, i, len);
	if (all->lenb > 2)
	{
		ft_finde_min_and_max(all);
		ft_find_max_min_int(all, num);
		all->t.x = 0;
		all->t.jj = all->lenb - 2;
		all->t.j = 0;
		all->t.meh = 1;
		while (all->t.meh)
		{
			if (all->minimum < all->num[num])
				ft_finde_score(all, i);
			else
				ft_finde_lowe_score(all, i);
			if (all->error == -5)
				return ;
		}
		all->p.pointerb[i] = all->t.x;
	}
}

// заполняем массив поинтер
void	ft_make_pointer(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	if (all->lena == 1)
		all->a.len = 1;
	while (i < all->a.len)
	{
		ft_nide_move_to_place_a_in_b(all, all->a.adress[i], i, all->lena);
		i++;
	}
	organaizer(all);
	j = all->p.pointera[0] + all->p.pointerb[0];
	all->a.lower_pointer = 0;
	while (all->i < all->a.len)
	{
		i = all->p.pointerb[all->i] + all->p.pointera[all->i];
		if (j > i)
		{
			j = all->p.pointerb[all->i] + all->p.pointera[all->i];
			all->a.lower_pointer = all->i;
			all->i = 0;
		}
		all->i++;
	}
}

// не влезло по итогу анализа выбирается как вертеть массивы
void	ft_one_hundred_num_part_two(t_all *all, int *i)
{
	if (all->p.stack_a[all->a.lower_pointer] == 1)
	{
		while (all->i++ != *i)
			all->num = ra(all->num, all->lena);
	}
	else
	{
		while (all->i++ != all->p.pointera[all->a.lower_pointer])
			all->num = rra(all->num, all->lena);
	}
	if (all->p.stack_b[all->a.lower_pointer] == 1)
	{
		while (all->j++ != all->p.pointerb[all->a.lower_pointer])
			all->numb = rb(all->numb, all->lenb - 1);
	}
	else if (all->p.stack_b[all->a.lower_pointer] == 0)
	{
		while (all->j++ != all->p.pointerb[all->a.lower_pointer])
			all->numb = rrb(all->numb, all->lenb - 1);
	}	
}

//тело функции
void	ft_one_hundred_num(t_all *all, int len)
{
	int	j;
	int	i;

	(void)len;
	j = 0;
	while (all->lena != 0)
	{
		organaizer(all);
		ft_make_pointer(all);
		organaizer(all);
		i = (int)all->p.pointera[all->a.lower_pointer];
		ft_one_hundred_num_part_two(all, &i);
		pb(all, all->lenb - 1);
		if (all->lena >= 1)
			ft_make_sort_stek(all, all->lena);
		if (all->lena >= 1)
			ft_make_adrees_pointer(all);
		j++;
	}
}
