#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

int binary_search(int* ary, int size, int target)
{
	int left = 0, right = size - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (ary[mid] == target)
		{
			return 1;
		}
		else if (ary[mid] < target)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return 0;
}

int main(void) // https://www.acmicpc.net/problem/1920
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
		printf("%d\n", binary_search(ary, n, a));
	}
	free(ary);
	return 0;
}
