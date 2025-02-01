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

void push(Heap* h, int num)
{
	int i = ++(h->size);
	while ((i != 1) && (num < h->heap[i / 2]))
	{
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = num;
}

int pop(Heap* h)
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

int main(void) // https://www.acmicpc.net/problem/1927
{
	Heap* h = create();
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		scanf("%d", &a);
		if (a)
		{
			push(h, a);
		}
		else
		{
			printf("%d\n", pop(h));
		}
	}
	free(h);
	return 0;
}