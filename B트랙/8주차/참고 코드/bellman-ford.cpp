#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef struct edge
{
	int vertex;
	ll value;
}edge;

int main(void) // https://www.acmicpc.net/problem/11657
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<edge>>graph(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int v1 = 0, v2 = 0;
		ll value = 0;
		cin >> v1 >> v2 >> value;
		graph[v1].push_back({ v2,value });
	}
	vector<ll>dist(n + 1, LLONG_MAX);
	dist[1] = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			for (int k = 0; k < (int)graph[j].size(); ++k)
			{
				int ver = graph[j][k].vertex;
				ll num = graph[j][k].value;
				if (dist[j] != LLONG_MAX && dist[ver] > dist[j] + num)
				{
					dist[ver] = dist[j] + num;
					if (i == n)
					{
						cout << -1;
						return 0;
					}
				}
			}
		}
	}
	for (int i = 2; i <= n; ++i)
	{
		cout << ((dist[i] == LLONG_MAX) ? -1 : dist[i]) << '\n';
	}
	return 0;
}