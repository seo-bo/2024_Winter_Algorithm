#define _CRT_SECURE_NO_WARNINGS
#define SIZE 150
#include <stdio.h>
#include <string.h>

void push(char* stack, int* ptr, char c)
{
	stack[++(*ptr)] = c;
}

char pop(char* stack, int* ptr)
{
	return stack[(*ptr)--];
}

int empty(int ptr)
{
	return ptr == -1;
}

int main(void) https://www.acmicpc.net/problem/1918
{
	char base[SIZE] = { 0, };
	scanf("%s", base);
	char oper[SIZE] = { 0, }, result[SIZE] = { 0, };
	int oper_ptr = -1, result_ptr = -1;
	int len = strlen(base);
	for (int i = 0; i < len; ++i)
	{
		if ('A' <= base[i] && base[i] <= 'Z')
		{
			push(result, &result_ptr, base[i]);
			continue;
		}
		else if (base[i] == '+' || base[i] == '-')
		{
			while (!empty(oper_ptr) && oper[oper_ptr] != '(')
			{
				push(result, &result_ptr, pop(oper, &oper_ptr));
			}
		}
		else if (base[i] == '*' || base[i] == '/')
		{
			while (!empty(oper_ptr) && (oper[oper_ptr] == '*' || oper[oper_ptr] == '/'))
			{
				push(result, &result_ptr, pop(oper, &oper_ptr));
			}
		}
		else if (base[i] == ')')
		{
			while (oper[oper_ptr] != '(')
			{
				push(result, &result_ptr, pop(oper, &oper_ptr));
			}
			pop(oper, &oper_ptr);
			continue;
		}
		push(oper, &oper_ptr, base[i]);
	}
	while (!empty(oper_ptr))
	{
		push(result, &result_ptr, pop(oper, &oper_ptr));
	}
	for (int i = 0; i <= result_ptr; ++i)
	{
		printf("%c", result[i]);
	}
}
