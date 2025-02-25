#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef struct edge
{
	int x, y, value;
}edge;

int main(void) // https://www.acmicpc.net/problem/1261
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> m >> n;
	vector<vector<int>>grid(n, vector<int>(m, 0));
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; ++j)
		{
			grid[i][j] = str[j] - '0';
		}
	}
	deque<edge>dq;
	vector<vector<int>>visited(n, vector<int>(m, INT_MAX));
	visited[0][0] = grid[0][0];
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	dq.push_back({ 0,0,visited[0][0] });
	while (!dq.empty())
	{
		edge cur = dq.front();
		dq.pop_front();
		if (cur.x == n - 1 && cur.y == m - 1)
		{
			cout << cur.value;
			break;
		}
		for (int i = 0; i < 4; ++i)
		{
			int nx = cur.x + dir[i][0];
			int ny = cur.y + dir[i][1];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				if (visited[nx][ny] > visited[cur.x][cur.y] + grid[nx][ny])
				{
					visited[nx][ny] = visited[cur.x][cur.y] + grid[nx][ny];
					if (grid[nx][ny])
					{
						dq.push_back({ nx,ny,visited[nx][ny] });
					}
					else
					{
						dq.push_front({ nx,ny,visited[nx][ny] });
					}
				}
			}
		}
	}
	return 0;
}