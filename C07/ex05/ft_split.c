/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 02:37:44 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/23 12:39:47 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include<stdio.h>
int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

int	ft_strcmp(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	count_word(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && ft_strcmp(*str, charset) == 1)
			str++;
		if (*str && ft_strcmp(*str, charset) == 0)
		{
			count++;
			while (*str && ft_strcmp(*str, charset) == 0)
				str++;
		}
	}
	return (count);
}

void	makeword(char **word, char *str, char *charset)
{
	int	i;
	int	j;
	int	widx;

	widx = 0;
	while (*str)
	{
		while (*str && ft_strcmp(*str, charset) == 1)
			str++ ;
		if (*str && ft_strcmp(*str, charset) == 0)
		{
			j = 0;
			while (*str && ft_strcmp(*str, charset) == 0)
			{
				j++;
				str++;
			}
			word[widx] = (char *) malloc(j + 1);
			str = str - j;
			i = 0;
			while (i < j)
				word[widx][i++] = *str++;
			word[widx++][i] = 0;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**word;
	int		widx;
	int		count;

	widx = 0;
	count = count_word(str, charset);
	word = (char **) malloc(sizeof(char *) * (count + 1));
	word[count] = 0;
	if (word == NULL)
		return (0);
	makeword(word, str, charset);
	return (word);
}
/*
#include<stdio.h>
int main(void){
	int temp =  count_word("80hzNIGZYoIa3ATwY8dRCFmBBYx0RA", "AKfwjE5l");
	printf("%d", temp);
	char **word = ft_split("80hzNIGZYoIa3ATwY8dRCFmBBYx0RA", "AKfwjE5l");
   for (int	i = 0 ; i < temp ; i++){
		int j =0;
		while (word[i][j]){
			printf("%c", word[i][j++]);
	}
	printf("\n");
}
}*/
