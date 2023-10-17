#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

int n, m;
// first stores the node value
// second stores the distance
vector <vector <pii>> adjList;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    adjList.resize(n);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        //--a;
        //--b;
        adjList[a].pb(mp(b, c));
        adjList[b].pb(mp(a, c));
    }

    int dis[n];
    for (int i = 1; i < n; ++i)
        dis[i] = INT32_MAX;
    dis[0] = 0;
    // first is to store total distance approaching
    // second is to store the destined node
    priority_queue <pii, vector <pii>, greater <pii>> pq;
    pq.push(mp(0, 0));
    while (!pq.empty()) {
        pii cur = pq.top();
        pq.pop();
        for (pii p : adjList[cur.second]) {
            if (cur.first + p.second < dis[p.first]) {
                pq.push(mp(p.second + cur.first, p.first));
                dis[p.first] = p.second + cur.first;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << "Distance from " << 1 << " to " << i + 1 << " is " << dis[i] << endl;
    }

    return 0;
}