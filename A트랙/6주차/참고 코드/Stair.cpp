#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) // https://www.acmicpc.net/problem/2579
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>cost(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> cost[i];
	}
	vector<int>dp(n + 1, 0);
	dp[1] = cost[1];
	dp[2] = cost[1] + cost[2];
	for (int i = 3; i <= n; ++i)
	{
		dp[i] = max(dp[i - 2], dp[i - 3] + cost[i - 1]) + cost[i];
	}
	cout << dp[n];
	return 0;
}