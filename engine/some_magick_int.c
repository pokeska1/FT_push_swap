/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_magick_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarian <jmarian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:30:19 by jmarian           #+#    #+#             */
/*   Updated: 2021/08/07 02:13:03 by jmarian          ###   ########.fr       */
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
			all->error = -1;
			return ;
		}
		all->num[all->i] = ft_atoi(argv[all->j]);
		all->i++;
		all->j++;
	}
}

void	ft_make_int_three_part_two(char **argv, t_all *all)
{
	if (!is_digit_char(argv[1][all->i]))
		all->error = -1;
	if (all->j >= 1)
	{
		all->len_full--;
	}
	all->len_full++;
	all->str[all->j++] = argv[1][all->i];
	all->i++;
}

void	ft_make_int_three(char **argv, t_all *all)
{
	all->str = ft_calloc(15);
	while (argv[1][all->i] == ' ')
		all->i++;
	while (argv[1][all->i] != ' ')
	{
		if (argv[1][all->i] == '\0')
			break ;
		ft_make_int_three_part_two(argv, all);
	}
	if ((ft_strlen(all->str) > 10 && all->str[0] != '-')
		|| (ft_strlen(all->str) > 11 && all->str[0] == '-'))
	{
		all->error = -1;
		return ;
	}
	all->atoi = ft_atoi(all->str);
	if (all->atoi > 2147483647 || all->atoi < -2147483648)
		all->error = -1;
	all->num[all->check++] = (int)all->atoi;
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
		all->error = -1;
	all->i = 0;
	all->j = 0;
	all->check = 0;
}
