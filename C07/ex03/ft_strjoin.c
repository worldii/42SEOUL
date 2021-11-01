/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 01:20:50 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/21 22:33:34 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strcat(char *dest, int idx, char *add)
{
	int	addidx;

	addidx = 0;
	while (add[addidx] != '\0')
		dest[idx++] = add[addidx++];
	return (idx);
}

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

int	get_len(int size, char **strs)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < size)
		len += ft_strlen(strs[i++]);
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*temp;
	int		len;

	if (size == 0)
	{
		temp = (char *) malloc(1);
		temp[0] = 0;
		return (temp);
	}
	len = get_len(size, strs);
	temp = (char *) malloc (len + (size - 1) * ft_strlen(sep) + 1);
	if (temp == NULL)
		return (0);
	i = 0;
	len = 0;
	while (i < size)
	{
		len = ft_strcat(temp, len, strs[i]);
		if (i++ != size - 1)
			len = ft_strcat(temp, len, sep);
	}
	temp[len] = '\0';
	return (temp);
}
/*
#include<stdio.h>
int main(void)
{
	char * temp; 
	char* texts1[] = { "a", "b", "c", "d", "e", "f", "g", "h", "i", "k" };
    temp=  ft_strjoin(10, texts1, ", ");
    printf("%s", temp); 
	char* texts2[] = { };
    temp=ft_strjoin(0, texts2, ", ");
	printf("%s", temp);
	// temp = ft_strjoin(-1, temp, ", ");
	// printf("%s", temp);
}*/
