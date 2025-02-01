#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Deque
{
	int front, rear, size;
	int* ary;
}Deque;

Deque* init(int total)
{
	Deque* newqueue = (Deque*)malloc(sizeof(Deque));
	newqueue->front = newqueue->rear = 0;
	newqueue->size = total + 5;
	newqueue->ary = (int*)malloc(sizeof(int) * newqueue->size);
	return newqueue;
}

int empty(Deque* dq)
{
	return dq->front == dq->rear;
}

void push_back(Deque* dq, int num)
{
	dq->rear = (dq->rear + 1) % dq->size;
	dq->ary[dq->rear] = num;
}

void push_front(Deque* dq, int num)
{
	dq->ary[dq->front] = num;
	dq->front = (dq->front - 1 + dq->size) % dq->size;
}

int pop_front(Deque* dq)
{
	if (empty(dq))
	{
		return -1;
	}
	dq->front = (dq->front + 1) % dq->size;
	return dq->ary[dq->front];
}

int pop_back(Deque* dq)
{
	if (empty(dq))
	{
		return -1;
	}
	int temp = dq->ary[dq->rear];
	dq->rear = (dq->rear - 1 + dq->size) % dq->size;
	return temp;
}

int front(Deque* dq)
{
	if (empty(dq))
	{
		return -1;
	}
	return dq->ary[(dq->front + 1) % dq->size];
}

int back(Deque* dq)
{
	if (empty(dq))
	{
		return -1;
	}
	return dq->ary[dq->rear];
}

int size(Deque* dq)
{
	return (dq->rear - dq->front + dq->size) % dq->size;
}

int main(void) // https://www.acmicpc.net/problem/28279
{
	int n = 0;
	scanf("%d", &n);
	Deque* dq = init(n);
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		scanf("%d", &a);
		if (a == 1)
		{
			int num = 0;
			scanf("%d", &num);
			push_front(dq, num);
		}
		else if (a == 2)
		{
			int num = 0;
			scanf("%d", &num);
			push_back(dq, num);
		}
		else if (a == 3)
		{
			printf("%d\n", pop_front(dq));
		}
		else if (a == 4)
		{
			printf("%d\n", pop_back(dq));
		}
		else if (a == 5)
		{
			printf("%d\n", size(dq));
		}
		else if (a == 6)
		{
			printf("%d\n", empty(dq));
		}
		else if (a == 7)
		{
			printf("%d\n", front(dq));
		}
		else
		{
			printf("%d\n", back(dq));
		}
	}
	free(dq->ary);
	free(dq);
	return 0;
}