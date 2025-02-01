#include <bits/stdc++.h>
using namespace std;

int find(vector<int>& parent, int root)
{
	if (parent[root] == root)
	{
		return root;
	}
	return find(parent, parent[root]);
}

void merge(vector<int>& parent, int ver_1, int ver_2)
{
	int root1 = find(parent, ver_1);
	int root2 = find(parent, ver_2);
	if (ver_1 < ver_2)
	{
		parent[ver_2] = ver_1;
	}
	else
	{
		parent[ver_1] = ver_2;
	}
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int vertex = 0, edge = 0;
	cin >> vertex >> edge;
	vector<int>parent(vertex + 1, 0);
	for (int i = 0; i <= vertex; ++i)
	{
		parent[i] = i;
	}
	for (int i = 0; i < edge; ++i)
	{
		int v1 = 0, v2 = 0;
		cin >> v1 >> v2;
		int r1 = find(parent, v1), r2 = find(parent, v2);
		if (r1 != r2)
		{
			merge(parent, v1, v2);
		}
	}
	for (int i = 0; i < vertex; ++i)
	{
		cout << i << ' ' << find(parent, i) << '\n';
	}
	return 0;
}
