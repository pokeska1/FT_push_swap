/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mor_one_hundred.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarian <jmarian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 03:31:43 by jmarian           #+#    #+#             */
/*   Updated: 2021/08/06 23:32:17 by jmarian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//сколько действий нужно для вставки числа из стека а в стек б 
void	ft_nide_move_to_place_a_in_b(t_all *all, int num, int i, int len)
{
	int	meh;
	int	j;
	int	jj;
	int	x;

	all->p.stack_b[i] = -1;
	all->a.midel_stacka = all->lena / 2;
	if (all->a.midel_stacka == 0)
		all->a.midel_stacka = 1;
	if (num < all->a.midel_stacka)// проверка что число меньше чем половин длины массиива
	{
		all->p.pointera[i] = num;
		all->p.stack_a[i] = 1; // флаг для выборра ra или rra 
	}
	else
	{
		all->p.pointera[i] = len - num;
		all->p.stack_a[i] = 0;
	}
	if (all->lenb > 2)// если в списке б больше 1ного числа мы ищем идеальное место и 
	{
		all->a.midel_stackb = all->lenb / 2;

		
		meh = 1;
		j = 0;
		jj = all->lenb - 2;
		x = 0;
		int minimum;
		int max;

		minimum = all->numb[0];
		max = all->numb[0];
		organaizer(all);
		while (all->i != all->lenb - 1)
		{
			if (minimum > all->numb[all->i])
				minimum = all->numb[all->i];
			all->i++;
		}
		organaizer(all);
		while (all->i != all->lenb - 1)
		{
			if (max < all->numb[all->i])
				max = all->numb[all->i];
			all->i++;
		}
		all->i = 0;
		while (all->i != all->lenb - 1) // нужно найти максимально низкое к нашему числу число в стеке б и оно должно быть правее 
		{
			if (all->numb[all->i] > minimum)
			{
				if (all->numb[all->i] > minimum && minimum < all->num[num] && all->num[num] > all->numb[all->i])
					minimum = all->numb[all->i];
			}
			if (all->i + 1 == all->lenb)
				if (minimum == all->numb[0] && minimum > all->num[num])
					minimum = max;
			all->i++;
		}
		while (meh) // определяем сколько движений нужно
		{ 
			if (minimum < all->num[num])
			{
				if (all->numb[j++] == minimum)
				{
					meh = 0;
					all->p.stack_b[i] = 1;
					x--;
				}
				if(jj >= 0 && meh != 0)
					if (all->numb[jj--] == minimum) 
					{
						meh = 0;
						all->p.stack_b[i] = 0;
					}
				x++;
				if (x > all->a.midel_stackb)
				{
					all->p.pointerb[i] += all->a.midel_stackb;
					all->p.stack_b[i] = 0;
					meh = 0;
					return ;
				}
			}
			else
			{
				if (all->numb[j++] == max)
				{
					meh = 0;
					all->p.stack_b[i] = 1;
					x--;
				}
				if(jj >= 1)
					if (all->numb[jj--] == max) 
					{
						meh = 0;
						all->p.stack_b[i] = 0;
					}
				x++;
				if (x > all->a.midel_stackb)
				{
					all->p.pointerb[i] += all->a.midel_stackb;
					all->p.stack_b[i] = 0;
					meh = 0;
					return ;
				}
			}
		}
			all->p.pointerb[i] = x;
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

//тело функции
void	ft_one_hundred_num(t_all *all, int len)
{
	(void)len;
	all->which_int = 0;
	while (all->lena != 0)
	{
		organaizer(all);
		ft_make_pointer(all);
		organaizer(all);
		int i;
		
		i = (int)all->p.pointera[all->a.lower_pointer];
		if (all->p.stack_a[all->a.lower_pointer] == 1)
		{
			while(all->i != i)
			{
				all->num = ra(all->num, all->lena);
				all->i++;
			}
		}
		else
		{
			while(all->i != all->p.pointera[all->a.lower_pointer])
			{
				all->num = rra(all->num, all->lena);
				all->i++;
			}
		}
		if (all->p.stack_b[all->a.lower_pointer] == 1)
		{
			while(all->j != all->p.pointerb[all->a.lower_pointer])
			{
				all->numb = rb(all->numb, all->lenb - 1);
				all->j++;
			}
		}
		else if (all->p.stack_b[all->a.lower_pointer]  == 0)
		{
			while(all->j != all->p.pointerb[all->a.lower_pointer])
			{
				all->numb = rrb(all->numb, all->lenb - 1);
				all->j++;
			}
		}
		pb(all, all->lenb - 1);
		//free(all->steck);
		//all->steck = NULL;
		if  (all->lena >= 1)
			ft_make_sort_stek(all, all->lena);
		// free(all->a.adress);
		// all->a.adress = NULL;
		if  (all->lena >= 1)
			ft_make_adrees_pointer(all);
		all->which_int++;
	}
}	
