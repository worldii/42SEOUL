#include"header.h"

int main(int argc, char *argv[])
{
		map tempmap;
		dpmap dmap;
		int t;

		dmap.temprow = NULL;
		t = 0;
		while (t++ <argc)
		{
			if (argc == 1) 
			{
				if (argcount1(&dmap, &tempmap)==1) break;
			}
			else
			{
				if ( t == argc) break;
				if (argcount2(&tempmap, argv, &dmap, t)==1) break;
			}
			solution(dmap.b, tempmap, dmap.arr);
			freearray(tempmap, dmap.arr, dmap.b, dmap.temprow);
		}
		errorcheck(argc, t);
system ("leaks BSQ");
		return 0;
}
