#include"header.h"

int stdmakearray(map tempmap, int **arr, char *temprow) {
	int i;
	int j;
	int ch;
	char buf[2];
	
	for (int i =  1 ; i<= tempmap.col; i++) arr[1][i] = temprow[i-1];
	i = 1;
	while (++i <= tempmap.row)
	{
		j = 0;
		while (++j <= tempmap.col)
		{
			ch = read(STDIN_FILENO,buf, 1);
			if ( ch <=0 || !(buf[0] == tempmap.block || buf[0] == tempmap.emp)) return 0;
			arr[i][j] = buf[0];
		}
		ch = read(STDIN_FILENO, buf, 1);
		if (ch <=0 || buf[0] != '\n') return 0;
	}
	ch =read (STDIN_FILENO, buf, 1);
	if (ch >0) return 0;
	return 1;
}

int mapcheck(int input, map* tempmap, int *num ){
	int ch;
	char buf[2];
	int nc;
	int mc;

	*num =0;
	nc = 0;
	mc = 0;
	ch = read(input, buf, 1);
	while ( ch > 0 && buf[0] != '\n' )
	{
		if ( ! ( '0' <= buf[0] && buf[0] <='9'))  break;
		while ( ch > 0 &&  ( '0' <= buf[0] && buf[0] <= '9') )
		{
			nc++;
			*num = *num * 10 + buf[0] - '0';
			ch = read(input, buf, 1);
		}
		while (ch >0 && buf[0] != '\n')
		{
			if (mc ==0) tempmap->emp = buf[0];
			else if (mc ==1) tempmap->block = buf[0];
			else if (mc ==2) tempmap->full = buf[0];
			mc++;
			ch = read (input, buf, 1);
		}
	}
	if( mc != 3  || ch <=0){return 0;}
	return nc;
}
int colcheck(int input, map *tempmap, int num, char * temprow)
{
	int ch;
	char buf[2];

	ch = read (input, buf, 1);
	tempmap->col = 0;
	while ( ch >0 && buf[0] != '\n')
	{
		if (temprow !=NULL) temprow[tempmap->col] = buf[0];
		tempmap->col++;
		ch = read (input, buf, 1);
	}
	if (temprow!=NULL) 	temprow[tempmap->col] = 0;
	tempmap->row = num;
	if (temprow == NULL) close(input);
	if (ch <=0 || buf[0] != '\n') {return 0;}
	return 1;
}
int filemakearray(map tempmap, char *str, int **arr, int nc)
{
	int i;
	int j;
	int ch;
	char buf[2];
	int fd = open(str,00);
	for (int i = 0 ; i< nc + 4 ; i++ ){read (fd, buf, 1);}
	i = 0;
	while (++i <= tempmap.row)
	{
		j = 0;
		while (++j <= tempmap.col)
		{	
			ch = read(fd,buf, 1);
			if ( ch <=0 || !(buf[0] == tempmap.block || buf[0] == tempmap.emp)) return 0;
			arr[i][j] = buf[0];
		}
		ch = read(fd, buf, 1);
		if (ch <=0 || buf[0] != '\n') return 0;
	}
	ch =read (fd, buf, 1);
	close(fd);
	if (ch > 0) return 0;
	return 1;
}
