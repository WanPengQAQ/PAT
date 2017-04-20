#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<map>
#include<iostream>
#include<string>

#define MAX 2010

using namespace std;

int graph[MAX][MAX];

map<string, int> stringToInt; //名字转编号
map<int, string> intToString; //编号转名字
map<string, int>ans;
int index = 1;
int weight[MAX];
int strToInt(string s)
{
	if (stringToInt[s] == 0) {
		stringToInt[s] = index;
		intToString[index] = s;
		return index++;
	}
	else
		return stringToInt[s];
}
bool visit[MAX];

void solve(int u,int& head,int& sumNumber,int& sumWeight)
{
	if (weight[u] > weight[head])
		head = u;
	visit[u] = true;
	sumNumber++;
	for (int i = 1; i < index; i++) {
		if (graph[u][i] > 0) {
			
			sumWeight += graph[u][i];

			graph[u][i] = graph[i][u] = 0;
			if (visit[i] == false)
				solve(i, head, sumNumber, sumWeight);
		}
	}
}
void dfs(int k)
{
	for (int i = 1; i < index; i++) {
		if (visit[i] == false) {
			int head = i, sumNumber = 0, sumWeight = 0;
			solve(i, head, sumNumber, sumWeight);
			if (sumNumber > 2 && sumWeight > k)
				ans[intToString[head]] = sumNumber;
		}
	}
}
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);

	string a, b; int w;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> w;
		int aNum = strToInt(a);
		int bNum = strToInt(b);

		graph[aNum][bNum] += w;
		graph[bNum][aNum] += w;

		weight[aNum] += w;
		weight[bNum] += w;

	}

	dfs(k);

	cout << ans.size()<< endl;

	for (map<string, int>::iterator it = ans.begin(); it != ans.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}

	return 0;
}
