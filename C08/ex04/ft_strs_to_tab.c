/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 03:05:20 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/23 00:05:39 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

char	*ft_strcpy(char *str, int len)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = (char *) malloc(len + 1);
	if (tmp == NULL)
		return (0);
	while (*str)
	{
		tmp[i++] = *str;
		str++;
	}
	tmp[i] = 0;
	return (tmp);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*tmp;

	tmp = (t_stock_str *) malloc(sizeof(t_stock_str) * (ac + 1));
	if (tmp == 0)
		return (0);
	i = 0;
	while (i < ac)
	{
		tmp[i].size = ft_strlen(av[i]);
		tmp[i].str = av[i];
		tmp[i].copy = ft_strcpy(av[i], tmp[i].size);
		i++;
	}
	tmp[i].str = 0;
	return (tmp);
}
