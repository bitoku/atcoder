#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

ll dp[3001][3001][4];

int main() {
    int R, C, k;
    cin >> R >> C >> k;
    map<pair<int, int>, ll> um;
    for (int i = 0; i < k; ++i) {
        int r, c, v;
        cin >> r >> c >> v;
        um[make_pair(r, c)] = v;
    }
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            auto p = make_pair(i, j);
            ll up = max({dp[i-1][j][0], dp[i-1][j][1], dp[i-1][j][2], dp[i-1][j][3]});
            dp[i][j][0] = max(dp[i][j-1][0], up);
            dp[i][j][1] = dp[i][j-1][1];
            dp[i][j][2] = dp[i][j-1][2];
            dp[i][j][3] = dp[i][j-1][3];
            if (um.find(p) != um.end()) {
                dp[i][j][1] = max({dp[i][j][1], dp[i][j-1][0] + um[p], up + um[p]});
                dp[i][j][2] = max({dp[i][j][2], dp[i][j-1][1] + um[p]});
                dp[i][j][3] = max({dp[i][j][3], dp[i][j-1][2] + um[p]});
            }
        }
    }
    cout << max({dp[R][C][0], dp[R][C][1], dp[R][C][2], dp[R][C][3]}) << endl;
}
