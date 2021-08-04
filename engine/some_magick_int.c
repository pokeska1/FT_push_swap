/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_magick_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarian <jmarian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:30:19 by jmarian           #+#    #+#             */
/*   Updated: 2021/08/03 04:32:39 by jmarian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_make_int_four(int argc, char **argv, t_all *all)
{
	all->len_full = argc - 1;
	all->i = 0;
	all->j = 1;
	all->num = ft_calloc_int(all->num, argc);
	if (!all->num)
	{
		free(all->num);
		all->error = -1;
		return ;
	}
	while (all->j != argc)
	{
		if (!is_digit(argv[all->j]))
		{
			// if (all->num)
			// 	free(all->num);
			all->error = -1;
			return ;
		}
		all->num[all->i] = ft_atoi(argv[all->j]);
		all->i++;
		all->j++;
	}
}

void	ft_make_int_three(char **argv, t_all *all)
{
	all->str = ft_calloc(15);
	while (argv[1][all->i] == ' ')
	{
	//	all->len_full--;
		all->i++;
	}
	while (argv[1][all->i] != ' ')
	{
		if (argv[1][all->i] == '\0')
			break ;
		if (!is_digit_char(argv[1][all->i]))
		{
			// if (all->num)
			// 	free(all->num);
			all->error = -1;
			// return ;
		}
		if (argv[1][all->i] == '-' || all->j >= 1)
			all->len_full--;
		all->len_full++;
		all->str[all->j++] = argv[1][all->i];
		all->i++;
	}
	if ((ft_strlen(all->str) > 10 && all->str[0] != '-') || (ft_strlen(all->str) > 11 && all->str[0] == '-'))
		all->error = -1;
	all->num[all->check++] = ft_atoi(all->str);
	free(all->str);
	all->j = 0;
}

void	ft_make_int_two(char **argv, t_all *all)
{
	organaizer(all);
	while (argv[1][all->i++] != '\0')
	{
		if (argv[1][0] == ' ')
			all->i++;
		if (argv[1][all->i] == ' ')
			all->j++;
	}
	all->len_full = ft_strlen(argv[1]) - all->j;
	all->num = ft_calloc_int(all->num, (all->len_full));
	all->len_full = 0;
	if (!all->num)
	{
		// free(all->num);
		all->error = -1;
		// return ;
	}
	all->i = 0;
	all->j = 0;
	all->check = 0;
}


void	ft_make_adrees_pointer(t_all *all)
{
	all->a.adress = ft_calloc_int(all->a.adress, all->a.len);
	organaizer(all);
	all->a.len = all->lena / 5;
	if (all->a.len < 2)
		all->a.len = 2;
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
	if (argc == 2 && ft_strlen(argv[1]) >= 3)
	{
		ft_make_int_two(argv, all);
		while (argv[1][all->i] != '\0')
			ft_make_int_three(argv, all);
	}
	else
		ft_make_int_four(argc, argv, all);
	// Новое хочу создать 2 доп int массива pointer и addres
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
