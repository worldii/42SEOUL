/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 22:17:15 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/21 22:17:17 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *src)
{
	int	len;

	len = 0;
	while (src[len])
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*temp;
	int		len;
	int		sidx;
	int		tidx;

	sidx = 0;
	tidx = 0;
	len = ft_strlen(src);
	temp = (char *) malloc (sizeof(char) * len + 1);
	while (src[sidx])
	{
		temp[tidx++] = src[sidx++];
	}
	temp[tidx] = 0;
	return (temp);
}
/*#include<stdio.h>
int main(void)
{
	 char *s1 = "String";
    char *s2 = ft_strdup(s1);
    printf("%s", s2);
    free(s2);
}*/
