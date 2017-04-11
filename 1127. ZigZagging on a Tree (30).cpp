#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;

int inorder[30], postorder[30];

struct node {
	int left, right, val;
};

struct node Tree[40];
int index = 0;

void buildTree(int root, int inL, int inR, int postL, int postR)
{
	if (inL > inR)
		return;

	int i = inL;
	while (inorder[i] != postorder[postR]) i++;//i是中序的Root的下标

	int leftnum = i - inL;
	int rightnum = inR - i;


	if (leftnum != 0) {
		Tree[root].left = postorder[postL + leftnum - 1];
		buildTree(Tree[root].left, inL, i - 1, postL, postL + leftnum - 1);
	}

	if (rightnum != 0) {
		Tree[root].right = postorder[postR - 1];
		buildTree(Tree[root].right, i + 1, inR, postR - rightnum, postR - 1);
	}

}

vector<int> res[20];
int rindex;
void bfs(int root)
{
	queue<int>q;
	q.push(root);
	int last, next;

	last = root;  rindex = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		res[rindex].push_back(x);

		if (Tree[x].left != -1) {
			q.push(Tree[x].left);
			next = Tree[x].left;
		}
		if (Tree[x].right != -1) {
			q.push(Tree[x].right);
			next = Tree[x].right;
		}
		
		if (x == last) {
			last = next;
			rindex++;
		}

	}

}
int main()
{
	int N;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &inorder[i]);
	for (int i = 0; i < N; i++)
		scanf("%d", &postorder[i]);

	for (int i = 0; i < 40; i++)
		Tree[i].left = Tree[i].right = -1;

	buildTree(postorder[N - 1], 0, N - 1, 0, N - 1);

	bfs(postorder[N - 1]);

	int flag = 1;
	for (int i = 0; i < rindex; i++) {

		
		if (i % 2 != 0) {
			for (int j = 0; j < res[i].size(); j++) {
				if (flag == 1) {
					flag = 0;
				}
				else
					printf(" ");
				printf("%d", res[i][j]);
			}
		}
		else {
			for (int j = res[i].size() - 1; j >= 0; j--) {
				if (flag == 1) {
					flag = 0;
				}
				else
					printf(" ");
				printf("%d", res[i][j]);
			}
		}

	}
	
	return 0;
}
