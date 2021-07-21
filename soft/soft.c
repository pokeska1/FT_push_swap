/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soft.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarian <jmarian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 13:08:42 by jmarian           #+#    #+#             */
/*   Updated: 2021/07/21 21:22:02 by jmarian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_error(char *str)
{
	write(1, str, ft_strlen(str));
	exit(1);
}

char	*ft_calloc(int i)
{
	char	*str;
	int		j;

	j = 0;
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	while (j != i)
	{
		str[j] = '\0';
		j++;
	}
	return (str);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_cpy(char *str, int num)
{
	char	*mimik;
	int		i;

	i = 0;
	mimik = ft_calloc(ft_strlen(str));
	if (!mimik)
		return (NULL);
	while (str[num] != '\0')
	{
		mimik[num] = str[num];
		i++;
	}
	return (mimik);
}

void	ft_join_char(char *str1, char *str2)
{
	char	*mimik;
	char	*remimik;
	int		i;
	int		j;

	i = 1;
	j = 0;
	mimik = ft_calloc(ft_strlen(str2) + 1);
	mimik = ft_cpy(str2, 1);
	mimik[0] = str1[0];
	remimik = ft_calloc(ft_strlen(str2));
	while (str2[i] != '\0')
	{
		remimik[j] = str2[i];
		i++;
		j++;
	}
	free(str1);
	free(str2);
	str1 = mimik;
	str2 = remimik;
}
