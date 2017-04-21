#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#define MAX 101

using namespace std;
int N, M, W;//总结点数 非叶子结点 target
vector<vector<int>>graph(MAX);
vector<int>path(MAX);
int weight[MAX];

void DFS(int root,int tempSum,int nodeNum) 
{
	if (tempSum > W)
		return ;
	if (tempSum == W) {
		if (graph[root].size() != 0)
			return;
		printf("%d", weight[0]);
		for (int i = 0; i < nodeNum; i++) {

			printf(" %d", weight[path[i]]);

			if (i == nodeNum - 1)
				printf("\n");
		}
	}
	for (int i = 0; i < graph[root].size(); i++) {
		path[nodeNum] = graph[root][i];
		DFS(graph[root][i], tempSum + weight[graph[root][i]], nodeNum + 1);

	}

	//tempSum += weight[root];

	//bool flag = false;
	//for (int i = 0; i < graph[root].size(); i++) {
	//	bool set = false;
	//	if (true == DFS(graph[root][i], level + 1, tempSum)) {
	//		if (set == false) {
	//			saveMartix[level].push_back(root);
	//			set = true;
	//		}
	//		flag = true;
	//	}
	//}

	//if (graph[root].size() == 0) {//叶子结点
	//	if (tempSum == W) {
	//		saveMartix[level].push_back(root);
	//		return true;
	//	}
	//	else
	//		return false;
	//}
	//else
	//	return flag;
}
int cmp(int a, int b)
{
	return weight[a] > weight[b];
}
int main()
{
	scanf("%d%d%d", &N, &M, &W);
	
	for (int i = 0; i < N; i++)
		scanf("%d", &weight[i]);

	for (int i = 0; i < M; i++) {
		int id, k, son;
		scanf("%d%d", &id, &k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &son);
			graph[id].push_back(son);
		}

		sort(graph[id].begin(), graph[id].end(), cmp);
	}

	DFS(0,weight[0],0);
	


	system("pause");
	return 0;
}
