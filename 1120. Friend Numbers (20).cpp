#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAX 10010


int friendNumbers(int n)
{
	int res = 0;
	while (n > 0) {
		res += n % 10;
		n /= 10;
	}
	return res;
}

int cmp(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}
int main()
{
	int N, nums[MAX];
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		temp = friendNumbers(temp);
		nums[i] = temp;
	}

	qsort(nums, N, sizeof(int), cmp);

	int visit[50];
	for (int i = 0; i < 50; i++)
		visit[i] = 0;

	int res[MAX],index = 0;

	for (int i = 0; i < N; i++) {
		if (visit[nums[i]] == 0) {
			visit[nums[i]] = 1;
			
			res[index++] = nums[i];

		}
	}

	printf("%d\n",index );

	for (int i = 0; i < index; i++)
		if (i == 0)
			printf("%d", res[i]);
		else
			printf(" %d", res[i]);

	return 0;
}
