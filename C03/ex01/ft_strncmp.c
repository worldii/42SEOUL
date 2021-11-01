/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:35:04 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/14 13:05:26 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	s1idx;
	int	s2idx;

	s1idx = 0;
	s2idx = 0;
	while (s1[s1idx] != '\0' && s2[s2idx] != '\0' && n != 0)
	{	
		if (s1[s1idx] != s2[s2idx])
		{
			return (s1[s1idx] - s2[s2idx]);
		}
		n--;
		s1idx++;
		s2idx++;
	}
	if (n == 0)
		return (0);
	else
		return (s1[s1idx] - s2[s2idx]);
}
