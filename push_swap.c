/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarian <jmarian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 12:56:18 by jmarian           #+#    #+#             */
/*   Updated: 2021/07/21 03:15:20 by jmarian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_all all;

	all.error = 0;
	if (argc < 2)
		ft_error("Error: need more param!");
	ft_make_int(argc, argv, &all);
	if (all.error == -1)
		ft_error("Error: you have replica int");
	ft_is_it_valid(&all, all.len_full);
	if (all.error == -1)
		ft_error("Error: you have replica int");
	if (!ft_numbers_sorted(all.num, all.len_full))
		ft_parser(&all, all.len_full);
	/*
	int i;
	i = 0;
	while (i != argc - 1)
	{
		printf("%d \n", num[i++]);
	}
	*/
	free(all.num);
	return(0);
}
