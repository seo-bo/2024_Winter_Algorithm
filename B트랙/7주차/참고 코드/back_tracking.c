#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void dfs(int* visited, int* ary, int depth, int num, int limit)
{
	if (depth == limit)
	{
		for (int i = 0; i < depth; ++i)
		{
			printf("%d ", ary[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 1; i <= num; ++i)
	{
		if (visited[i])
		{
			continue;
		}
		visited[i] = 1;
		ary[depth] = i;
		dfs(visited, ary, depth + 1, num, limit);
		ary[depth] = 0;
		visited[i] = 0;
	}
}

int main(void) // https://www.acmicpc.net/problem/15649
{
	int n = 0, m = 0;
	scanf("%d %d", &n, &m);
	int* visited = (int*)calloc(n + 1, sizeof(int));
	int* ary = (int*)calloc(m + 1, sizeof(int));
	dfs(visited, ary, 0, n, m);
	free(visited);
	free(ary);
	return 0;
}