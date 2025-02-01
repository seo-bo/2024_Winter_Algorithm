#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;

ll power(ll a)
{
	ll result = 1, b = MOD - 2;
	while (b > 0)
	{
		if (b % 2)
		{
			result = (result * a) % MOD;
		}
		a = (a * a) % MOD;
		b /= 2;
	}
	return result;
}

int main(void) // https://www.acmicpc.net/problem/11401
{
	ll n = 0, k = 0;
	cin >> n >> k;
	vector<ll>factorial(n + 1, 1);
	for (ll i = 1; i <= n; ++i)
	{
		factorial[i] = (factorial[i - 1] * i) % MOD;
	}
	ll ans = factorial[n] * ((power(factorial[n - k]) * power(factorial[k])) % MOD);
	cout << ans % MOD;
}
