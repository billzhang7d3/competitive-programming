//#include "pch.h"  // remove when submitting to USACO
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

int N, M, arr[100000][2];
char pref[100000];
string S;
vector <vector <int>> adjList;
vector <bool> seen;
vector <int> component;

int main() {
	ios_base::sync_with_stdio(0);
	ifstream cin("milkvisits.in");
	freopen("milkvisits.out", "w", stdout);
	cin >> N >> M >> S;
	adjList.resize(N);
	for (int i = 1; i < N; ++i) {
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		adjList[a].pb(b);
		adjList[b].pb(a);
	}
	for (int i = 0; i < M; ++i) {
		cin >> arr[i][0] >> arr[i][1] >> pref[i];
		--arr[i][0];
		--arr[i][1];
	}
	
	seen.resize(N, false);
	component.resize(N, 0);
	int cnt = 1;
	for (int i = 0; i < N; ++i) {
		if (seen[i]) {
			continue;
		}
		queue <int> q;
		q.push(i);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			if (seen[cur])
				continue;
			seen[cur] = true;
			component[cur] = cnt;
			int ctr = 0;
			for (int j : adjList[cur]) {
				if (S[j] == S[i])
					q.push(j);
				++ctr;
			}
		}
		++cnt;
	}
	for (int i = 0; i < M; ++i) {
		bool same = component[arr[i][0]] == component[arr[i][1]];
		bool match = S[arr[i][0]] == pref[i];
		bool ans = (same && match) || !same;
		cout << ans;
	}
	cout << endl;

	return 0;
}