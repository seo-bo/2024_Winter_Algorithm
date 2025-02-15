#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
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
	ll n = 0, exp = 0;
	scanf("%lld %lld", &n, &exp);
	printf("%lld", power(n, exp));
	return 0;
}