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
            ind += ind & -ind;
        }
    }
    int sum(int ind) {
        int ans = 0;
        while (ind > 0) {
            ans += arr[ind];
            ind -= ind & -ind;
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
    int n;
    fin >> n;
    int *arr = (int *) malloc(n * sizeof(int));
    cout << "arr elements:\n";
    for (int i = 0; i < n; ++i) {
        fin >> arr[i];
        cout << arr[i] << ' ';
    }
    cout << "\n";

    FenwickTree fw(n, arr);
    fw.printList();
    cout << "range query 6, 9: " << fw.rangeSum(6, 9) << endl;
    cout << "range query 4, 15: " << fw.rangeSum(4, 15) << endl;
    cout << "range query 1, 4: " << fw.rangeSum(1, 4) << endl;
    fw.update(7, 1000);
    fw.printList();
    cout << "range query 6, 9: " << fw.rangeSum(6, 9) << endl;
    cout << "range query 4, 15: " << fw.rangeSum(4, 15) << endl;

    free(arr);

    return 0;
}

