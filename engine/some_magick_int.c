/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_magick_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarian <jmarian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:30:19 by jmarian           #+#    #+#             */
/*   Updated: 2021/07/21 03:18:42 by jmarian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_make_int(int argc, char **argv, t_all *all)
{
	if (argc == 2 && ft_strlen(argv[1]) > 3)
	{
		organaizer(all);
		while (argv[1][all->i++] != '\0')
		{
			if (argv[1][all->i] == ' ')
				all->j++;
		}
		all->len_full = ft_strlen(argv[1]) - all->j;
		all->num = ft_calloc_int(all->num, (all->len_full));
		if (!all->num)
		{
			free(all->num);
			all->error = -1;
			return;
		}
		all->i = 0;
		all->j = 0;
		all->check = 0;
		while (argv[1][all->i] != '\0')
		{
			all->str = ft_calloc(15);
			while (argv[1][all->i] == ' ')
				all->i++;
			while (argv[1][all->i] != ' ')
			{
				if (argv[1][all->i] == '\0')
					break;
				if(!is_digit_char(argv[1][all->i]))
				{
					free(all->num);
					all->error = -1;
					return;
				}
				if (argv[1][all->i] == '-')
					all->len_full--;
				all->str[all->j++] = argv[1][all->i];
				all->i++;
			}
			all->num[all->check++] = ft_atoi(all->str);
			free(all->str);
			all->j = 0;
			//all->i++;
		}
		// while (all->j != all->i)
		// {
		// 	// if(!is_digit(argv[all->i]))
		// 	// {
		// 	// 	free(all->num);
		// 	// 	all->error = -1;
		// 	// 	return;
		// 	// }
		// 	all->num[all->i] = ft_atoi(argv[all->j]);
		// 	all->i++;
		// 	all->j++;
		// }
	}
	else
	{
		all->len_full = argc - 1;
		all->i = 0;
		all->j = 1;
		all->num = ft_calloc_int(all->num, argc);
		if (!all->num)
		{
			free(all->num);
			all->error = -1;
			return;
		}
		while (all->j != argc)
		{
			if(!is_digit(argv[all->j]))
			{
				free(all->num);
				all->error = -1;
				return;
			}
			all->num[all->i] = ft_atoi(argv[all->j]);
			all->i++;
			all->j++;
		}
	}
}

void	ft_sort_first(int *num, int len)
{
	int	i;

	i = 0;
	while (ft_numbers_sorted(num, len))
	{
		if(num[i] > num[i + 1])
		i++;
	}
	
}
