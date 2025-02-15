#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int dfs(int i, int j, const string& A, const string& B, vector<vector<int>>& dp)
{
	if (i == (int)A.size() || j == (int)B.size())
	{
		return 0;
	}
	if (dp[i][j] != -1)
	{
		return dp[i][j];
	}
	dp[i][j] = max(dfs(i + 1, j, A, B, dp), dfs(i, j + 1, A, B, dp));
	if (A[i] == B[j])
	{
		dp[i][j] = max(dp[i][j], dfs(i + 1, j + 1, A, B, dp) + 1);
	}
	return dp[i][j];
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string A, B;
	cin >> A >> B;
	int alen = A.size(), blen = B.size();
	vector<vector<int>>dp(alen, vector<int>(blen, -1));
	cout << dfs(0, 0, A, B, dp);
	/*
	(Bottom-up)
	vector<vector<int>>dp(alen, vector<int>(blen, 0));
	for (int i = 1; i <= alen; ++i)
	{
		for (int j = 1; j <= blen; ++j)
		{
			if (A[i - 1] == B[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << dp[alen][blen];
	*/
	return 0;
}
