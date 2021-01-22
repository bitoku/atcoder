#include <bits/stdc++.h>

using namespace std;

int ctoi(char c) {
    return c - '0';
}

template<typename T>
T combi(T n, T r) {
    T ans = 1;
    for (int i = n; i > n - r; --i) {
        ans *= i;
    }
    for (int i = 1; i >= r; ++i) {
        ans /= i;
    }
    return ans;
}

int main() {
    string n;
    int k;
    cin >> n >> k;
    vector<vector<int>> dp0(n.size() + 1, vector<int>(k + 1, 0));
    vector<vector<int>> dp1(n.size() + 1, vector<int>(k + 1, 0));
    dp1[0][0] = 1;
    for (int i = 0; i < n.size(); ++i) {
        if (i != 0) dp0[i][0] = 1;
        for (int j = 0; j < k; ++j) {
            dp0[i + 1][j + 1] += dp0[i][j + 1];
            dp0[i + 1][j + 1] += dp0[i][j] * 9;
            dp0[i + 1][j + 1] += dp1[i][j] * max(ctoi(n[i]) - 1, 0);
            dp0[i + 1][j + 1] += dp1[i][j + 1] * min(ctoi(n[i]), 1);
            if (ctoi(n[i]) == 0) {
                dp1[i + 1][j + 1] = dp1[i][j + 1];
            } else {
                dp1[i + 1][j + 1] = dp1[i][j];
            }
        }
    }
    cout << dp0[n.size()][k] + dp1[n.size()][k] << endl;
}
