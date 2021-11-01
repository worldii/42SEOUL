/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:46:29 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/16 08:35:11 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *array)
{
	int	len;

	len = 0;
	while (*array != 0)
	{
		array++;
		len++;
	}
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int	destlen;
	int	i;
	int	srclen;
	int	len;

	destlen = ft_strlen(dest);
	len = (int) size - destlen;
	srclen = ft_strlen(src);
	i = 0;
	while (*src && i < len - 1)
	{
		*(dest + destlen) = *(src);
		i++;
		dest++;
		src++;
	}
	*(dest + destlen) = 0;
	if ((int) size >= destlen)
		return (srclen + destlen);
	else
		return (srclen + size);
}
/*
#include<stdio.h>
int main(void) {
	char  dest[30] = "goods";
	char src[30] = "saysomthing";
	printf("%d %s %s ", ft_strlcat(dest, src, 1), dest, src); 
}*/
