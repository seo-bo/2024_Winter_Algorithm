#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) // https://www.acmicpc.net/problem/2805
{
	ll n = 0, m = 0;
	cin >> n >> m;
	vector<ll>v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	ll left = 0, right = *max_element(v.begin(), v.end()), ans = 0;
	while (left <= right)
	{
		ll mid = (left + right) / 2;
		ll pivot = 0;
		for (int i = 0; i < n; ++i)
		{
			pivot += max(0LL, v[i] - mid);
		}
		if (pivot >= m)
		{
			ans = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	cout << ans;
	return 0;
}
