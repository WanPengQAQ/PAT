#define _CRT_SECURE_NO_WARNINGS

#include<queue>
#include<vector>
#include<iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;

	for (int k = 0; k < N; k++) {
		int length;
		cin >> length;

		vector<int> v(length);
		vector<int> visit(length+1);
		bool result = true;

		for (int j = 0; j < length; j++) {
			cin >> v[j];
			if (visit[v[j]] == 0)
				visit[v[j]]++;
			else
				result = false;
		}

		bool flag = true;
		for (int i = 0; i < length; i++) {
			if (flag == false)
				break;

			for (int j = 0; j < length; j++) {

				if (i == j)
					continue;

				if (abs(i - j) == abs(v[i] - v[j])) {
					result = false;
					flag = false;
					break;
				}

			}
			

		}
		cout << ((result == true) ? "YES\n" : "NO\n");
	
	}
		

	return 0;
}
