#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<bool> get_prime(int n)
{
	vector<bool>prime(n + 1, true);
	prime[0] = prime[1] = false;
	for (ll i = 2; i <= sqrt(n); ++i)
	{
		if (prime[i])
		{
			for (int j = i * i; j <= n; j += i)
			{
				prime[j] = false;
			}
		}
	}
	return prime;
}

int main(void)
{
	int n = 0;
	cin >> n;
	vector<bool>prime = get_prime(n);
	for (int i = 2; i <= n; ++i)
	{
		if (prime[i])
		{
			cout << i << ' ';
		}
	}
	return 0;
}
