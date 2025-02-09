#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef struct Knapsack
{
	int weight, value;
}Knapsack;

int main(void) // https://www.acmicpc.net/problem/12865
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, limit = 0;
	cin >> n >> limit;
	vector<Knapsack>item(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> item[i].weight >> item[i].value;
	}
	vector<vector<int>>dp(limit + 1, vector<int>(n + 1, 0));
	for (int j = 1; j <= n; ++j)
	{
		for (int i = 0; i <= limit; ++i)
		{
			dp[i][j] = dp[i][j - 1];
			if (i >= item[j].weight)
			{
				int k = item[j].weight, cost = item[j].value;
				dp[i][j] = max(dp[i][j - 1], dp[i - k][j - 1] + cost);
			}
		}
	}
	cout << dp[limit][n];
	return 0;
}