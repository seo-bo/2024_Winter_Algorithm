#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef long long ll;
typedef enum { RED, BLACK } Color;

typedef struct Node
{
	char* key;
	ll value;
	Color color;
	struct Node* left;
	struct Node* right;
	struct Node* parent;
} Node;

typedef struct RBTree
{
	Node* root;
	Node* NIL;
} RBTree;

Node* create(RBTree* tree, const char* key, ll value)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	if (!newnode)
	{
		exit(EXIT_FAILURE);
	}
	newnode->key = strdup(key);
	if (!newnode->key)
	{
		free(newnode);
		exit(EXIT_FAILURE);
	}
	newnode->value = value;
	newnode->color = RED;
	newnode->left = newnode->right = newnode->parent = tree->NIL;
	return newnode;
}

RBTree* init()
{
	RBTree* tree = (RBTree*)malloc(sizeof(RBTree));
	if (!tree)
	{
		exit(EXIT_FAILURE);
	}
	tree->NIL = (Node*)malloc(sizeof(Node));
	if (!tree->NIL)
	{
		free(tree);
		exit(EXIT_FAILURE);
	}
	tree->NIL->color = BLACK;
	tree->NIL->left = tree->NIL->right = tree->NIL->parent = tree->root = tree->NIL;
	tree->NIL->key = NULL;
	tree->NIL->value = 0;
	return tree;
}

Node* mini(RBTree* tree, Node* x)
{
	while (x->left != tree->NIL)
	{
		x = x->left;
	}
	return x;
}

void rotate_left(RBTree* tree, Node* x)
{
	Node* y = x->right;
	x->right = y->left;
	if (y->left != tree->NIL)
	{
		y->left->parent = x;
	}
	y->parent = x->parent;
	if (x->parent == tree->NIL)
	{
		tree->root = y;
	}
	else if (x == x->parent->left)
	{
		x->parent->left = y;
	}
	else
	{
		x->parent->right = y;
	}
	y->left = x;
	x->parent = y;
}

void rotate_right(RBTree* tree, Node* y)
{
	Node* x = y->left;
	y->left = x->right;
	if (x->right != tree->NIL)
	{
		x->right->parent = y;
	}
	x->parent = y->parent;
	if (y->parent == tree->NIL)
	{
		tree->root = x;
	}
	else if (y == y->parent->left)
	{
		y->parent->left = x;
	}
	else
	{
		y->parent->right = x;
	}
	x->right = y;
	y->parent = x;
}

void insertfix(RBTree* tree, Node* z)
{
	while (z->parent->color == RED)
	{
		if (z->parent == z->parent->parent->left)
		{
			Node* y = z->parent->parent->right;
			if (y->color == RED)
			{
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}
			else
			{
				if (z == z->parent->right)
				{
					z = z->parent;
					rotate_left(tree, z);
				}
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				rotate_right(tree, z->parent->parent);
			}
		}
		else
		{
			Node* y = z->parent->parent->left;
			if (y->color == RED)
			{
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}
			else
			{
				if (z == z->parent->left)
				{
					z = z->parent;
					rotate_right(tree, z);
				}
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				rotate_left(tree, z->parent->parent);
			}
		}
	}
	tree->root->color = BLACK;
}

Node* insert_helper(RBTree* tree, Node* root, Node* z)
{
	if (root == tree->NIL)
	{
		return z;
	}
	int cmp = strcmp(z->key, root->key);
	if (cmp < 0)
	{
		Node* inst = insert_helper(tree, root->left, z);
		if (inst)
		{
			root->left = inst;
			inst->parent = root;
		}
	}
	else if (cmp > 0)
	{
		Node* inst = insert_helper(tree, root->right, z);
		if (inst)
		{
			root->right = inst;
			inst->parent = root;
		}
	}
	else
	{
		root->value += z->value;
		free(z->key);
		free(z);
		return NULL;
	}
	return root;
}

void insert(RBTree* tree, const char* key, ll value)
{
	Node* z = create(tree, key, value);
	Node* newnode = insert_helper(tree, tree->root, z);
	if (newnode != NULL)
	{
		tree->root = newnode;
		insertfix(tree, z);
	}
}

Node* search_helper(RBTree* tree, Node* root, const char* key)
{
	if (root == tree->NIL || strcmp(key, root->key) == 0)
	{
		return (root == tree->NIL) ? NULL : root;
	}
	if (strcmp(key, root->key) < 0)
	{
		return search_helper(tree, root->left, key);
	}
	else
	{
		return search_helper(tree, root->right, key);
	}
}

Node* search(RBTree* tree, const char* key)
{
	return search_helper(tree, tree->root, key);
}

