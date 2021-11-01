/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 03:52:43 by jonghapa          #+#    #+#             */
/*   Updated: 2021/10/28 10:34:16 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define BUF_SIZE 800000

# include <stdlib.h>
# include<unistd.h>
# include<fcntl.h>

typedef struct s_map
{
	int	row;
	int	col;
	int	emp;
	int	full;
	int	block;
	int	nc;
	int	num;
	int	fd;
}				t_map;

typedef struct s_dpmap {
	int		**arr;
	int		**b;
	char	*temprow;
}				t_dpmap;

void	fillsquare(long long cnt, int **arr, int ans, t_map tempmap);
int		filemakearray(t_map tempmap, char *str, int **arr, int nc);
int		stdmakearray(t_map tempmap, int **arr, char *temprow);
void	makebarray(int **b, t_map tempmap, int **arr);
int		makedp(t_map tempmap, int **b);
void	printarray(t_map tempmap, int **arr);
void	findsquare(t_map tempmap, int ans, int **b, int **arr);
int		**mallocarr(t_map tempmap);
void	freearray(t_map tempmap, int **arr, int **b, char *temprow);
int		mapcheck(int input, t_map *tempmap, int *num);
int		numcheck(int ch, char buf[], int *nc, int input);
int		setmap(int *mc, char buf[], t_map *tempmap);
int		colcheck(int input, t_map *tempmap, int num, char *temprow);
int		stdsmall(t_map tempmap, int**arr, int i);
void	solution(int **b, t_map tempmap, int **arr);
void	mallocarrays(int ***arr, int ***b, t_map tempmap);
void	errorcheck(int argc, int t);
int		argcount1(t_dpmap *dmap, t_map *tempmap);
int		argcount2(t_map *tempmap, char *argv[], t_dpmap *dmap, int t);
int		smallmake(t_map tempmap, int fd, int **arr, int i);
#endif
