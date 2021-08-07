/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarian <jmarian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 02:08:31 by jmarian           #+#    #+#             */
/*   Updated: 2021/08/07 02:11:12 by jmarian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_make_adrees_pointer(t_all *all)
{
	organaizer(all);
	all->a.len = all->lena / 5;
	if (all->a.len < 2)
		all->a.len = 2;
	if (all->lena == 1)
		all->a.len = 1;
	all->a.adress = ft_calloc_int(all->a.adress, all->a.len);
	while (all->j != all->a.len)
	{
		while (all->steck[all->j] != all->num[all->i])
			all->i++;
		all->a.adress[all->j] = all->i;
		all->i = 0;
		all->j++;
	}
}

void	ft_make_int(int argc, char **argv, t_all *all)
{
	if (argc == 2 && ft_strlen(argv[1]) >= 3 && all->error != -1)
	{
		ft_make_int_two(argv, all);
		while (argv[1][all->i] != '\0')
			ft_make_int_three(argv, all);
	}
	else
		ft_make_int_four(argc, argv, all);
	all->a.midel_stackfull = all->len_full / 2;
}

void	ft_sort_first(int *num, int len)
{
	int	i;

	i = 0;
	while (ft_numbers_sorted(num, len))
	{
		if (num[i] > num[i + 1])
			i++;
	}
}
