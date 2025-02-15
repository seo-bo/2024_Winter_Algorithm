#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void merge(int* ary, int left, int mid, int right)
{
	int n1 = mid - left + 1, n2 = right - mid;
	int* L = (int*)malloc(sizeof(int) * n1);
	int* R = (int*)malloc(sizeof(int) * n2);
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
	free(L);
	free(R);
}

void sort(int* ary, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		sort(ary, left, mid);
		sort(ary, mid + 1, right);
		merge(ary, left, mid, right);
	}
}

int main(void)
{
	int n = 0;
	scanf("%d", &n);
	int* ary = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &ary[i]);
	}
	sort(ary, 0, n - 1);
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", ary[i]);
	}
	free(ary);
	return 0;
}