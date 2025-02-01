#include <bits/stdc++.h>
using namespace std;

int find(vector<int>& parent, int root)
{
	if (parent[root] == root)
	{
		return parent[root];
	}
	return parent[root] = find(parent, parent[root]);
}

void merge(vector<int>& parent, vector<int>& rank, int ver_1, int ver_2)
{
	int r1 = find(parent, ver_1);
	int r2 = find(parent, ver_2);
	if (r1 != r2)
	{
		if (rank[r1] > rank[r2])
		{
			parent[r2] = r1;
		}
		else
		{
			parent[r1] = r2;
			if (rank[r1] == rank[r2])
			{
				rank[r2]++;
			}
		}
	}
}

int main(void) // https://www.acmicpc.net/problem/1717
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int>parent(n + 1, 0), rank(n + 1, 0);
	iota(parent.begin(), parent.end(), 0); // c++의 함수. 마지막에 지정한 값부터 시작하는 연속된 값을 채우는 함수이다. ex) p[0] = 0, p[1] =1, p[2] = 2...
	for (int i = 0; i < m; ++i)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		if (a)
		{
			if (find(parent, b) == find(parent, c))
			{
				cout << "YES" << '\n';
			}
			else
			{
				cout << "NO" << '\n';
			}
		}
		else
		{
			int r1 = find(parent, b), r2 = find(parent, c);
			if (r1 != r2) // 불필요한 함수 호출 없애려고 조건문 만듬. 굳이 조건문 설정안하고 merge만 불러도 상관 없음
			{
				merge(parent, rank, b, c);
			}
		}
	}
	return 0;
}