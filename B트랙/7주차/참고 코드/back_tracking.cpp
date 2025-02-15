#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int>& visited, vector<int>& ary, int depth, int num, int limit)
{
	if (depth == limit)
	{
		for (int i = 0; i < depth; ++i)
		{
			cout << ary[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= num; ++i)
	{
		if (visited[i])
		{
			continue;
		}
		visited[i] = 1;
		ary.push_back(i);
		dfs(visited, ary, depth + 1, num, limit);
		ary.pop_back();
		visited[i] = 0;
	}
}

int main(void) // https://www.acmicpc.net/problem/15649
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int>visited(n + 1, 0), ary;
	dfs(visited, ary, 0, n, m);
	return 0;
}