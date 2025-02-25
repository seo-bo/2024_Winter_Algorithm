#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) // https://www.acmicpc.net/problem/11404
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<ll>>graph(n + 1, vector<ll>(n + 1, LLONG_MAX));
	for (int i = 1; i <= n; ++i)
	{
		graph[i][i] = 0;
	}
	for (int i = 0; i < m; ++i)
	{
		int v1 = 0, v2 = 0;
		ll value = 0;
		cin >> v1 >> v2 >> value;
		graph[v1][v2] = min(graph[v1][v2], value);
	}
	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (graph[i][k] != LLONG_MAX && graph[k][j] != LLONG_MAX)
				{
					graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cout << ((graph[i][j] == LLONG_MAX) ? 0 : graph[i][j]);
			cout << ' ';
		}
		cout << '\n';
	}
	return 0;
}