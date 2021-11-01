/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rowcol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 19:15:26 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/17 23:37:27 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rowcol.h"

int	rowcol_check(int cnt, int num, int map[][4])
{
	int	i;

	i = 0;
	while (i < N)
	{
		if (map[cnt / 4][i] == num)
			return (0);
		i++;
	}
	i = 0;
	while (i < N)
	{
		if (map[i][cnt % 4] == num)
			return (0);
		i++;
	}
	return (1);
}

int	rowleft_check(int cnt, int num, int map[][4], int *constraints)
{
	int	count;
	int	row;
	int	col;
	int	min;
	int	i;

	count = 1;
	row = cnt / 4;
	col = cnt % 4;
	map[row][col] = num;
	min = map[row][0];
	i = 1;
	while (i < N)
	{
		if (min < map[row][i])
		{
			min = map[row][i];
			count++;
		}
		i++;
	}
	if (count != constraints[8 + row])
		count = 0;
	map[row][col] = 0;
	return (count);
}

int	rowright_check(int cnt, int num, int map[][4], int *constraints)
{
	int	count;
	int	row;
	int	col;
	int	min;
	int	i;

	count = 1;
	row = cnt / 4;
	col = cnt % 4;
	map[row][col] = num;
	min = map[row][N - 1];
	i = N - 2;
	while (i >= 0)
	{
		if (min < map[row][i])
		{
			min = map[row][i];
			count++;
		}
		i--;
	}
	if (count != constraints[12 + row])
		count = 0;
	map[row][col] = 0;
	return (count);
}

int	colup_check(int cnt, int num, int map[][4], int *constraints)
{
	int	count;
	int	row;
	int	col;
	int	min;
	int	i;

	count = 1;
	row = cnt / 4;
	col = cnt % 4;
	min = map[0][col];
	map[row][col] = num;
	i = 1;
	while (i < N)
	{
		if (min < map[i][col])
		{
			min = map[i][col];
			count++;
		}
		i++;
	}
	if (count != constraints[col])
		count = 0;
	map[row][col] = 0;
	return (count);
}

int	coldown_check(int cnt, int num, int map[][4], int *constraints)
{
	int	count;
	int	row;
	int	col;
	int	min;
	int	i;

	count = 1;
	row = cnt / 4;
	col = cnt % 4;
	map[row][col] = num;
	min = map[N - 1][col];
	i = N - 2;
	while (i >= 0)
	{
		if (min < map[i][col])
		{
			min = map[i][col];
			count++;
		}
		i--;
	}
	if (count != constraints[4 + col])
		count = 0;
	map[row][col] = 0;
	return (count);
}
