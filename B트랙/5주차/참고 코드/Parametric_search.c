#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef long long ll;

ll Max(ll a, ll b)
{
	return (a > b) ? a : b;
}

int main(void) // https://www.acmicpc.net/problem/2805
{
	ll n = 0, m = 0, maxi = 0;
	scanf("%lld %lld", &n, &m);
	ll* ary = (ll*)malloc(sizeof(ll) * n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%lld", &ary[i]);
		maxi = Max(maxi, ary[i]);
	}
	ll left = 0, right = maxi, ans = 0;
	while (left <= right)
	{
		ll mid = (left + right) / 2;
		ll pivot = 0;
		for (int i = 0; i < n; ++i)
		{
			pivot += Max(ary[i] - mid, 0);
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
	printf("%lld", ans);
	free(ary);
	return 0;
}
