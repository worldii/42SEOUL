/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 13:29:51 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/24 19:54:44 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

/// Dict 자료구조 함수들 ////
/*void	modify_dict(t_Dict *head, char *key, char *value)
{
	int		keylen;
	int		valuelen;
	t_Dict	*temp;
	int		i;

	temp = (t_Dict *) malloc(sizeof(t_Dict));
	keylen = ft_strlen(key);
	valuelen = ft_strlen(value);
	temp->key = (char *)malloc(1 + keylen);
	temp->value = (char *)malloc(1 + valuelen);
	i = -1;
	while (++i < keylen)
		temp->key[i] = key[i];
	i = -1;
	while (++i < valuelen)
		temp->value[i] = value[i];
	make_dict(&head, temp);
}	
*/
void	make_dict(t_Dict **head, t_Dict *temp)
{
	t_Dict	*cur;

	cur = *head;
	if (*head == NULL)
		*head = temp;
	else
	{
		while (cur -> next != NULL)
			cur = cur ->next;
		cur ->next = temp;
	}
}

void	memory_deallocate(t_Dict *head)
{
	t_Dict	*cur;
	t_Dict	*prev;

	cur = head ->next;
	prev = head;
	while (cur != NULL)
	{
		free(prev->key);
		free(prev->value);
		free(prev);
		prev = cur ;
		cur = cur->next;
	}
	free(prev->key);
	free(prev->value);
	free(prev);
}

char	*makestr(int fd, int *ret, int *idx)
{
	char	*temp;
	char	buf[50];

	temp = (char *) malloc (sizeof(char) * BUF_SIZE);
	*idx = 0;
	while (1)
	{
		*ret = read(fd, buf, 1);
		if (*ret <= 0 || buf[0] != '\n')
			break ;
	}
	if (*ret <= 0)
		return (0);
	temp[(*idx)++] = buf[0];
	while (1)
	{
		*ret = read(fd, buf, 1);
		if (*ret <= 0 || buf[0] == '\n')
			break ;
		temp[(*idx)++] = buf[0];
	}
	if (*ret <= 0)
		return (0);
	temp[(*idx)] = 0;
	return (temp);
}

int	fileread(int fd, t_Dict **head)
{
	int		ret;
	char	*temp;
	int		idx;

	ret = 1;
	while (ret > 0)
	{
		temp = makestr(fd, &ret, &idx);
		if (ret <= 0)
			break ;
		if (split_word(temp, head) == 0)
		{
			write(1, "Dict Error\n", 11);
			close(fd);
			free(temp);
			return (0);
		}
		free(temp);
	}
	close(fd);
	return (1);
}
/*
void print_dict (t_Dict *head) {
    t_Dict *cur = head;
    while (cur != NULL) {
        //printf("%s %s\n", cur->key, cur->value);
        cur = cur ->next;
    }
}*/
//////////////
