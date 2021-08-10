/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarian <jmarian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 12:56:18 by jmarian           #+#    #+#             */
/*   Updated: 2021/08/07 03:34:55 by jmarian          ###   ########.fr       */
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
	if (all->num)
		free(all->num);
	free(all->steck);
}

int	main(int argc, char **argv)
{
	t_all	all;

	if (argc < 2)
		return (1);
	ft_grate_start(&all);
	ft_make_int(argc, argv, &all);
	if (all.error == -1)
	{
		ft_error("Error\n");
		return (1);
	}
	ft_is_it_valid(&all, all.len_full);
	if (all.error == -1)
	{
		ft_error("Error\n");
		return (1);
	}
	first_more_space(&all);
	return (0);
}
