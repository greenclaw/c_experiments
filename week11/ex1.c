#include <stdlib.h>
#include <stdio.h>
#define N_RES 3
#define N_PROC 5

int main()
{
	int *E = (int*)malloc(N_RES * sizeof(int));
	int *A = (int*)malloc(N_RES * sizeof(int));
	int **C = (int**)malloc(N_PROC * sizeof(int*));
	int **R = (int**)malloc(N_PROC * sizeof(int*));
	FILE *fp;

	int num = 0;
	int i=0, j=0;
	fp = fopen("./input.txt", "r");
   	
	do {
		for(i=0; i<N_RES; i++)
		{
			sscanf("%d", &num);
			*E = num;
			E++;
		}
		for(i=0; i<N_RES; i++)
		{
			sscanf("%d", &num);
			*A = num;
			A++;
		}
		for(i=0; i<N_PROC; i++)
		{
			for(j=0; j<N_RES; j++)
			{
				sscanf("%d", &num);
				**C = ;
			}
		}

	} while(!feof(file));

		
	fclose(fp);
	if (line)  
		free(line);
	return 0;
}


