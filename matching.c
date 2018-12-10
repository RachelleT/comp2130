#include<stdio.h>
#include <string.h>

int main(int argc, char*argv[])
{
	int i,j;
	for (i=1; i<argc; i++)
	{
		for (j= i+1; j < argc; j++)
		{
			if (strcmp(argv[i],argv[j]) == 0){
				printf("Match at position [%d] = %s and position [%d] = %s\n",i,argv[i],j,argv[j]);
			}
		}
	}
}
