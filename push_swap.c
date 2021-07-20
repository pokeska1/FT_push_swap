/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarian <jmarian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 12:56:18 by jmarian           #+#    #+#             */
/*   Updated: 2021/07/21 00:39:57 by jmarian          ###   ########.fr       */
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
	ft_is_it_valid(&all, argc - 1);
	if (all.error == -1)
		ft_error("Error: you have replica int");
	if (!ft_numbers_sorted(all.num, argc - 1))
		ft_parser(&all, argc - 1);
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
