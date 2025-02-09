#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dfs(int node, int limit, int distance, vector<vector<int>>& graph, vector<int>& apple, vector<int>& visited)
{
	visited[node] = 1;
	int cnt = apple[node];
	for (int i = 0; i < (int)graph[node].size() && distance + 1 <= limit; ++i)
	{
		int nxt = graph[node][i];
		if (visited[nxt])
		{
			continue;
		}
		cnt += dfs(nxt, limit, distance + 1, graph, apple, visited);
	}
	return cnt;
}

int main(void) // https://www.acmicpc.net/problem/25516
{
	cin.tie(0)->sync_with_stdio(0);
	int vertex = 0, dist = 0;
	cin >> vertex >> dist;
	vector<vector<int>>graph(vertex);
	for (int i = 0; i < vertex - 1; ++i)
	{
		int v1 = 0, v2 = 0;
		cin >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	vector<int>apple(vertex, 0), visited(vertex, 0);
	for (int i = 0; i < vertex; ++i)
	{
		cin >> apple[i];
	}
	cout << dfs(0, dist, 0, graph, apple, visited);
	return 0;
}