/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 03:50:15 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/28 05:58:59 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	stdsmall(t_map tempmap, int**arr, int i)
{
	int		j;
	char	buf[2];
	int		ch;

	j = 0;
	while (++j <= tempmap.col)
	{
		ch = read(STDIN_FILENO, buf, 1);
		if (ch <= 0 || !(buf[0] == tempmap.block || buf[0] == tempmap.emp))
			return (0);
		arr[i][j] = buf[0];
	}
	ch = read(STDIN_FILENO, buf, 1);
	if (ch <= 0 || buf[0] != '\n')
		return (0);
	return (1);
}

int	stdmakearray(t_map tempmap, int **arr, char *temprow)
{
	int		i;
	int		ch;
	char	buf[2];

	i = -1;
	while (++i <= tempmap.col)
		arr[1][i] = temprow[i - 1];
	i = 1;
	while (++i <= tempmap.row)
		if (stdsmall(tempmap, arr, i) == 0)
			return (0);
	ch = read(STDIN_FILENO, buf, 1);
	if (ch > 0)
		return (0);
	return (1);
}

int	colcheck(int input, t_map *tempmap, int num, char *temprow)
{
	int		ch;
	char	buf[2];

	ch = read(input, buf, 1);
	tempmap->col = 0;
	while (ch > 0 && buf[0] != '\n')
	{
		if (temprow != NULL)
			temprow[tempmap->col] = buf[0];
		tempmap->col++;
		ch = read (input, buf, 1);
	}
	if (temprow != NULL)
		temprow[tempmap->col] = 0;
	tempmap->row = num;
	if (temprow == NULL)
		close(input);
	if (ch <= 0 || buf[0] != '\n')
		return (0);
	return (1);
}

int	smallmake(t_map tempmap, int fd, int **arr, int i)
{
	char	buf[2];
	int		ch;
	int		j;

	j = 0;
	while (++j <= tempmap.col)
	{
		ch = read(fd, buf, 1);
		if (ch <= 0 || !(buf[0] == tempmap.block || buf[0] == tempmap.emp))
			return (0);
		arr[i][j] = buf[0];
	}
	ch = read(fd, buf, 1);
	if (ch <= 0 || buf[0] != '\n')
		return (0);
	return (1);
}

int	filemakearray(t_map tempmap, char *str, int **arr, int nc)
{
	int		i;
	int		ch;
	char	buf[2];
	int		fd ;

	fd = open(str, 00);
	i = -1;
	while (++i < nc + 4)
		read(fd, buf, 1);
	i = 0;
	while (++i <= tempmap.row)
		if (smallmake(tempmap, fd, arr, i) == 0)
			return (0);
	ch = read(fd, buf, 1);
	close(fd);
	if (ch > 0)
		return (0);
	return (1);
}
