#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#define SIZE 1000003
#define FACTOR 0.7
typedef unsigned long long ull;
typedef long long ll;

typedef enum { EMPTY, OCCUPIED, DELETED } state;

typedef struct Entry
{
	char* key;
	char* value;
	state state;
} Entry;

typedef struct HashTable
{
	Entry* table;
	ll size, cnt;
} HashTable;

ull mulmod(ull a, ull b, ull mod)
{
	ull res = 0;
	a %= mod;
	b %= mod;
	while (b > 0)
	{
		if (b & 1)
		{
			res = (res + a) % mod;
		}
		a = (a * 2) % mod;
		b >>= 1;
	}
	return res;
}

ull power(ull base, ull exp, ull mod)
{
	if (mod == 1)
	{
		return 0;
	}
	ull result = 1;
	base = base % mod;
	while (exp > 0)
	{
		if (exp & 1)
		{
			result = mulmod(result, base, mod);
		}
		base = mulmod(base, base, mod);
		exp >>= 1;
	}
	return result;
}

bool miller_rabin(ull n, ll iter)
{
	if (n < 2)
	{
		return false;
	}
	if (n == 2 || n == 3)
	{
		return true;
	}
	if (n % 2 == 0)
	{
		return false;
	}
	ull d = n - 1;
	ll s = 0;
	while (d % 2 == 0)
	{
		d /= 2;
		s++;
	}
	for (ll i = 0; i < iter; ++i)
	{
		ull a = 2 + rand() % (n - 3);
		ull x = power(a, d, n);
		if (x == 1 || x == n - 1)
		{
			continue;
		}
		bool flag = false;
		for (ll j = 1; j < s; ++j)
		{
			x = mulmod(x, x, n);
			if (x == n - 1)
			{
				flag = true;
				break;
			}
		}
		if (flag)
		{
			continue;
		}
		return false;
	}
	return true;
}

bool isprime(ull n)
{
	ll iter = 5;
	return miller_rabin(n, iter);
}

ll nextprime(ll cur)
{
	ll next = cur + 1;
	while (!isprime(next))
	{
		next++;
	}
	return next;
}

ull hashing1(const char* key, ll size)
{
	ull hash = 5381;
	int c = 0;
	while ((c = *key++))
	{
		hash = ((hash << 5) + hash) + c;
	}
	return hash % size;
}

ull hashing2(const char* key, ll size)
{
	ull hash = 0;
	int c = 0;
	while ((c = *key++))
	{
		hash = (hash * 31 + c) % size;
	}
	return 1 + (hash % (size - 1));
}

HashTable* create(ll size)
{
	HashTable* newnode = (HashTable*)malloc(sizeof(HashTable));
	if (!newnode)
	{
		exit(EXIT_FAILURE);
	}
	newnode->size = size;
	newnode->cnt = 0;
	newnode->table = (Entry*)malloc(sizeof(Entry) * newnode->size);
	if (!newnode->table)
	{
		free(newnode);
		exit(EXIT_FAILURE);
	}
	for (ll i = 0; i < newnode->size; ++i)
	{
		newnode->table[i].state = EMPTY;
		newnode->table[i].key = newnode->table[i].value = NULL;
	}
	return newnode;
}

void destroy(HashTable* node)
{
	if (node)
	{
		for (ll i = 0; i < node->size; i++)
		{
			if (node->table[i].state != EMPTY)
			{
				if (node->table[i].key)
				{
					free(node->table[i].key);
				}
				if (node->table[i].value)
				{
					free(node->table[i].value);
				}
			}
		}
		free(node->table);
		free(node);
	}
}

