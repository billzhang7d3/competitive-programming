#include <iostream>
#include <string>
#include <vector>
using namespace std;

int editDistance(string s1, string s2, vector <vector <int>>& dp, int row, int col);

int main(int argc, char **argv) {
    if (argc != 3) {
        cout << "edit-distance [source] [destination]\n";
        return 0;
    }
    string s1 = argv[1], s2 = argv[2];
    vector <vector <int>> dp(s1.size() + 1);
    for (int i = 0; i <= s1.size(); ++i) { dp[i].resize(s2.size() + 1); }
    for (int i = 0; i < s1.size(); ++i) {
        for (int j = 0; j < s2.size(); ++j) {
            dp[i][j] = -1;
        }
    }
    dp[s1.size()][s2.size()] = 0;
    for (int i = 0; i < s2.size(); ++i) { dp[s1.size()][i] = s2.size() - i; }
    for (int i = 0; i < s1.size(); ++i) { dp[i][s2.size()] = s1.size() - i; }

    int ans = editDistance(s1, s2, dp, 0, 0);
    cout << ans << endl;

    return 0;
}

int editDistance(string s1, string s2, vector <vector <int>>& dp, int row, int col) {
    if (row == s1.size() || col == s2.size()) { return dp[row][col]; }
    if (dp[row][col] == -1) {
        if (s1[row] == s2[col]) {
            dp[row][col] = editDistance(s1, s2, dp, row + 1, col + 1);
        } else {
            dp[row][col] = min(
                min(
                    editDistance(s1, s2, dp, row + 1, col + 1) + 1, 
                    editDistance(s1, s2, dp, row + 1, col) + 1
                ),
                editDistance(s1, s2, dp, row, col + 1) + 1
            );
        }
    }
    return dp[row][col];
}