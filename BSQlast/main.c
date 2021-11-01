/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 03:49:58 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/28 04:14:21 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"header.h"

int	main(int argc, char *argv[])
{
	t_map		tempmap;
	t_dpmap		dmap;
	int			t;

	dmap.temprow = NULL;
	t = 0;
	while (t++ < argc)
	{
		if (argc == 1)
		{
			if (argcount1(&dmap, &tempmap) == 1)
				break ;
		}
		else
		{
			if (t == argc)
				break ;
			if (argcount2(&tempmap, argv, &dmap, t) == 1)
				break ;
		}
		solution(dmap.b, tempmap, dmap.arr);
		freearray(tempmap, dmap.arr, dmap.b, dmap.temprow);
	}
	errorcheck(argc, t);
	return (0);
}
