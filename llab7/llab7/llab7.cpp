#include <time.h>
#include <stdio.h>
#include <Windows.h>

void DFS(int k, int* vis, int** G, int n)
{
	vis[k] = 1;
	printf("%d ", k);
	for (int i = 0; i < n; i++)
	{
		if (G[k][i] == 1 && vis[i] == 0)
		{
			DFS(i, vis, G, n);
		}
	}
}

int main(void)
{
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	int n;
	printf("Введите кол-во вершин: ");
	scanf_s("%d", &n);
	int** G = (int**)malloc(n * sizeof(int*));
	int* vis = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		vis[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		G[i] = (int*)malloc(n * sizeof(int));
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			G[i][j] = rand() % 2;
			if (i == j)
			{
				G[i][j] = 0;
			}
			G[j][i] = G[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d\t", G[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d ", vis[i]);
	}
	printf("\n");
	int k = 0;
	printf("Вершина: \n");
	scanf_s("%d", &k);
	DFS(k, vis, G, n);
}