void resize(HashTable* node)
{
	ll newsize = nextprime(node->size * 2);
	Entry* old = node->table;
	ll oldsize = node->size;
	node->table = (Entry*)malloc(sizeof(Entry) * newsize);
	if (!node->table)
	{
		exit(EXIT_FAILURE);
	}
	node->size = newsize;
	node->cnt = 0;
	for (ll i = 0; i < node->size; ++i)
	{
		node->table[i].state = EMPTY;
		node->table[i].key = NULL;
		node->table[i].value = NULL;
	}
	for (ll i = 0; i < oldsize; ++i)
	{
		if (old[i].state == OCCUPIED)
		{
			const char* key = old[i].key;
			const char* value = old[i].value;
			ull hash1 = hashing1(key, node->size);
			ull hash2 = hashing2(key, node->size);
			for (ll j = 0; j < node->size; ++j)
			{
				ll idx = (hash1 + j * hash2) % node->size;
				if (node->table[idx].state != OCCUPIED)
				{
					node->table[idx].key = (char*)key;
					node->table[idx].value = (char*)value;
					node->table[idx].state = OCCUPIED;
					node->cnt++;
					break;
				}
			}
		}
	}
	free(old);
}

void insert(HashTable* node, const char* key, const char* value)
{
	if ((double)(node->cnt + 1) / node->size > FACTOR)
	{
		resize(node);
	}
	ull hash1 = hashing1(key, node->size);
	ull hash2 = hashing2(key, node->size);
	ll pivot = -1;
	for (ll i = 0; i < node->size; ++i)
	{
		ll idx = (hash1 + i * hash2) % node->size;
		if (node->table[idx].state == OCCUPIED)
		{
			if (strcmp(node->table[idx].key, key) == 0)
			{
				free(node->table[idx].value);
				node->table[idx].value = strdup(value);
				return;
			}
		}
		else
		{
			if (node->table[idx].state == DELETED && pivot == -1)
			{
				pivot = idx;
			}
			if (node->table[idx].state == EMPTY)
			{
				if (pivot != -1) idx = pivot;
				node->table[idx].key = strdup(key);
				node->table[idx].value = strdup(value);
				node->table[idx].state = OCCUPIED;
				node->cnt++;
				return;
			}
		}
	}
}

char* search(HashTable* node, const char* key)
{
	ull hash1 = hashing1(key, node->size);
	ull hash2 = hashing2(key, node->size);
	for (ll i = 0; i < node->size; ++i)
	{
		ll idx = (hash1 + i * hash2) % node->size;
		if (node->table[idx].state == OCCUPIED)
		{
			if (strcmp(node->table[idx].key, key) == 0)
			{
				return node->table[idx].value;
			}
		}
		else if (node->table[idx].state == EMPTY)
		{
			break;
		}
	}
	return NULL;
}

void del(HashTable* node, const char* key)
{
	ull hash1 = hashing1(key, node->size);
	ull hash2 = hashing2(key, node->size);

	for (ll i = 0; i < node->size; ++i)
	{
		ll idx = (hash1 + i * hash2) % node->size;

		if (node->table[idx].state == OCCUPIED)
		{
			if (strcmp(node->table[idx].key, key) == 0)
			{
				free(node->table[idx].key);
				free(node->table[idx].value);
				node->table[idx].key = NULL;
				node->table[idx].value = NULL;
				node->table[idx].state = DELETED;
				node->cnt--;
				return;
			}
		}
		else if (node->table[idx].state == EMPTY)
		{
			break;
		}
	}
}

char buffer1[1024] = { 0, };
char buffer2[1024] = { 0, };

int main(void) // https://www.acmicpc.net/problem/10816
{
	ll n = 0;
	scanf("%lld", &n);
	HashTable* node = create(SIZE);
	for (ll i = 0; i < n; i++)
	{
		scanf("%s", buffer1);
		char* ex = search(node, buffer1);
		if (ex)
		{
			ll cnt = atoi(ex);
			cnt++;
			snprintf(buffer2, sizeof(buffer2), "%lld", cnt);
			insert(node, buffer1, buffer2);
		}
		else
		{
			insert(node, buffer1, "1");
		}
	}
	ll m = 0;
	scanf("%lld", &m);
	for (ll i = 0; i < m; i++)
	{
		scanf("%s", buffer1);
		char* res = search(node, buffer1);
		if (res)
		{
			printf("%s ", res);
		}
		else
		{
			printf("0 ");
		}
	}
	printf("\n");
	destroy(node);
	return 0;
}