#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef struct bridge
{
	int vertex, value;
}bridge;

int dfs(vector<vector<bridge>>& graph, int node, int parent)
{
	if (graph[node].size() == 1 && graph[node].back().vertex == parent)
	{
		return graph[node].back().value;
	}
	int pivot = 0;
	for (int i = 0; i < (int)graph[node].size(); ++i)
	{
		int ver = graph[node][i].vertex;
		int num = graph[node][i].value;
		if (ver == parent)
		{
			continue;
		}
		pivot += min(dfs(graph, ver, node), num);
	}
	return pivot;
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int T = 0;
	cin >> T;
	for (int _ = 0; _ < T; ++_)
	{
		int n = 0, m = 0;
		cin >> n >> m;
		vector<vector<bridge>>graph(n + 1);
		for (int i = 0; i < m; ++i)
		{
			int v1 = 0, v2 = 0, num = 0;
			cin >> v1 >> v2 >> num;
			graph[v1].push_back({ v2,num });
			graph[v2].push_back({ v1,num });
		}
		cout << dfs(graph, 1, 0) << '\n';
	}
	return 0;
}