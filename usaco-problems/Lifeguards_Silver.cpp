//#include "pch.h"  // remove when submitting to USACO
#include <iostream>
#include <fstream>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <int, bool> pib;

int N;
vector <pair <pii, bool>> arr;  // first is to store pos and ind, second determines which type of point it is
int solo[100000];

int main() {
    ios_base::sync_with_stdio(0);
	ifstream cin("lifeguards.in");
	freopen("lifeguards.out", "w", stdout);
    cin >> N;
    for (int i = 0; i < N; ++i) {
		int a, b;
		cin >> a >> b;
        arr.pb(mp(mp(a, i), true));
        arr.pb(mp(mp(b, i), false));
    }
    
	sort(arr.begin(), arr.end());
	int ans = 0, tot = 0, onDuty = 0, prev = arr[0].first.first;
	// finds the area
	for (int i = 0; i < arr.size(); ++i) {
		if (onDuty > 0) {
			tot += arr[i].first.first - prev;
		}
		if (arr[i].second) {
			++onDuty;
		}
		else {
			--onDuty;
		}
		prev = arr[i].first.first;
	}
	// loops thru each cow and finds the amount of time in which it is alone
	int active = 0;
	prev = 0;
	set <int> hashSet;  // first is arr ind, second is actual ind.
	for (int i = 0; i < N * 2; ++i) {
		if (active == 1) {
			int cur = *hashSet.begin();
			solo[cur] += arr[i].first.first - arr[i - 1].first.first;
		}
		if (arr[i].second) {
			++active;
			hashSet.insert(arr[i].first.second);
		}
		else {
			--active;
			hashSet.erase(hashSet.find(arr[i].first.second));
		}
		prev = i;
	}
	for (int i = 0; i < N; ++i) {
		ans = max(ans, tot - solo[i]);
	}
    
    cout << ans << endl;
    
    return 0;
}