#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>

using namespace std;

int main()
{
	int N, M,graph[501];
	scanf("%d%d", &N, &M);
	int matrix[501][501];
	int visit[501];
	for (int i = 1; i <= N; i++) {
		graph[i] = 0;
		visit[i] = 0;
	}

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			matrix[i][j] = 0;

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d%d", &a, &b);

		matrix[a][b] = 1;
		matrix[b][a] = 1;

		graph[a]++;
		graph[b]++;
	}
	int oddnums = 0;
	for (int i = 1; i <= N; i++) {
		if (i != 1)
			printf(" ");
		printf("%d", graph[i]);

		if (graph[i] % 2 != 0)
			oddnums++;
	}

	//图必须连通

	queue<int>q;
	q.push(1);

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		visit[v] = 1;

		for (int w = 1; w <= N; w++) 
			if (matrix[v][w] == 1 && visit[w] == 0) 
				q.push(w);
			
		
		
	}

	int flag = 1;
	for (int i = 1; i <= N; i++)
		if (visit[i] == 0) {
			flag = 0;
			break;
		}


	if (oddnums == 0 && flag == 1)
		printf("\nEulerian");
	else if (oddnums == 2 && flag == 1)
		printf("\nSemi-Eulerian");
	else
		printf("\nNon-Eulerian");

	return 0;
}
