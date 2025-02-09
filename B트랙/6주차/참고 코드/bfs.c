#define _CRT_SECURE_NO_WARNINGS
#define SIZE 350001
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int vertex;
	struct Node* link;
} Node;

typedef struct Queue
{
	int q[SIZE];
	int front, rear;
} Queue;

void init(Queue* queue)
{
	queue->front = queue->rear = 0;
}

int EMPTY(Queue* queue)
{
	return queue->front == queue->rear;
}

void push(Queue* queue, int value)
{
	queue->q[queue->rear++] = value;
}

int pop(Queue* queue)
{
	return queue->q[queue->front++];
}

void add_edge(Node** graph, int v1, int v2)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->vertex = v2;
	node->link = graph[v1];
	graph[v1] = node;
}

int cmp(const void* a, const void* b)
{
	return *(const int*)a - *(const int*)b;
}

int* bfs(int vertex, int limit, int start, Node** graph, int* len)
{
	int* visited = (int*)malloc((vertex + 1) * sizeof(int));
	for (int i = 0; i <= vertex; i++)
	{
		visited[i] = -1;
	}
	int* answer = (int*)malloc(vertex * sizeof(int));
	int count = 0;
	Queue queue;
	init(&queue);
	visited[start] = 0;
	push(&queue, start);
	while (!EMPTY(&queue))
	{
		int current = pop(&queue);
		if (visited[current] == limit)
		{
			answer[count++] = current;
			continue;
		}
		Node* temp = graph[current];
		while (temp)
		{
			int nxt = temp->vertex;
			if (visited[nxt] == -1)
			{
				visited[nxt] = visited[current] + 1;
				push(&queue, nxt);
			}
			temp = temp->link;
		}
	}
	free(visited);
	if (count > 0)
	{
		qsort(answer, count, sizeof(int), cmp);
	}
	*len = count;
	return answer;
}

int main(void) // https://www.acmicpc.net/problem/18352
{
	int vertex = 0, edge = 0, dist = 0, start = 0;
	scanf("%d %d %d %d", &vertex, &edge, &dist, &start);
	Node** graph = (Node**)malloc((vertex + 1) * sizeof(Node*));
	for (int i = 0; i <= vertex; i++)
	{
		graph[i] = NULL;
	}
	for (int i = 0; i < edge; i++)
	{
		int v1 = 0, v2 = 0;
		scanf("%d %d", &v1, &v2);
		add_edge(graph, v1, v2);
	}
	int len = 0;
	int* ans = bfs(vertex, dist, start, graph, &len);
	if (len == 0)
	{
		printf("-1");
	}
	else
	{
		for (int i = 0; i < len; i++)
		{
			printf("%d\n", ans[i]);
		}
	}
	for (int i = 0; i <= vertex; i++)
	{
		Node* current = graph[i];
		while (current)
		{
			Node* temp = current;
			current = current->link;
			free(temp);
		}
	}
	free(graph);
	free(ans);
	return 0;
}
