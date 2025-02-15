#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll power(ll n, ll exp)
{
	if (exp == 0)
	{
		return 1LL;
	}
	ll mid = power(n, exp / 2);
	return (mid % 2 == 0) ? mid * mid : mid * mid * n;
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0, exp = 0;
	cin >> n >> exp;
	cout << power(n, exp);
	return 0;
}