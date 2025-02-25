#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef struct edge
{
	int vertex;
	ll value;
}edge;

struct cmp
{
	bool operator() (const edge& a, const edge& b)
	{
		return a.value > b.value;
	}
};

int main(void) // https://www.acmicpc.net/problem/1916
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<edge>>graph(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int v1 = 0, v2 = 0;
		ll num = 0;
		cin >> v1 >> v2 >> num;
		graph[v1].push_back({ v2,num });
	}
	int start = 0, end = 0;
	cin >> start >> end;
	priority_queue<edge, vector<edge>, cmp>pq;
	vector<ll>dist(n + 1, LLONG_MAX);
	dist[start] = 0;
	pq.push({ start,0 });
	while (!pq.empty())
	{
		edge cur = pq.top();
		pq.pop();
		if (dist[cur.vertex] < cur.value)
		{
			continue;
		}
		for (int i = 0; i < (int)graph[cur.vertex].size(); ++i)
		{
			int ver = graph[cur.vertex][i].vertex;
			ll num = graph[cur.vertex][i].value;
			if (dist[ver] > dist[cur.vertex] + num)
			{
				dist[ver] = dist[cur.vertex] + num;
				pq.push({ ver,dist[ver] });
			}
		}
	}
	cout << dist[end];
	return 0;
}