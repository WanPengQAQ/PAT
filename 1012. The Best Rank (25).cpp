#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<stdlib.h>

struct tempNode {
	int Class; int rank;
};


struct node {
	int ID;
	int C, M, E, A;
	tempNode rankArray[4]; //
};

int cmpC(const void* a, const void* b) {
	return (*(node*)b).C - (*(node*)a).C;
}
int cmpM(const void* a, const void* b) {
	return (*(node*)b).M - (*(node*)a).M;
}
int cmpE(const void* a, const void* b) {
	return (*(node*)b).E - (*(node*)a).E;
}
int cmpA(const void* a, const void* b) {
	return (*(node*)b).A - (*(node*)a).A;
}
int cmp(const void* a, const void* b) {

	if ((*(tempNode*)a).rank != (*(tempNode*)b).rank)
		return (*(tempNode*)a).rank - (*(tempNode*)b).rank;
	else
		return (*(tempNode*)b).Class - (*(tempNode*)a).Class;
}

int main(){
	int n, m;   scanf("%d%d", &n, &m);

	//node* a = new node[n];

	node a[2010];
	
	//node a[100];
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d%d", &a[i].ID, &a[i].C, &a[i].M, &a[i].E);
		a[i].A = (a[i].C + a[i].M + a[i].E) / 3;
		(a[i].rankArray)[0].Class = 4; //A
		(a[i].rankArray)[1].Class = 3; //C
		(a[i].rankArray)[2].Class = 2; //M
		(a[i].rankArray)[3].Class = 1; //E
	}

	
	qsort(a, n, sizeof(node), cmpC);
	for (int i = 0; i < n; i++) 
		a[i].rankArray[1].rank = i + 1;
	
	qsort(a, n, sizeof(node), cmpM);
	for (int i = 0; i < n; i++)
		a[i].rankArray[2].rank = i + 1;

	qsort(a, n, sizeof(node), cmpE);
	for (int i = 0; i < n; i++)
		a[i].rankArray[3].rank = i + 1;

	qsort(a, n, sizeof(node), cmpA);
	for (int i = 0; i < n; i++)
		a[i].rankArray[0].rank = i + 1;



	for (int i = 0; i < m; i++) {
		int chID; scanf("%d", &chID);

		bool flag = false;
		int j;
		for (j = 0; j < n; j++) {
			if (a[j].ID == chID) {
				flag = true;
				break;
			}
		}

		if (flag) {
			//A > C > M > E
			//4   3   2   1
			qsort(a[j].rankArray, 4, sizeof(tempNode), cmp);
			
			switch (a[j].rankArray[0].Class)
			{
			case 1:printf("%d E\n", a[j].rankArray[0].rank); break;
			case 2:printf("%d M\n", a[j].rankArray[0].rank); break;
			case 3:printf("%d C\n", a[j].rankArray[0].rank); break;
			case 4:printf("%d A\n", a[j].rankArray[0].rank); break;
			}
			
		}
		else {
			printf("N/A\n");
		}

	}

	return 0;
}
