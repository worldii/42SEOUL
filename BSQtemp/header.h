#ifndef HEADER_H
# define HEADER_H

#define BUF_SIZE 800000

# include <stdlib.h>
# include<unistd.h>
# include<fcntl.h>

typedef struct s_map
{
	int row;
	int col;
	int emp;
	int full;
	int block;
	int nc;
	int num;
	int fd;
}map;

typedef struct s_dpmap {
	int **arr;
	int **b;
	char * temprow;
}dpmap;


/// 메인 함수 
void errorcheck (int argc, int t);
int  argcount1 (dpmap *dmap, map *tempmap);
int argcount2(map * tempmap, char *argv[],dpmap *dmap, int t);
//////

////// 메모리 담당 함수
int **mallocarr(map tempmap);
void freearray(map tempmap, int **arr, int **b, char *temprow);
void mallocarrays(int ***arr, int ***b, map tempmap);
//////

////// 정답 찾는 함수
void makebarray (int **b, map tempmap, int **arr);
int makedp (map tempmap, int **b);
void printarray(map tempmap, int **arr);
void findsquare(map tempmap, int ans, int **b, int **arr);
void solution(int **b, map tempmap,  int **arr);
/////

//// 입력 받는 함수 
int mapcheck(int input, map* tempmap, int *num);
int colcheck(int input, map *tempmap, int num, char * temprow);
int filemakearray(map tempmap, char *str, int **arr, int nc);
int stdmakearray(map tempmap, int **arr, char *temprow) ;
////

#endif
