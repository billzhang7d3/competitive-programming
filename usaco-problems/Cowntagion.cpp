#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;

int N, ans;
vector <vi> adjList;
int sick[100000];
bool seen[100000];
void dfs(int node) {
	seen[node] = true;
	int cnt = 1;
	for (int i : adjList[node]) {
		if (!seen[i])
			++cnt;
	}
	//cout << "cnt: " << cnt << endl;
	for (; sick[node] < cnt; sick[node] *= 2) {
		++ans;
	}
	//cout << "#: " << sick[node] << endl;
	//cout << "ans: " << ans << endl;
	for (int i : adjList[node]) {
		if (seen[i])
			continue;
		sick[i] = 1;
		dfs(i);
		++ans;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> N;
	adjList.resize(N);
	for (int i = 1; i < N; ++i) {
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		adjList[a].pb(b);
		adjList[b].pb(a);
	}

	sick[0] = 1;
	dfs(0);

	cout << ans << endl;

	return 0;
}