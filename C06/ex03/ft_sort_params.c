/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 00:21:30 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/20 00:30:59 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	strswap(char **stradd1, char **stradd2)
{
	char	*temp;

	temp = *stradd1;
	*stradd1 = *stradd2;
	*stradd2 = temp;
}

int	comparestr(char *str1, char *str2)
{
	int	s1idx;
	int	s2idx;

	s1idx = 0;
	s2idx = 0;
	while (str1[s1idx] != '\0' && str2[s2idx] != '\0')
	{
		if (str1[s1idx] != str2[s2idx])
		{
			return (str1[s1idx] - str2[s2idx]);
		}
		s1idx++;
		s2idx++;
	}
	return (str1[s1idx] - str2[s2idx]);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	j = 1;
	while (j < argc)
	{
		i = 1;
		while (i < argc - 1)
		{
			if (comparestr(argv[i], argv[i + 1]) > 0)
				strswap(&argv[i], &argv[i + 1]);
			i++;
		}
		j++;
	}
	i = 1;
	while (i < argc)
	{
		while (*argv[i])
			write(1, argv[i]++, 1);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
