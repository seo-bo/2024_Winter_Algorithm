#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs1(int node, vector<bool>& visited, vector<int>& stack, vector<vector<int>> &graph)
{
	visited[node] = true;
	for (int i = 0; i < (int)graph[node].size(); ++i)
	{
		int nxt = graph[node][i];
		if (visited[nxt])
		{
			continue;
		}
		dfs1(nxt, visited, stack, graph);
	}
	stack.push_back(node);
}

void dfs2(int node, vector<bool>& visited, vector<vector<int>> &graph, vector<int>& nodes)
{
	visited[node] = true;
	for (int i = 0; i < (int)graph[node].size(); ++i)
	{
		int nxt = graph[node][i];
		if (visited[nxt])
		{
			continue;
		}
		dfs2(nxt, visited, graph, nodes);
	}
	nodes.push_back(node);
}

int main(void) // https://www.acmicpc.net/problem/2150
{
	cin.tie(0)->sync_with_stdio(0);
	int vertex = 0, edge = 0;
	cin >> vertex >> edge;
	vector<vector<int>>graph(vertex + 1);
	vector<vector<int>>rev_graph(vertex + 1);
	vector<vector<int>>sccs;
	vector<bool>visited(vertex + 1, false);
	vector<int>stack;
	for (int i = 0; i < edge; ++i)
	{
		int start = 0, end = 0;
		cin >> start >> end;
		graph[start].push_back(end);
		rev_graph[end].push_back(start);
	}
	for (int node = 1; node <= vertex; ++node)
	{
		if (!visited[node])
		{
			dfs1(node, visited, stack, graph);
		}
	}
	vector<bool>(vertex + 1, false).swap(visited);
	while (!stack.empty())
	{
		int current = stack.back();
		stack.pop_back();
		if (visited[current])
		{
			continue;
		}
		vector<int>nodes;
		dfs2(current, visited, rev_graph, nodes);
		sort(nodes.begin(), nodes.end());
		sccs.push_back(nodes);
	}
	sort(sccs.begin(), sccs.end());
	cout << (int)sccs.size() << '\n';
	for (int i = 0; i < (int)sccs.size(); ++i)
	{
		for (int j = 0; j < (int)sccs[i].size(); ++j)
		{
			cout << sccs[i][j] << ' ';
		}
		cout << -1 << '\n';
	}
	return 0;
}