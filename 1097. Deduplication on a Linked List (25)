

//题目大意是一个链表，绝对值相同的只输出一次，再把所有相同的连接成一个链表
//先遍历一遍，把前面出现坐上标记，顺便找到第一个被删除的结点的Addr
//我用的是懒惰删除先输出所有没有标记的，注意next一定要找下一个没有被删除的结点的Addr
//再用相同的方法输出所有被删除的结点
//TIP:除了 -1 都要五位五位的输出
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAX 100000

struct node {
	int key, next;
	int lazyDel;
};

int main()
{
	struct node* a = malloc(sizeof(struct node)*MAX);

	int first, N;
	scanf("%d %d", &first, &N);

	//int* check = malloc(sizeof(int) * 1001);
	int check[10010];
	for (int i = 0; i < N; i++) {
		int Address, Key, Next;
		scanf("%d %d %d", &Address, &Key, &Next);

		a[Address].key = Key;
		a[Address].next = Next;
		a[Address].lazyDel = 0;

		check[abs(Key)] = 1;
	}

	int delfirst = -1 , flag = 1;
	for (int i = first; i != -1; i = a[i].next) {
		
		if (check[abs(a[i].key)] == 1) {//第一次出现
		
			a[i].lazyDel = 0;
			check[abs(a[i].key)] = 0;

		}
		else {
			
			if (flag == 1) {
				flag = 0;

				delfirst = i;
			
			}

			a[i].lazyDel = 1;//懒惰删除
		
		}

	}

	
//	printf("\n\n\n");
	for (int i = first; i != -1;) {
		printf("%05d %d ", i, a[i].key);

		int temp;
		for (temp = a[i].next; (a[temp].lazyDel == 1) && temp != -1; temp = a[temp].next);//下一个没删除的结点

		if (temp != -1)
			printf("%05d\n", temp);
		else
			printf("-1\n");

		i = temp;
		if (temp == -1)
			break;
	}

	if (delfirst == -1)
		return 0;
//	printf("\n\n\n");
	for (int i = delfirst; i != -1;) {
		printf("%05d %d ", i, a[i].key);

		int temp;
		for (temp = a[i].next; (a[temp].lazyDel == 0) && temp != -1; temp = a[temp].next);//下一个删除的结点

		if (temp != -1)
			printf("%05d\n", temp);
		else
			printf("-1\n");

		i = temp;
		if (temp == -1)
			break;
	}


	system("pause");
	return 0;
}
