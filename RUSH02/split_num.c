/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 20:31:39 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/24 20:56:18 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	split_num(char *str, t_Dict **temp)
{
	int	size;

	size = 0;
	while (*str && ('0' <= *str && *str <= '9'))
	{
		size++;
		str++;
	}
	(*temp)->key = (char *) malloc (sizeof (char) * (size + 1));
	str = str - size;
	size = 0;
	while (*str && ('0' <= *str && *str <= '9'))
		(*temp)->key[size++] = *str++;
	(*temp)->key[size] = 0;
	return (size + split_num2(str));
}

int	split_num2(char *str)
{
	int	size;

	size = 0 ;
	if (is_space(*str) == 0 && *str && *str != ':')
	{
		while (*str && is_space(*str) == 0)
		{
			str++;
			size++;
		}
	}
	while (*str && is_space(*str) == 1)
	{
		str++;
		size++;
	}
	return (size);
}
