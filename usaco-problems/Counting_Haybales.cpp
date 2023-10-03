//#include "pch.h"  // remove when submitting to USACO
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

typedef pair <pair <int, int>, bool> ppiib;
int N, Q, arr[100001];
// pair <int, bool> is to see if the index is a haybale or not

int binSearch(int low, int high)
{
	if (arr[0] > high || arr[N - 1] < low)
		return 0;
	int st = 0, en = N - 1;
	for (; st != en;)
	{
		int mid = (st + en + 1) / 2;
		if (arr[mid] <= low)
			st = mid;
		else
			en = mid - 1;
	}
	int _1 = st + 1;
	if (arr[0] > low)
		_1 = 0;
	st = 0, en = N - 1;
	for (; st != en;)
	{
		int mid = (st + en + 1) / 2;
		if (arr[mid] <= high)
			st = mid;
		else
			en = mid - 1;
	}
	int _2 = st + 1;
	//cout << _1 << ' ' << _2 << endl;
	return _2 - _1;
}

int main()
{
	freopen("haybales.in", "r", stdin);
	freopen("haybales.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> Q;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	sort(arr, arr + N);
	queue <int> ans;
	for (int i = 0; i < Q; ++i)
	{
		int n1, n2;
		cin >> n1 >> n2;
		int n3 = binSearch(n1 - 1, n2);
		ans.push(n3);
	}

	while (!ans.empty())
	{
		cout << ans.front() << endl;
		ans.pop();
	}

	return 0;
}
