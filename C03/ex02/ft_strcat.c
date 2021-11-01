/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:44:25 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/11 16:03:19 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	desidx;
	int	srcidx;

	desidx = 0;
	srcidx = 0;
	while (dest[desidx] != '\0')
	{
		desidx++;
	}
	while (src[srcidx] != '\0')
	{
		dest[desidx] = src[srcidx];
		desidx++;
		srcidx++;
	}
	dest[desidx] = '\0';
	return (dest);
}
