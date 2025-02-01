#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll, int, int>tp;

int find(vector<int>& parent, int root)
{
	if (parent[root] == root)
	{
		return parent[root];
	}
	return parent[root] = find(parent, parent[root]);
}

void merge(vector<int>& parent, vector<int>& rank, int root1, int root2)
{
	int r1 = find(parent, root1);
	int r2 = find(parent, root2);
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

int main(void) // https://www.acmicpc.net/problem/1197
{
	cin.tie(0)->sync_with_stdio(0);
	int v = 0, e = 0;
	cin >> v >> e;
	vector<int>parent(v + 1, 0), rank(v + 1, 0);
	for (int i = 1; i <= v; ++i)
	{
		parent[i] = i;
	}
	priority_queue<tp, vector<tp>, greater<tp>>pq;
	// 최소 힙 대신에 정렬을 사용해도 무방하다.
	for (int i = 0; i < e; ++i)
	{
		int v1 = 0, v2 = 0;
		ll cost = 0;
		cin >> v1 >> v2 >> cost;
		pq.push(make_tuple(cost, v1, v2));
	}
	int cnt = 0;
	ll ans = 0;
	while (!pq.empty() && cnt < v - 1)
	{
		auto [cost, v1, v2] = pq.top();
		pq.pop();
		if (find(parent, v1) != find(parent, v2))
		{
			cnt++;
			ans += cost;
			merge(parent, rank, v1, v2);
		}
	}
	cout << ans;
	return 0;
}