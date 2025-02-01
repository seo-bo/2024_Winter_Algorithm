#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
	int front, rear, size;
	int* ary;
}Queue;

Queue* init(int total)
{
	Queue* newqueue = (Queue*)malloc(sizeof(Queue));
	newqueue->front = newqueue->rear = 0;
	newqueue->size = total;
	newqueue->ary = (int*)malloc(sizeof(int) * newqueue->size);
}