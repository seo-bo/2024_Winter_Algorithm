#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Heap
{
	int heap[100001];
	int size;
}Heap;

Heap* create()
{
	Heap* h = (Heap*)calloc(1, sizeof(Heap));
	h->size = 0;
	return h;
}

void min_push(Heap* h, int num)
{
	int i = ++(h->size);
	while ((i != 1) && (num < h->heap[i / 2]))
	{
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = num;
}

int min_pop(Heap* h)
{
	if (!h->size)
	{
		return 0;
	}
	int parent = 1, child = 2;
	int num = h->heap[1], temp = h->heap[(h->size)--];
	while (child <= h->size)
	{
		if ((child < h->size) && (h->heap[child] > h->heap[child + 1]))
		{
			child++;
		}
		if (temp <= h->heap[child])
		{
			break;
		}
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return num;
}

void max_push(Heap* h, int num)
{
	int i = ++(h->size);
	while ((i != 1) && (num > h->heap[i / 2]))
	{
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = num;
}

int max_pop(Heap* h)
{
	if (!h->size)
	{
		return 0;
	}
	int parent = 1, child = 2;
	int num = h->heap[1], temp = h->heap[(h->size)--];
	while (child <= h->size)
	{
		if ((child < h->size) && (h->heap[child] < h->heap[child + 1]))
		{
			child++;
		}
		if (temp >= h->heap[child])
		{
			break;
		}
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return num;
}

void balance(Heap* max, Heap* min)
{
	if (!max->size && !min->size)
	{
		return;
	}
	if (min->size && max->heap[1] > min->heap[1])
	{
		int mini = min_pop(min);
		int maxi = max_pop(max);
		min_push(min, maxi);
		max_push(max, mini);
	}
	if (max->size > min->size + 1)
	{
		min_push(min, max_pop(max));
	}
}

int main(void) // https://www.acmicpc.net/problem/1655
{
	Heap* max = create();
	Heap* min = create();
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		scanf("%d", &a);
		max_push(max, a);
		balance(max, min);
		printf("%d\n", max->heap[1]);
	}
	free(max);
	free(min);
	return 0;
}