#include <pthread.h>
#include <stdio.h>
#include <string.h>

int main()
{

	int n, m;

	n = 6;
    m = 4;
    int alloc[6][4] = { { 0, 1, 0, 3 },
                        { 2, 0, 0, 3 }, 
                        { 3, 0, 2, 0 }, 
                        { 2, 1, 1, 5 }, 
                        { 0, 0, 2, 2 }, 
                        {1, 2 , 3, 1 } }; 
    int max[6][4] = { { 6, 4, 3, 4 }, 
                        { 3, 2, 2, 4 }, 
                        { 9, 1, 2, 6 },
                        { 2, 2, 2, 8 }, 
                        { 4, 3, 3, 7 }, 
                        { 6, 2 , 6, 5 } }; 
    int avail[4] = { 2, 2, 2, 1 };

	int finished[n];
	int a[n];
	int i_n = 0;
	int need[n][m];
	
	for (int l = 0; l < n; l++) 
	{
		finished[l] = 0;
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			need[i][j] = max[i][j] - alloc[i][j];
		}
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
					{
						avail[l] += alloc[i][l];
					    finished[i] = 1;
					}
				}
			}
		}
	}

	int flag = 1;
	
	for(int i=0;i<n;i++)
	{
	if(finished[i]==0)
	{
		flag=0;
		printf("Deadlock Found");
		break;
	}
	}
	
	if(flag==1)
	{
	printf(" Safe Sequence Found:\n");
	for (int i = 0; i < n - 1; i++)
		printf(" P%d ==>", a[i]);
	printf(" P%d", a[n - 1]);
	}

	return 0;

}