void delfix(RBTree* tree, Node* x)
{
	while (x != tree->root && x->color == BLACK)
	{
		if (x == x->parent->left)
		{
			Node* w = x->parent->right;
			if (w->color == RED)
			{
				w->color = BLACK;
				x->parent->color = RED;
				rotate_left(tree, x->parent);
				w = x->parent->right;
			}
			if (w->left->color == BLACK && w->right->color == BLACK)
			{
				w->color = RED;
				x = x->parent;
			}
			else
			{
				if (w->right->color == BLACK)
				{
					w->left->color = BLACK;
					w->color = RED;
					rotate_right(tree, w);
					w = x->parent->right;
				}
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->right->color = BLACK;
				rotate_left(tree, x->parent);
				x = tree->root;
			}
		}
		else
		{
			Node* w = x->parent->left;
			if (w->color == RED)
			{
				w->color = BLACK;
				x->parent->color = RED;
				rotate_right(tree, x->parent);
				w = x->parent->left;
			}
			if (w->right->color == BLACK && w->left->color == BLACK)
			{
				w->color = RED;
				x = x->parent;
			}
			else
			{
				if (w->left->color == BLACK)
				{
					w->right->color = BLACK;
					w->color = RED;
					rotate_left(tree, w);
					w = x->parent->left;
				}
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->left->color = BLACK;
				rotate_right(tree, x->parent);
				x = tree->root;
			}
		}
	}
	x->color = BLACK;
}

void del(RBTree* tree, const char* key)
{
	Node* z = search(tree, key);
	if (z == NULL) return;
	Node* y = z;
	Node* x = NULL;
	Color origin = y->color;
	if (z->left == tree->NIL)
	{
		x = z->right;
		if (z->parent == tree->NIL)
		{
			tree->root = x;
		}
		else if (z == z->parent->left)
		{
			z->parent->left = x;
		}
		else
		{
			z->parent->right = x;
		}
		x->parent = z->parent;
	}
	else if (z->right == tree->NIL)
	{
		x = z->left;
		if (z->parent == tree->NIL)
		{
			tree->root = x;
		}
		else if (z == z->parent->left)
		{
			z->parent->left = x;
		}
		else
		{
			z->parent->right = x;
		}
		x->parent = z->parent;
	}
	else
	{
		y = mini(tree, z->right);
		origin = y->color;
		x = y->right;
		if (y->parent == z)
		{
			x->parent = y;
		}
		else
		{
			if (y->parent != tree->NIL)
			{
				if (y == y->parent->left)
				{
					y->parent->left = x;
				}
				else
				{
					y->parent->right = x;
				}
			}
			x->parent = y->parent;
			y->right = z->right;
			y->right->parent = y;
		}
		if (z->parent == tree->NIL)
		{
			tree->root = y;
		}
		else if (z == z->parent->left)
		{
			z->parent->left = y;
		}
		else
		{
			z->parent->right = y;
		}
		y->parent = z->parent;
		y->left = z->left;
		y->left->parent = y;
		y->color = z->color;
	}
	free(z->key);
	free(z);
	if (origin == BLACK)
	{
		delfix(tree, x);
	}
}

Node* lower_bound(RBTree* tree, const char* key)
{
	Node* cur = tree->root;
	Node* ans = NULL;
	while (cur != tree->NIL)
	{
		int cmp = strcmp(cur->key, key);
		if (cmp >= 0)
		{
			ans = cur;
			cur = cur->left;
		}
		else
		{
			cur = cur->right;
		}
	}
	return ans;
}

Node* upper_bound(RBTree* tree, const char* key)
{
	Node* cur = tree->root;
	Node* ans = NULL;
	while (cur != tree->NIL)
	{
		int cmp = strcmp(cur->key, key);
		if (cmp > 0)
		{
			ans = cur;
			cur = cur->left;
		}
		else
		{
			cur = cur->right;
		}
	}
	return ans;
}

void inorder_helper(RBTree* tree, Node* node)
{
	if (node != tree->NIL)
	{
		inorder_helper(tree, node->left);
		printf("%s %lld\n", node->key, node->value);
		inorder_helper(tree, node->right);
	}
}

void inorder(RBTree* tree)
{
	inorder_helper(tree, tree->root);
}

void destroy_helper(RBTree* tree, Node* node)
{
	if (node != tree->NIL)
	{
		destroy_helper(tree, node->left);
		destroy_helper(tree, node->right);
		free(node->key);
		free(node);
	}
}

void destroy(RBTree* tree)
{
	destroy_helper(tree, tree->root);
	free(tree->NIL);
	free(tree);
}

typedef struct Stack
{
	Node* node;
	int done;
} Stack;

char buf[1024] = { 0, };
int head = -1;

int main(void) // https://www.acmicpc.net/problem/1269
{
	int n = 0, m = 0;
	scanf("%d %d", &n, &m);
	RBTree* tree = init();
	for (int i = 0; i < n; ++i)
	{
		ll temp = 0;
		scanf("%lld", &temp);
		sprintf(buf, "%lld", temp);
		insert(tree, buf, 1);
	}
	for (int i = 0; i < m; i++)
	{
		ll temp = 0;
		scanf("%lld", &temp);
		sprintf(buf, "%lld", temp);
		insert(tree, buf, 2);
	}
	ll cnt = 0;
	Stack* stack = (Stack*)malloc(sizeof(Stack) * (n + m + 1));
	Node* cur = tree->root;
	while (1)
	{
		while (cur != tree->NIL)
		{
			stack[++head].node = cur;
			stack[head].done = 0;
			cur = cur->left;
		}
		if (head < 0)
		{
			break;
		}
		Stack st = stack[head--];
		if (!st.done)
		{
			cur = st.node;
			if (cur->value == 1 || cur->value == 2)
			{
				cnt++;
			}
			cur = cur->right;
		}
	}
	printf("%lld\n", cnt);
	free(stack);
	destroy(tree);
	return 0;
}