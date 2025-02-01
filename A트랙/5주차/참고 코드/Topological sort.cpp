#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) // https://www.acmicpc.net/problem/2252
{
	cin.tie(0)->sync_with_stdio(0);
	int vertex = 0, edge = 0;
	cin >> vertex >> edge;
	vector<vector<int>>graph(vertex + 1);
	vector<int>indegree(vertex + 1, 0);
	for (int i = 0; i < edge; ++i)
	{
		int start = 0, end = 0;
		cin >> start >> end;
		graph[start].push_back(end);
		indegree[end]++;
	}
	vector<int>result;
	queue<int>q;
	for (int i = 1; i <= vertex; ++i)
	{
		if (indegree[i] == 0)
		{
			q.push(i);
		}
	}
	while (!q.empty())
	{
		int current = q.front();
		q.pop();
		result.push_back(current);
		for (int i = 0; i < (int)graph[current].size(); ++i)
		{
			int node = graph[current][i];
			indegree[node]--;
			if (indegree[node] == 0)
			{
				q.push(node);
			}
		}
	}
	int len = result.size();
	for (int i = 0; i < len; ++i)
	{
		cout << result[i] << ' ';
	}
	return 0;
}