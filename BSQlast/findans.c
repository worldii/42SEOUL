/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findans.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 04:16:04 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/28 05:56:57 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	solution(int **b, t_map tempmap, int **arr)
{
	int	ans;

	makebarray(b, tempmap, arr);
	ans = makedp(tempmap, b);
	findsquare(tempmap, ans, b, arr);
	printarray(tempmap, arr);
}

void	makebarray(int **b, t_map tempmap, int **arr)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= tempmap.row)
	{
		j = -1;
		while (++j <= tempmap.col)
		{
			b[i][j] = 0;
		}
	}
	i = 0;
	while (++i <= tempmap.row)
	{
		j = 0;
		while (++j <= tempmap.col)
		{
			b[i][j] = 1;
			if (arr[i][j] == tempmap.block)
				b[i][j] = 0;
		}
	}
}

int	makedp(t_map tempmap, int **b)
{
	int	ans;
	int	i;
	int	j;

	ans = 0;
	i = 0;
	while (++i <= tempmap.row)
	{
		j = 0;
		while (++j <= tempmap.col)
		{
			if (b[i][j] != 0)
			{
				b[i][j] = b[i - 1][j] + 1;
				if (b[i][j] > b[i][j - 1] + 1)
					b[i][j] = b[i][j - 1] + 1;
				if (b[i][j] > b[i - 1][j - 1] + 1)
					b[i][j] = b[i - 1][j - 1] + 1;
				if (ans < b[i][j])
					ans = b[i][j];
			}
		}
	}
	return (ans);
}

void	findsquare(t_map tempmap, int ans, int **b, int **arr)
{
	int	i;
	int	flag;
	int	j;

	i = 0;
	flag = 1;
	while (++i <= tempmap.row)
	{
		j = 0;
		while (++j <= tempmap.col)
		{
			if (ans == b[i][j])
			{
				flag = 0;
				break ;
			}
		}
		if (flag == 0)
			break ;
	}
	fillsquare(i * tempmap.col + j, arr, ans, tempmap);
}

void	fillsquare(long long cnt, int **arr, int ans, t_map tempmap)
{
	int	t;
	int	k;
	int	i;
	int	j;

	i = cnt / tempmap.col;
	j = cnt % tempmap.col;
	t = i - ans;
	while (++t <= i)
	{
		k = j - ans;
		while (++k <= j)
			arr[t][k] = tempmap.full;
	}
}
