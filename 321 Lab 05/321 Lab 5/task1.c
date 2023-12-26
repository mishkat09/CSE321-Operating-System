#include <pthread.h>
#include <stdio.h>
#include <string.h>

int main()
{

	int n, m;
	n = 5; 
    m = 4; 
    int alloc[5][4] = { { 0, 1, 0, 3 },
                      { 2, 0, 0, 0 }, 
                      { 3, 0, 2, 0 },
                      { 2, 1, 1, 5 }, 
                      { 0, 0, 2, 2 } }; 
    int max[5][4] = { { 6, 4, 3, 4 }, 
                      { 3, 2, 2, 1 }, 
                      { 9, 1, 2, 6 }, 
                      { 2, 2, 2, 8 }, 
                      { 4, 3, 3, 7 } }; 
    int avail[4] = { 3, 3, 2, 1 }; 


    int need[n][m];
	int finished[n];
	int a[n];
	int  i_n = 0;
	int fl = 1;
	
	for (int l = 0; l < n; l++) {
		finished[l] = 0;
	}
	
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++)
			need[i][j] = max[i][j] - alloc[i][j];
	}
	
	for (int l = 0; l < 5; l++) 
	{
		for (int i = 0; i < n; i++) 
		{
			if (finished[i] == 0)
			{
				int fl = 0;
				for (int j = 0; j < m; j++)
				{
					if (need[i][j] > avail[j])
					{
						fl = 1;
						break;
					}
				}

				if (fl == 0)
				{
					a[i_n++] = i;
					for (int l = 0; l < m; l++)
						avail[l] += alloc[i][l];
					finished[i] = 1;
				}
			}
		}
	}

	
	
	for(int i=0;i<n;i++)
	{
	if(finished[i]==0)
	{
		fl=0;
		printf("Deadlock Ahead");
		break;
	}
	}
	
	if(fl==1)
	{
	printf("Safe here\n");
	}
	

	return 0;
}