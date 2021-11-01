/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 19:15:26 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/17 23:37:12 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rush.h"

void	print_map(int map[][4])
{
	int		row;
	int		col;
	char	c;

	row = 0;
	while (row < N)
	{
		col = 0;
		while (col < N)
		{
			c = map[row][col] + '0';
			write(STDOUT_FILENO, &c, 1);
			if (col != 3)
				write(STDOUT_FILENO, " ", 1);
			col++;
		}
		write(STDOUT_FILENO, "\n", 1);
		row++;
	}
}

int	recur_map_row_check(int cnt, int num, int map[][4], int *constraints)
{
	int	row;
	int	col;

	row = cnt / 4;
	col = cnt % 4;
	if (row == 0)
	{
		if (N - constraints[col] + 1 < num)
			return (0);
	}
	else if (row == N - 1)
	{
		if (N - constraints[4 + col] + 1 < num)
			return (0);
		if (colup_check(cnt, num, map, constraints) == 0)
			return (0);
		if (coldown_check(cnt, num, map, constraints) == 0)
			return (0);
	}
	return (1);
}

int	recur_map_col_check(int cnt, int num, int map[][4], int *constraints)
{
	int	row;
	int	col;

	row = cnt / 4;
	col = cnt % 4;
	if (col == 0)
	{
		if (N - constraints[8 + row] + 1 < num)
			return (0);
	}
	else if (col == N - 1)
	{
		if (N - constraints[12 + row] + 1 < num)
			return (0);
		if (rowleft_check(cnt, num, map, constraints) == 0)
			return (0);
		if (rowright_check(cnt, num, map, constraints) == 0)
			return (0);
	}
	return (1);
}

int	recur_map(int cnt, int map[][4], int *constraints)
{
	static int	checkflag = 0;
	int			i;

	if (checkflag)
		return (checkflag);
	if (cnt == 16)
	{
		checkflag = 1;
		print_map(map);
		return (checkflag);
	}
	i = 0;
	while (i++ < N)
	{
		if (!recur_map_row_check(cnt, i, map, constraints)
			|| !recur_map_col_check(cnt, i, map, constraints))
			continue ;
		if (rowcol_check(cnt, i, map))
		{
			map[cnt / 4][cnt % 4] = i;
			recur_map(cnt + 1, map, constraints);
			map[cnt / 4][cnt % 4] = 0;
		}
	}
	return (checkflag);
}
