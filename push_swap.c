/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarian <jmarian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 12:56:18 by jmarian           #+#    #+#             */
/*   Updated: 2021/08/04 05:03:35 by jmarian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_more_space(t_all *all)
{
	ft_make_sort_stek(all, all->len_full);
	if (!ft_numbers_sorted(all->num, all->len_full))
	{
		all->lenb = 1;
		all->lena = all->len_full;
		all->numb = ft_calloc_int(all->numb, all->len_full);
		ft_parser(all, all->len_full);
	}
	// вроде нужно вырезать от сюда
	// if (ft_numbers_sorted(all->num, all->len_full))
	// 	ft_write("OK\n");
	// else
	// 	ft_write("KO\n");
	// до сюда
	if (all->num)
		free(all->num);
	free(all->steck);
}

int	main(int argc, char **argv)
{
	t_all	all;

	all.error = 0;
	if (argc < 2)
	{
		ft_error("Error: need more param!\n");
		return (1);
	}
	ft_make_int(argc, argv, &all);
	if (all.error == -1)
	{
		ft_error("Error: you have replica int\n");
		return (1);
	}
	ft_is_it_valid(&all, all.len_full);
	if (all.error == -1)
	{
		ft_error("Error: you have replica int\n");
		return (1);
	}
	first_more_space(&all);
	return (0);
}
