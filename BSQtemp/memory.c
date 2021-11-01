#include"header.h"
int **mallocarr(map tempmap){
	int i;
	int ** b;

	b= (int **) malloc( sizeof (int *) * (tempmap.row+1));
	i = -1;
	while (++i <= tempmap.row)
		b[i] = (int *) malloc(sizeof(int) * (tempmap.col+1));
	return b;
}

void freearray(map tempmap, int **arr, int **b, char * temprow){
	int i;
	i = -1;
	while (++i < tempmap.row)
	{
		free(arr[i]);
		free(b[i]);
	}
	free(arr);
	free(b);
	if (temprow != NULL) free(temprow);
}

void mallocarrays(int ***arr, int ***b, map tempmap)
{
*arr = mallocarr(tempmap);
*b = mallocarr(tempmap);
}