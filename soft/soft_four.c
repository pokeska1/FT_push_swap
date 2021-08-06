/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soft_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarian <jmarian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 22:06:04 by jmarian           #+#    #+#             */
/*   Updated: 2021/08/04 05:05:41 by jmarian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strcpy(char *str)
{
	int		i;
	char	*mimik;

	i = 0;
	mimik = ft_calloc(ft_strlen(str));
	while (str[i])
	{
		mimik[i] = str[i];
		i++;
	}
	free(str);
	return (mimik);
}

int	*ft_strcpy_int(int *num, int len)
{
	int	*sum;
	int	i;

	i = 0;
	sum = NULL;
	sum = ft_calloc_int(sum, len);
	while (i < len)
	{
		sum[i] = num[i];
		i++;
	}
	free(num);
	return (sum);
}
