#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10100


int main()
{
	int M, N, S;
	scanf("%d%d%d", &M, &N, &S);

	if (S > M) {
		printf("Keep going...");
		return 0;
	}



	char str[MAX][32];

	for (int i = 0; i < M; i++)
		scanf("%s", &str[i]);

	int res[MAX], index = 0;

	for (int i = S - 1; i < M;) {
		
		for (int j = 0; j < index; j++) 
			if (strcmp(str[i], str[res[j]]) == 0) {
				i++;
				break;
			}

		res[index++] = i;
		
		i += N;
	}

	
	
	for (int i = 0; i < index; i++)
		printf("%s\n", &str[res[i]]);

	
	
	return 0;
}
