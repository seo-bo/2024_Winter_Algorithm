#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef struct Matrix
{
	ll row, col;
}Matrix;

ll dfs(int left, int right, vector<vector<ll>>& dp, vector<Matrix>& cost)
{
	if (left == right)
	{
		return 0LL;
	}
	if (dp[left][right] != -1)
	{
		return dp[left][right];
	}
	dp[left][right] = LLONG_MAX;
	for (int mid = left; mid < right; ++mid)
	{
		dp[left][right] = min(dp[left][right], dfs(left, mid, dp, cost) + dfs(mid + 1, right, dp, cost) + cost[left].row * cost[mid].col * cost[right].col);
	}
	return dp[left][right];
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<Matrix>cost(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> cost[i].row >> cost[i].col;
	}
	vector<vector<ll>>dp(n + 1, vector<ll>(n + 1, -1));
	cout << dfs(1, n, dp, cost);
	/*
	(Bottom-up)
	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; i + j <= n; ++j)
		{
			dp[j][i + j] = LLONG_MAX;
			for (int k = j; k <= i + j; ++k)
			{
				dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + cost[j].row * cost[k].col * cost[i + j].col);
			}
		}
	}
	cout << dp[1][n];
	*/
	return 0;
}