#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) // https://www.acmicpc.net/problem/11723
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	ll base = 0;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		int num = 0;
		if (str == "add")
		{
			cin >> num;
			base |= (1 << num);
		}
		else if (str == "remove")
		{
			cin >> num;
			base &= ~(1 << num);
		}
		else if (str == "check")
		{
			cin >> num;
			if (base & (1 << num))
			{
				cout << 1 << '\n';
			}
			else
			{
				cout << 0 << '\n';
			}
		}
		else if (str == "toggle")
		{
			cin >> num;
			base ^= (1 << num);
		}
		else if (str == "all")
		{
			base = (1 << 21) - 1;
		}
		else
		{
			base = 0;
		}
	}
	return 0;
}