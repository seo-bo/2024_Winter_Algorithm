#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef struct pos
{
	int v, cnt;
}pos;

vector<int> bfs(int vertex, int edge, int limit, int start, vector<vector<int>>& graph)
{
	vector<bool>visited(vertex + 1, false);
	vector<int>answer;
	queue<pos>q;
	visited[start] = true;
	q.push({ start,0 });
	while (!q.empty())
	{
		pos current = q.front();
		q.pop();
		if (current.cnt == limit)
		{
			answer.push_back(current.v);
			continue;
		}
		for (int i = 0; i < (int)graph[current.v].size(); ++i)
		{
			int nxt = graph[current.v][i];
			if (!visited[nxt])
			{
				visited[nxt] = true;
				q.push({ nxt,current.cnt + 1 });
			}
		}
	}
	sort(answer.begin(), answer.end());
	return answer;
}

int main(void) // https://www.acmicpc.net/problem/18352
{
	cin.tie(0)->sync_with_stdio(0);
	int vertex = 0, edge = 0, dist = 0, start = 0;
	cin >> vertex >> edge >> dist >> start;
	vector<vector<int>>graph(vertex + 1);
	for (int i = 0; i < edge; ++i)
	{
		int v1 = 0, v2 = 0;
		cin >> v1 >> v2;
		graph[v1].push_back(v2);
	}
	vector<int>ans = bfs(vertex, edge, dist, start, graph);
	if (ans.empty())
	{
		cout << -1;
	}
	else
	{
		for (int i = 0; i < (int)ans.size(); ++i)
		{
			cout << ans[i] << '\n';
		}
	}
	return 0;
}