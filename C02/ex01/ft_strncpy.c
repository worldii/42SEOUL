/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:12:06 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/12 23:15:25 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	idx;

	idx = 0;
	while (idx < n && src[idx])
	{		
		dest[idx] = src[idx];
		idx++;
	}
	while (idx < n)
		dest[idx++] = 0;
	return (dest);
}
