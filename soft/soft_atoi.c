/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soft_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarian <jmarian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 21:35:50 by jmarian           #+#    #+#             */
/*   Updated: 2021/08/06 22:07:30 by jmarian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	proverkaminus(char *str, int i)
{
	int	minus;
	int	check;

	minus = 0;
	check = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == '\n'
		|| str[i] == '+' || str[i] == '-')
	{
		while (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				minus++;
			i++;
			check++;
		}
		i++;
	}
	if (check > 1)
		return (0);
	else if (minus == 1)
		return (-1);
	return (1);
}

static int	probel(char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == '\n'
		|| str[i] == '0' || str[i] == '+' || str[i] == '-')
	{
		i++;
		if (str[i] == '+' || str[i] == '-' || str[i] == '0')
		{
			while (str[i] == '+' || str[i] == '-' || str[i] == '0')
			{
				i++;
				if (str[i] == '0')
				{
					while (str[i] == '0')
						i++;
					return (i);
				}
			}
			return (i);
		}
	}
	return (i);
}

static int	proverkanebukva(char *str, int i, int minus)
{
	int	mimik;

	mimik = i + 1 % 10;
	if (minus != 0)
		mimik = i + 2 % 10;
	if (mimik == 0)
		return (3);
	if ((str[i] < '0') || (str[i] > '9'))
		return (0);
	else
		return (1);
}

static int	zapis(char *str, int i, int minus)
{
	int	shet;
	int	sum;

	sum = 0;
	shet = 0;
	while (str[i] != '\0')
	{
		if (proverkanebukva(str, i, minus) == 0)
			return (sum);
		if (proverkanebukva(str, i, minus) == 3)
			sum = 0;
		sum = sum * 10 + str[i] - 48;
		shet++;
		i++;
	}
	if (shet > 19 && minus != -1)
		sum = -1;
	if (shet > 19 && minus == -1)
		sum = 0;
	return (sum);
}

int	ft_atoi(char *str)
{
	int	i;
	int	minus;
	int	result;

	i = 0;
	minus = proverkaminus(str, i);
	i = probel(str, i);
	if (minus == 0)
		return (0);
	result = zapis(str, i, minus);
	return (result);
}
