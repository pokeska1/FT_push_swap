/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mor_one_hangred_part_two.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarian <jmarian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 03:10:25 by jmarian           #+#    #+#             */
/*   Updated: 2021/08/10 10:18:51 by jmarian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//число меньше чем половин длины массиива и флаг для выборра ra или rra 
void	ft_point_for_arr_a(t_all *all, int num, int i, int len)
{
	all->p.stack_b[i] = -1;
	all->a.midel_stacka = all->lena / 2;
	if (all->a.midel_stacka == 0)
		all->a.midel_stacka = 1;
	if (num < all->a.midel_stacka)
	{
		all->p.pointera[i] = num;
		all->p.stack_a[i] = 1;
	}
	else
	{
		all->p.pointera[i] = len - num;
		all->p.stack_a[i] = 0;
	}
}

// найти максимально низкое к нашему числу число в стеке б
void	ft_find_max_min_int(t_all *all, int num)
{
	while (all->i != all->lenb - 1)
	{
		if (all->numb[all->i] > all->minimum)
		{
			if (all->numb[all->i] > all->minimum && all->minimum < all->num[num]
				&& all->num[num] > all->numb[all->i])
				all->minimum = all->numb[all->i];
		}
		if (all->i + 1 == all->lenb)
			if (all->minimum == all->numb[0] && all->minimum > all->num[num])
				all->minimum = all->max;
		all->i++;
	}
}

void	ft_finde_min_and_max(t_all *all)
{
	all->a.midel_stackb = all->lenb / 2;
	all->minimum = all->numb[0];
	all->max = all->numb[0];
	organaizer(all);
	while (all->i != all->lenb - 1)
	{
		if (all->minimum > all->numb[all->i])
			all->minimum = all->numb[all->i];
		all->i++;
	}
	organaizer(all);
	while (all->i != all->lenb - 1)
	{
		if (all->max < all->numb[all->i])
			all->max = all->numb[all->i];
		all->i++;
	}
	all->i = 0;
}

// определяем сколько движений нужно если число не самое маленькое для b
void	ft_finde_score(t_all *all, int i)
{
	if (all->numb[all->t.j++] == all->minimum)
	{
		all->t.meh = 0;
		all->p.stack_b[i] = 1;
		all->t.x--;
	}
	if (all->t.jj >= 0 && all->t.meh != 0)
	{
		if (all->numb[all->t.jj--] == all->minimum)
		{
			all->t.meh = 0;
			all->p.stack_b[i] = 0;
		}
	}
	all->t.x++;
	if (all->t.x > all->a.midel_stackb)
	{
		all->p.pointerb[i] += all->a.midel_stackb;
		all->p.stack_b[i] = 0;
		all->t.meh = 0;
		all->error = -5;
	}
}

// определяем сколько движений нужно если число самое маленькое для b
void	ft_finde_lowe_score(t_all *all, int i)
{
	if (all->numb[all->t.j++] == all->max)
	{
		all->t.meh = 0;
		all->p.stack_b[i] = 1;
		all->t.x--;
	}
	if (all->t.jj >= 1 && all->p.stack_b[i] != 1)
	{
		if (all->numb[all->t.jj--] == all->max)
		{
			all->t.meh = 0;
			all->p.stack_b[i] = 0;
		}
	}
	all->t.x++;
	if (all->t.x > all->a.midel_stackb)
	{
		all->p.pointerb[i] += all->a.midel_stackb;
		all->p.stack_b[i] = 0;
		all->t.meh = 0;
		all->error = -5;
	}
}
