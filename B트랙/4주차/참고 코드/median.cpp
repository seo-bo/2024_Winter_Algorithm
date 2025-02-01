#include <bits/stdc++.h>
using namespace std;

void balance(priority_queue<int>& max_heap, priority_queue<int, vector<int>, greater<int>>& min_heap)
{
	if (max_heap.empty() && min_heap.empty())
	{
		return;
	}
	if (!min_heap.empty() && max_heap.top() > min_heap.top())
	{
		int mini = min_heap.top();
		min_heap.pop();
		int maxi = max_heap.top();
		max_heap.pop();
		min_heap.push(maxi);
		max_heap.push(mini);
	}
	if (max_heap.size() > min_heap.size() + 1)
	{
		min_heap.push(max_heap.top());
		max_heap.pop();
	}
}

int main(void) // https://www.acmicpc.net/problem/1655
{
	cin.tie(0)->sync_with_stdio(0);
	priority_queue<int>max_heap;
	priority_queue<int, vector<int>, greater<int>>min_heap;
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		cin >> a;
		max_heap.push(a);
		balance(max_heap, min_heap);
		cout << max_heap.top() << '\n';
	}
	return 0;
}