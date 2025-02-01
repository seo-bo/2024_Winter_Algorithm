#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

int lower_search(int* ary, int size, int target)
{
	int left = 0, right = size - 1, ans = size;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (ary[mid] >= target)
		{
			ans = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	return ans;
}

int main(void)
{
	int n = 0, m = 0;
	scanf("%d", &n);
	int* ary = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &ary[i]);
	}
	qsort(ary, n, sizeof(int), compare);
	scanf("%d", &m);
	while (m--)
	{
		int a = 0;
		scanf("%d", &a);
		int res = lower_search(ary, n, a);
		if (res == n)
		{
			printf("하한 없음\n");
		}
		else
		{
			printf("%d\n", ary[res]);
		}
	}
	free(ary);
	return 0;
}
