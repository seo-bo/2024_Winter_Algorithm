#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& ary, int left, int mid, int right)
{
	int n1 = mid - left + 1, n2 = right - mid;
	vector<int>L(n1), R(n2);
	for (int i = 0; i < n1; ++i)
	{
		L[i] = ary[left + i];
	}
	for (int i = 0; i < n2; ++i)
	{
		R[i] = ary[mid + i + 1];
	}
	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			ary[k++] = L[i++];
		}
		else
		{
			ary[k++] = R[j++];
		}
	}
	while (i < n1)
	{
		ary[k++] = L[i++];
	}
	while (j < n2)
	{
		ary[k++] = R[j++];
	}
}

void merge_sort(vector<int>& ary, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		merge_sort(ary, left, mid);
		merge_sort(ary, mid + 1, right);
		merge(ary, left, mid, right);
	}
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int>ary(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> ary[i];
	}
	merge_sort(ary, 0, n - 1);
	for (int i = 0; i < n; ++i)
	{
		cout << ary[i] << ' ';
	}
	return 0;
}