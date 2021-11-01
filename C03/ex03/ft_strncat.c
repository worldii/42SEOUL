/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:04:27 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/14 13:13:47 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	desidx;
	int	srcidx;

	desidx = 0;
	srcidx = 0;
	while (dest[desidx] != '\0')
	{
		desidx++;
	}
	while (nb-- && src[srcidx] != '\0')
	{
		dest[desidx] = src[srcidx];
		desidx++;
		srcidx++;
	}
	dest[desidx] = '\0';
	return (dest);
}
