#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int vertex;
	struct Node* link;
}Node;

void add_edge(Node** graph, int v1, int v2)
{
	Node* node1 = (Node*)malloc(sizeof(Node));
	node1->vertex = v2;
	node1->link = graph[v1];
	graph[v1] = node1;
	Node* node2 = (Node*)malloc(sizeof(Node));
	node2->vertex = v1;
	node2->link = graph[v2];
	graph[v2] = node2;
}

int dfs(int node, int limit, int distance, Node** graph, int* apple, int* visited)
{
	if (distance > limit)
	{
		return 0;
	}
	visited[node] = 1;
	int cnt = apple[node];
	Node* current = graph[node];
	while (current)
	{
		int nxt = current->vertex;
		if (!visited[nxt])
		{
			cnt += dfs(nxt, limit, distance + 1, graph, apple, visited);
		}
		current = current->link;
	}
	return cnt;
}

int main(void) // https://www.acmicpc.net/problem/25516
{
	int vertex = 0, dist = 0;
	scanf("%d %d", &vertex, &dist);
	Node** graph = (Node**)malloc(sizeof(Node*) * vertex);
	int* apple = (int*)malloc(sizeof(int) * vertex);
	int* visited = (int*)calloc(vertex, sizeof(int));
	for (int i = 0; i < vertex; ++i)
	{
		graph[i] = NULL;
	}
	for (int i = 0; i < vertex - 1; ++i)
	{
		int v1 = 0, v2 = 0;
		scanf("%d %d", &v1, &v2);
		add_edge(graph, v1, v2);
	}
	for (int i = 0; i < vertex; ++i)
	{
		scanf("%d", &apple[i]);
	}
	printf("%d", dfs(0, dist, 0, graph, apple, visited));
	for (int i = 0; i < vertex; ++i)
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
	free(apple);
	free(visited);
	return 0;
}