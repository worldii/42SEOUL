/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 03:49:20 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/28 04:30:33 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	**mallocarr(t_map tempmap)
{
	int	i;
	int	**b;

	b = (int **) malloc(sizeof (int *) * (tempmap.row + 1));
	i = -1;
	while (++i <= tempmap.row)
		b[i] = (int *) malloc(sizeof(int) * (tempmap.col + 1));
	return (b);
}

void	freearray(t_map tempmap, int **arr, int **b, char *temprow)
{
	int	i;

	i = -1;
	while (++i < tempmap.row)
	{
		free(arr[i]);
		free(b[i]);
	}
	free(arr);
	free(b);
	if (temprow != NULL)
		free(temprow);
}

void	mallocarrays(int ***arr, int ***b, t_map tempmap)
{
	*arr = mallocarr(tempmap);
	*b = mallocarr(tempmap);
}
