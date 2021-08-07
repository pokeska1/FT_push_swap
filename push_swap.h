/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarian <jmarian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 02:09:54 by jmarian           #+#    #+#             */
/*   Updated: 2021/08/07 03:22:47 by jmarian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_t
{
	int			meh;
	int			j;
	int			jj;
	int			x;
}				t_t;

typedef struct s_a
{
	int			*adress;
	int			len;
	int			midel_stackfull;
	int			midel_stacka;
	int			midel_stackb;
	int			lower_pointer;
}				t_a;

typedef struct s_p
{
	int			*pointera;
	int			*pointerb;
	int			*stack_a;
	int			*stack_b;
	int			counte;
}				t_p;

typedef struct s_all
{
	t_p			p;
	t_a			a;
	t_t			t;
	int			*mimik;
	char		*str;
	int			*steck;
	int			*mimiktwo;
	int			*num;
	int			*numb;
	int			error;
	int			i;
	int			j;
	int			check;
	int			len_full;
	int			lena;
	int			lenb;
	int			buf;
	int			maxint;
	int			minimum;
	int			max;
	int			pointer_int;
	int			which_int;
	int			result;
	long int	atoi;
}				t_all;

int			*sa(int *str);
int			*sb(int *str);
void		ss(int *stra, int *strb);
char		*ft_calloc(int i);
int			ft_strlen(char *str);
void		ft_error(char *str);
void		ft_make_int(int argc, char **argv, t_all *all);
long int	ft_atoi(char *str);
void		ft_is_it_valid(t_all *all, int len);
int			is_digit(char *str);
int			ft_numbers_sorted(int *num, int	len);
void		ft_parser(t_all *all, int len);
void		ft_write(char *str);
int			*ra(int	*num, int len);
int			*rra(int *num, int len);
void		pb(t_all *all, int len);
void		pa(t_all *all, int len);
int			*ft_calloc_int(int *num, int len);
int			ft_min(int *num, int len);
int			ft_rra_or_ra(t_all *all, int i);
int			ft_good_choice(t_all *all);
void		organaizer(t_all *all);
int			ft_min_max_midl(t_all *all);
int			ft_more_nide(int *num, int len, int numer);
int			ft_rra_or_ra_numb(int i, int len);
int			is_digit_char(char c);
void		sort_mor_one_hundred(t_all *all, int len);
void		ft_one_hundred_num(t_all *all, int len);
void		ft_five_hundred_num(t_all *all, int len);
char		*ft_strcpy(char *str);
int			*ft_strcpy_int(int *num, int len);
void		ft_make_sort_stek(t_all *all, int len);
int			wich_one(int i, int j, int sum, t_all *all);
int			ft_numbers_sorted_back(int *num, int len);
int			*rrb(int *num, int len);
int			*rb(int	*num, int len);
void		ft_make_adrees_pointer(t_all *all);
void		ft_grate_start(t_all *all);
void		ft_make_int_two(char **argv, t_all *all);
void		ft_make_int_three(char **argv, t_all *all);
void		ft_make_int_four(int argc, char **argv, t_all *all);
void		ft_point_for_arr_a(t_all *all, int num, int i, int len);
void		ft_find_max_min_int(t_all *all, int num);
void		ft_finde_min_and_max(t_all *all);
void		ft_finde_score(t_all *all, int i);
void		ft_finde_lowe_score(t_all *all, int i);
void		ft_meh(t_all *all, int len);
void		ft_vip_parser_len_more_fife_par_two(t_all *all);

#	endif