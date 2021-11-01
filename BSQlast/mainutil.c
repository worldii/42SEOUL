/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainutil.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 03:49:34 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/28 11:43:30 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	errorcheck(int argc, int t)
{
	if ((argc == 1 && t == 1)
		|| (argc != 1 && t != argc))
	{
		write(1, "map error\n", 10);
	}
}

int	argcount1(t_dpmap *dmap, t_map *tempmap)
{
	if (!mapcheck(STDIN_FILENO, tempmap, &tempmap->num))
		return (1);
	dmap->temprow = (char *)malloc(BUF_SIZE);
	if (!colcheck(STDIN_FILENO, tempmap, tempmap->num, dmap->temprow))
		return (1);
	mallocarrays(&dmap->arr, &dmap->b, *tempmap);
	if (!stdmakearray(*tempmap, dmap->arr, dmap->temprow))
		return (1);
	return (0);
}

int	argcount2(t_map *tempmap, char *argv[], t_dpmap *dmap, int t)
{
	tempmap->fd = open(argv[t], 00);
	tempmap->nc = mapcheck(tempmap->fd, tempmap, &tempmap->num);
	if (!tempmap->nc || !colcheck (tempmap->fd, tempmap, tempmap->num, NULL))
		return (1);
	mallocarrays(&dmap->arr, &dmap->b, *tempmap);
	if (!filemakearray(*tempmap, argv[t], dmap->arr, tempmap->nc))
		return (1);
	return (0);
}

void	printarray(t_map tempmap, int **arr)
{
	int	i;
	int	j;

	i = 0;
	while (++i <= tempmap.row)
	{
		j = 0;
		while (++j <= tempmap.col)
		{
			write(1, &arr[i][j], 1);
		}
		write(1, "\n", 1);
	}
}
