/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mor_one_hundred.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarian <jmarian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 03:31:43 by jmarian           #+#    #+#             */
/*   Updated: 2021/08/04 03:01:39 by jmarian          ###   ########.fr       */
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
	//	int zero;

		//zero = 0;
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
				{
					// while (all->j != all->lenb)
					// {
					// 	if (max < all->numb[all->j])
					// 		max = all->numb[all->j];
							
					// 	all->j++;
					// }
					minimum = max;
				}
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
				//if (all->numb[jj--] > all->num[num] && all->numb[zero] < all->num[num])
				if(jj >= 0 && meh != 0)
					if (all->numb[jj--] == minimum) 
					{
						meh = 0;
						all->p.stack_b[i] = 0;
					//	x--;
					}
				x++;
				if (x > all->a.midel_stackb)
				{
					all->p.pointerb[i] += all->a.midel_stackb;
					all->p.stack_b[i] = 0;
					meh = 0;
					return ;
				}
				//zero = jj + 1;
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
/*(t_all *all, int midle_stack, int mino, int y)
	int	pointx;
	int pointy;

	if (mino < midle_stack)
		pointx = mino;
	else
	{
		pointx = all->lena - mino;
		mino = mino - all->lena;
	}
	if (y < midle_stack)
		pointy = y;
	else
	{
		pointy = all->lena - y;
		y = y - all->lena;
	}
	// здесь нужно придумать и сделать увелечение счетчика point если нужно двигать ещё и стек б 
	
	if (all->lenb > 1)
	{
		if ()
	}
	
	//
	if (pointx < pointy)
		return(mino);
	else
		return(y);*/
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
	int j;
	(void)len;
	j = 0;
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
		free(all->steck);
		all->steck = NULL;
		if  (all->lena >= 1)
			ft_make_sort_stek(all, all->lena);
		free(all->a.adress);
		all->a.adress = NULL;
		if  (all->lena >= 1)
			ft_make_adrees_pointer(all);
		j++;
	}
}	
	//all->buf = ft_nide_move_to_place_a_in_b(all, all->check, all->i, all->j);//сколько действий нужно для вставки числа из стека а в стек б
	
// 	if (all->p.stack_a > 0)
// 		while (all->buf)
// 		{
// 			all->num = ra(all->num, all->lena);
// 			all->buf--;
// 		}
// 	else
// 		while (all->buf)
// 	{
// 		all->num = rra(all->num, all->lena);
// 			all->buf++;
// 	}
// }
// void	make_stack_lother(t_all *all, int i)
// {
// 	int	*new;
// 	int	x;
// 	int	j;

// 	x = 0;
// 	j = 0;
// 	new = NULL;
// 	new = ft_calloc_int(new, all->lena);
// 	while (j != all->lena)
// 	{
// 		if (x != i)
// 		{
// 			new[j] = all->steck[x];
// 			j++;
// 		}
// 		x++;
// 	}
// 	free(all->steck);
// 	all->steck = new;
// }

// int	wich_one(int i, int j, int sum, t_all *all)
// {
// 	if (i < sum && j < sum)
// 	{
// 		if (i < j)
// 		{
// 			make_stack_lother(all, i);
// 			return (i);
// 		}
// 		else if (j < i)
// 		{
// 			make_stack_lother(all, j);
// 			return (j);
// 		}
// 	}
// 	else if (i >= sum && j < sum)
// 	{
// 		if (((all->len_full + 1) - i) < j)
// 		{
// 			make_stack_lother(all, i);
// 			return (i - (all->len_full + 1));
// 		}
// 		else if (((all->len_full + 1) - i) > j)
// 		{
// 			make_stack_lother(all, j);
// 			return (j);
// 		}
// 	}
// 	else if (i < sum && j >= sum)
// 	{
// 		if (i < ((all->len_full + 1) - j))
// 		{
// 			make_stack_lother(all, i);
// 			return (i);
// 		}
// 		else if (((all->len_full + 1) - j) < i)
// 		{
// 			make_stack_lother(all, j);
// 			return (j - (all->len_full + 1));
// 		}
// 	}
// 	else if (i == j)
// 	{
// 		if (i < sum)
// 			return(i);
// 		else
// 		{
// 			make_stack_lother(all, i);
// 			return (i - (all->len_full + 1));
// 		}
// 	}
// 	else
// 	{
// 		if (i > j)
// 		{
// 			make_stack_lother(all, i);
// 			return (i - (all->len_full + 1));
// 		}
// 		else
// 		{
// 			make_stack_lother(all, j);
// 			return (j - (all->len_full + 1));
// 		}
// 	}
// 	return (0);
// }

// void	ft_one_hundred_num(t_all *all, int len)
// {
// 	int	i;

// 	organaizer(all);
// 	while(all->steck[0] != all->num[all->i])
// 		all->i++;
// 	if (all->check + 1 < all->len_full)
// 		while(all->steck[all->check + 1] != all->num[all->j])
// 			all->j++;
// 	else
// 		all->j = all->i;
// 	i = ((all->len_full + 1) / 2);
// 	i = wich_one(all->i, all->j , i, all);
// 	if (all->lenb > 2)
// 		ft_good_plase(all);
// 	if (i >= 0)
// 	{
// 		while (i != 0)
// 		{
// 			all->num = ra(all->num, all->lena);
// 			i--;
// 		}
// 	}
// 	else if (i <= 0)
// 	{
// 		while (i < -1)
// 		{
// 			all->num = rra(all->num, all->lena);
// 			i++;
// 		}
// 	}
// 	pb(all, all->lenb);
// 	while (all->lena != 0)
// 	{
// 		ft_make_sort_stek(all, all->lena);
// 		ft_one_hundred_num(all, len);
// 	}
// }
