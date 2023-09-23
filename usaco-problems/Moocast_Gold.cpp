#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <queue>
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

int N, adjMat[1000][1000], arr[1000][2];
bool seen[1000];
int manhatDist(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2);
}
bool works(ll r) {
	bool seen[1000];
	for (int i = 0; i < N; ++i)
		seen[i] = false;
	queue <int> q;
	q.push(0);
	while (!q.empty()) {
		int cur = q.front();
		//cout << "cur " << cur << endl;
		q.pop();
		if (seen[cur])
			continue;
		seen[cur] = true;
		for (int i = 0; i < N; ++i) {
			if (i == cur)
				continue;
			if (manhatDist(arr[cur][0], arr[cur][1], arr[i][0], arr[i][1]) <= r)
				q.push(i);
			//cout << "mDist " << manhatDist(arr[cur][0], arr[cur][1], arr[i][0], arr[i][1]) << endl;
		}
	}
	bool ans = true;
	for (int i = 0; i < N; ++i)
		ans &= seen[i];
	return ans;
}

int main() {
	ifstream cin("moocast.in");
	freopen("moocast.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i][0] >> arr[i][1];
	}
	ll st = 0, en = pow(25000, 2) * 2;
	while (st != en) {
		//cout << st << ' ' << en << endl;
		ll mid = (st + en) / 2;
		if (works(mid)) {
			en = mid;
		}
		else {
			st = mid + 1;
		}
		//cout << works(mid) << endl;
	}

	cout << st << endl;

	return 0;
}