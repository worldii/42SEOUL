/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 05:59:15 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/28 10:47:05 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

int	setmap(int *mc, char buf[], t_map *tempmap)
{
	if (*mc == 0)
		tempmap->emp = buf[0];
	if (*mc == 1)
	{
		tempmap->block = buf[0];
		if (tempmap -> emp == buf[0])
			return (0);
	}
	if (*mc == 2)
	{
		tempmap->full = buf[0];
		if (tempmap -> emp == buf[0] || tempmap -> block == buf[0])
			return (0);
	}
	(*mc)++;
	return (1);
}

int	numcheck(int ch, char buf[], int *nc, int input)
{
	int	num;

	num = 0;
	while (ch > 0 && ('0' <= buf[0] && buf[0] <= '9'))
	{
		(*nc)++;
		num = num * 10 + buf[0] - '0';
		ch = read(input, buf, 1);
	}
	return (num);
}

int	mapcheck(int input, t_map *tempmap, int *num)
{
	char	buf[2];
	int		ch;
	int		nc;
	int		mc;

	*num = 0;
	nc = 0;
	mc = 0;
	ch = read(input, buf, 1);
	while (ch > 0 && buf[0] != '\n')
	{
		if (!('0' <= buf[0] && buf[0] <= '9'))
			break ;
		*num = numcheck(ch, buf, &nc, input);
		while (ch > 0 && buf[0] != '\n')
		{
			if (!setmap(&mc, buf, tempmap))
				return (0);
			ch = read(input, buf, 1);
		}
	}
	if (mc != 3 || ch <= 0)
		return (0);
	return (nc);
}
