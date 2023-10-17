#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626
#define fr first
#define sc second
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

class FenwickTree {
public:
    int n;
    vi arr, intervals;
    FenwickTree(int n, int *arr) {
        this->n = n;
        this->arr.pb(0);
        for (int i = 0; i < n; ++i) { this->arr.pb(arr[i]); }
        intervals.resize(n + 1);
        for (int interval = 1; interval <= n; interval *= 2) {
            for (int i = interval; i <= n; i += interval * 2) {
                intervals[i] = interval;
            }
        }
        for (int interval = 1; interval <= n; interval *= 2) {
            for (int i = interval; i <= n; i += interval * 2) {
                int reference = arr[i - 1], ind = i;
                ind += intervals[ind];
                while (ind <= n) {
                    this->arr[ind] += reference;
                    ind += intervals[ind];
                }
            }
        }
    }
    void update(int ind, int num) {
        int diff = num - arr[ind];
        while (ind <= n) {
            arr[ind] += diff;
            ind += intervals[ind];
        }
    }
    int sum(int ind) {
        int ans = 0;
        while (ind > 0) {
            ans += arr[ind];
            ind -= ind % -ind;
        }
        return ans;
    }
    int rangeSum(int st, int en) {
        //inclusive
        return sum(en) - sum(st - 1);
    }
    void printList() {
        for (int i = 1; i <= n; ++i) { cout << arr[i] << ' '; }
        cout << endl;
    }
};

int main() {
    ifstream fin("fwt.txt");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL);
    int n;
    fin >> n;
    int *arr = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        fin >> arr[i];
    }

    FenwickTree fw(n, arr);
    for (int i = 1; i <= fw.n; ++i) { cout << fw.arr[i] << endl; }

    return 0;
}

