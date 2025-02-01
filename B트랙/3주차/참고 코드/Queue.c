#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Queue
{
	int front, rear, size;
	int* ary;
}Queue;

Queue* init(int total) // 배열 크기는 항상 넉넉하게!
{
	Queue* newqueue = (Queue*)malloc(sizeof(Queue));
	newqueue->front = newqueue->rear = 0;
	newqueue->size = total + 5;
	newqueue->ary = (int*)malloc(sizeof(int) * newqueue->size);
	return newqueue;
}

int empty(Queue* q)
{
	return q->front == q->rear;
}

void push(Queue* q, int num)
{
	q->rear = (q->rear + 1) % q->size;
	q->ary[q->rear] = num;
}

int pop(Queue* q)
{
	if (empty(q))
	{
		return -1;
	}
	q->front = (q->front + 1) % q->size;
	return q->ary[q->front];
}

int front(Queue* q)
{
	if (empty(q))
	{
		return -1;
	}
	return q->ary[(q->front + 1) % q->size];
}

int back(Queue* q)
{
	if (empty(q))
	{
		return -1;
	}
	return q->ary[q->rear];
}

int size(Queue* q)
{
	return (q->rear - q->front + q->size) % q->size;
}
char buffer[1 << 10] = { 0, };

int main(void) //https://www.acmicpc.net/problem/18258
{
	int n = 0;
	scanf("%d", &n);
	Queue* q = init(n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", buffer);
		if (!strcmp(buffer, "push"))
		{
			int num = 0;
			scanf("%d", &num);
			push(q, num);
		}
		else if (!strcmp(buffer, "pop"))
		{
			printf("%d\n", pop(q));
		}
		else if (!strcmp(buffer, "size"))
		{
			printf("%d\n", size(q));
		}
		else if (!strcmp(buffer, "empty"))
		{
			printf("%d\n", empty(q));
		}
		else if (!strcmp(buffer, "front"))
		{
			printf("%d\n", front(q));
		}
		else
		{
			printf("%d\n", back(q));
		}
	}
	free(q->ary);
	free(q);
	return 0;
}