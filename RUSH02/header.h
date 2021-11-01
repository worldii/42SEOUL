/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 08:25:52 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/24 20:23:30 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUF_SIZE 1024

typedef struct _entry
{
	char			*key;
	char			*value;
	struct _entry	*next;
}t_Dict;

////// 기본적 함수들 
int			ft_strcmp(char *str1, char *str2);
int			ft_strlen(char *str);
void		ft_putstr(char *str);
long long	ft_atoi(char *str);
int			is_space(char c);
////////

///// Dict 자료구조 함수들 
int			fileread(int fd, t_Dict **head);
void		make_dict(t_Dict **head, t_Dict *temp);
char		*makestr(int fd, int *ret, int *idx);
///void		print_dict(t_Dict *head);
void		memory_deallocate(t_Dict *head);
//void		modify_dict(t_Dict *head, char *key, char *value);
///////////////

/// split 하는 함수들 
int			split_num2(char *str);
int			split_frontword(char *str);
int			split_word(char *str, t_Dict **head);
int			split_num(char *str, t_Dict **temp);
int			split_space(char *str, t_Dict **temp);
int			split_printable(char *str, t_Dict **temp);
//////

///// 숫자 계산 함수들 
int			getrange(int num);
int			getrange2(int num);
int			check_num(long long n, t_Dict *head);
int			check_dict(t_Dict *head, long long num, int flag);
void		print_num(long long n, int *sep, t_Dict *head);
//////
#endif
