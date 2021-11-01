#include"header.h"
void solution(int **b, map tempmap,  int **arr)
{
	makebarray(b, tempmap, arr);
	int ans = makedp (tempmap, b);
	findsquare(tempmap,ans, b, arr);
	printarray(tempmap, arr);

}


void makebarray (int **b, map tempmap, int **arr)
{
	int i;
	int j;

	i = -1;
	while (++i<= tempmap.row){
			j = -1;
		while (++j <= tempmap.col) {
				b[i][j] = 0;
		}
	}
	i = 0;
	while ( ++i<=tempmap.row)
	{
		j = 0;
		while (++j <=tempmap.col)
		{
			b[i][j] = 1;
			if ( arr[i][j] == tempmap.block) b[i][j] = 0;
		}
	}
}
int makedp (map tempmap, int **b){
	int ans = 0;
		for(int i = 1 ; i <= tempmap.row; i ++){
			for(int j = 1 ; j <= tempmap.col; j++){
				if(b[i][j] != 0)
				{
					b[i][j] = b[i-1][j]+1;
					if ( b[i][j] > b[i][j-1]+1) b[i][j] = b[i][j-1]+1;
					if (b[i][j] > b[i-1][j-1] +1 ) b[i][j] = b[i-1][j-1]+1;
					if (ans < b[i][j] )
					{
						ans = b[i][j] ;
					}

				}
			}
		}
	return ans;
}
void printarray(map tempmap, int **arr)
{
	for (int i = 1; i<= tempmap.row ; i++)
	{
		for (int j =  1; j<= tempmap.col ; j++)
		{
			write(1, &arr[i][j],1);
		}
		write(1, "\n", 1);
	}write(1, "\n", 1);
}
void findsquare(map tempmap, int ans, int **b, int **arr)
{
	int i;
	int flag;
	int j;
	i = 0;
	flag =1;
	while (++i <= tempmap.row)
	{
		j = 0;
		while (++j <= tempmap.col)
		{
			if ( ans == b[i][j]) {flag = 0;	break;}
		}
		if( flag ==0) break;
	}
	for (int t= i - ans+1; t<= i ; t++){
		for (int k = j - ans+1;k<= j ; k++)
			{
			arr[t][k] = tempmap.full;
		}
	}
}