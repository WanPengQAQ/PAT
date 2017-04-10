#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10100

int cmp(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}
int main()
{
	int N, nums[MAX];
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &nums[i]);

	qsort(nums, N, sizeof(int), cmp);

	int res = 0;

	res = (nums[0] + nums[1]) / 2;

	for (int i = 2; i < N; i++) {
		res = (res + nums[i]) / 2;
	}

	printf("%d", res);

	return 0;
}
