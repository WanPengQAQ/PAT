#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAX 100000

struct ndoe {
	int another, visit;
};
int cmp(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}
int main()
{
	ndoe *couples = (ndoe*)malloc(sizeof(ndoe)*MAX);
	for (int i = 0; i < MAX; i++) {
		couples[i].visit = 0;
		couples[i].another = -1;
	}
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int a, b;
		scanf("%d%d", &a, &b);

		couples[a].another = b;
		couples[b].another = a;
	}

	int K;
	scanf("%d", &K);

	int DamnSingle[MAX], index = 0;


	for (int i = 0; i < K; i++) {
		int temp;
		scanf("%d", &temp);
		DamnSingle[index++] = temp;

		couples[temp].visit = 1;
	}
	
	int res[MAX], res_index = 0;
	for (int i = 0; i < index; i++) {

		if (couples[couples[DamnSingle[i]].another].another == -1) {
			res[res_index++] = DamnSingle[i];
			continue;
		}



		if (couples[couples[DamnSingle[i]].another].visit != 1) {
			res[res_index++] = DamnSingle[i];
		}
	}
	qsort(res, res_index, sizeof(int), cmp);

	printf("%d\n", res_index);

	for (int i = 0; i < res_index; i++) {
		
		if (i != 0)
			printf(" ");

		printf("%05d", res[i]);
	
	}
	return 0;
}
