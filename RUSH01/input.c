/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:32:24 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/17 21:38:01 by minjekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"input.h"

int	*get_constraints(char *str)
{
	int	*constraints;
	int	i;

	constraints = (int *) malloc(sizeof(int) * MS);
	if (constraints == NULL)
		return (NULL);
	i = 0;
	while (i < MS)
	{
		if (*str && *str >= '1' && *str <= '0' + N)
		{
			constraints[i++] = *str++ - '0';
			if ((i < MS && *str++ == ' ') || (i == MS && *str == '\0'))
			{
				if ((i - 1) % 8 < 4)
					continue ;
				else if (constraints[i - 1] + constraints[i - 1 - N] <= N + 1
					&& constraints[i - 1] + constraints[i - 1 - N] > 2)
					continue ;
			}
		}
		free(constraints);
		return (NULL);
	}
	return (constraints);
}

void	initialize_arr(int map[4][4])
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < N)
	{
		while (j < N)
		{
			map[i][j] = 0;
			j++;
		}
		i++;
	}
}
