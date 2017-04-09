#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAX 201

struct gnode {
	int adj, visit;
};

gnode graph[MAX][MAX];

int main()
{
	for (int i = 1; i < MAX; i++)
		for (int j = 1; j < MAX; j++) {
			graph[i][j].adj = 0;
			graph[i][j].visit = 0;
		}

	int N, M;
	scanf("%d%d", &N, &M);

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		graph[a][b].adj = 1;
		graph[b][a].adj = 1;
	}

	int K;
	scanf("%d", &K);

	for (int i = 0; i < K; i++) {
		int length; scanf("%d", &length);
		int cycle[5000];

		for (int i = 0; i < length; i++)
			scanf("%d", &cycle[i]);

		if (length != N + 1) {
			printf("NO\n");
			continue;
		}

		int nodevisit[250];
		for (int i = 1; i <= N; i++)
			nodevisit[i] = 0;

		int flag = 1, v1 = cycle[0];
		nodevisit[v1] = 1;
		for (int i = 1; i < length; i++) {
			if (graph[v1][cycle[i]].adj == 0) {//不连通！
				flag = 0;
				break;
			}
			else if (graph[v1][cycle[i]].visit == 1) {//连通但是已经走过了
				flag = 0;
				break;
			}
			else {
				graph[v1][cycle[i]].visit = 1;
				graph[cycle[i]][v1].visit = 1;
			}

			v1 = cycle[i];
			nodevisit[v1] = 1;
		}

		/*if (graph[cycle[length - 1]][cycle[0]].adj == 0 || graph[cycle[length - 1]][cycle[0]].visit == 1)
			flag = 0;*/

		if (cycle[0] != cycle[length - 1])
			flag = 0;

		for(int i = 1;i<=N;i++)
			if (nodevisit[i] == 0) {
				flag = 0;
				break;
			}

		if (flag == 0)
			printf("NO\n");
		else
			printf("YES\n");


		for (int i = 1; i < MAX; i++)
			for (int j = 1; j < MAX; j++) 
				graph[i][j].visit = 0;
	}

	return 0;
}
