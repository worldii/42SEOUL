/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 16:55:34 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/24 20:32:37 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	split_space(char *str, t_Dict **temp)
{
	int	size;

	size = 0;
	if (*str == ':')
	{
		str++;
		size++;
	}
	else
	{
		free(*temp);
		return (0);
	}
	while (*str && is_space(*str) == 1)
	{
		str++;
		size++;
	}
	return (size);
}

int	split_printable(char *str, t_Dict **temp)
{
	int	size;

	if (*str && (33 <= *str && *str <= 126))
	{
		size = 0;
		while (*str && (33 <= *str && *str <= 126))
		{
			str++;
			size++;
		}
		(*temp)->value = (char *) malloc(sizeof(char) * (size + 1));
		str = str - size;
		size = 0;
		while (*str && (33 <= *str && *str <= 126))
			(*temp)->value[size++] = *str++;
		(*temp)->value[size] = 0;
	}
	else
	{
		free(*temp);
		write(1, "Dict Error\n", 11);
		return (0);
	}
	return (size);
}

int	split_frontword(char *str)
{
	int	size;

	size = 0;
	while (*str && is_space(*str) == 1)
	{
		str++;
		size++;
	}
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			return (1);
		size++;
	}
	if (!('0' <= *str && *str <= '9'))
		return (1);
	return (size);
}

int	split_word(char *str, t_Dict **head)
{
	t_Dict	*temp;

	while (*str)
	{
		if (split_frontword(str) == 1)
			return (1);
		str += split_frontword(str);
		if (*str && ('0' <= *str && *str <= '9'))
		{
			temp = (t_Dict *) malloc(sizeof(t_Dict));
			temp->next = NULL;
			str = str + split_num(str, &temp);
			if (split_space(str, &temp) == 0)
				return (0);
			str += split_space(str, &temp);
			if (split_printable(str, &temp) == 0)
				return (0);
			str += split_printable(str, &temp);
		}
	}
	make_dict(head, temp);
	return (1);
}
