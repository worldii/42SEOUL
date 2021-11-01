/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjekan <minjekan@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:16:31 by minjekan          #+#    #+#             */
/*   Updated: 2021/10/17 21:47:19 by minjekan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "rush.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int		*constraints;
	int		map[4][4];

	if (argc != 2)
	{
		write(STDOUT_FILENO, "Error\n", 6);
		return (0);
	}
	constraints = get_constraints(argv[1]);
	if (constraints == NULL)
	{
		write(STDOUT_FILENO, "Error\n", 6);
		return (0);
	}
	initialize_arr(map);
	for (int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{	map[i][j] = 0;
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	if (!recur_map(0, map, constraints))
		write(STDOUT_FILENO, "Error\n", 6);
	return (0);
}
