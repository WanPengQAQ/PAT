#define _CRT_SECURE_NO_WARNINGS

#include<queue>
#include<vector>
#include<iostream>
#include<string.h>
#include<string>

using namespace std;

struct treenode {
	int left, right;
	string str;
};

vector<treenode>v;

int Root;

string solve(int root)
{
	if (root == -1)
		return "";
	if (v[root].right != -1) {

		if (root != Root)
			v[root].str = "(" + solve(v[root].left) + v[root].str + solve(v[root].right) + ")";
		else
			v[root].str = solve(v[root].left) + v[root].str + solve(v[root].right);

	}

	return v[root].str;
	
}

int main()
{
	int N;
	cin >> N;
	
	v.resize(N + 1);
	vector<bool>isVisit(N + 1, true);
	for (int i = 1; i <= N; i++) {
		cin >> v[i].str >> v[i].left >> v[i].right;
		if (v[i].left != -1)	isVisit[v[i].left] = false;
		if (v[i].right != -1)	isVisit[v[i].right] = false;
	}
	
	
	for (int i = 1; i <= N + 1; i++)
		if (isVisit[i] == true) {
			Root = i;
			break;
		}

	string res = solve(Root);
	cout << res;
	return 0;
}
