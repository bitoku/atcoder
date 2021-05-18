#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

ll rev(ll x) {
    ll ret = 0;
    while (x > 0) {
        ret = ret * 10 + x % 10;
        x /= 10;
    }
    return ret;
}

vector<vector<int>> dp(1000, vector<int>(1000, -1));

int ope(ll x, ll y) {
    if (x == 0 || y == 0) return 0;
    if (dp[x][y] == 2) return 1;
    if (dp[x][y] == 1) return 1;
    if (dp[x][y] == 0) return 0;
    dp[x][y] = 2;
    ll xx = x, yy = y;
    if (x < y) {
        x = rev(x);
    } else {
        y = rev(y);
    }
    if (x < y) {
        y = y - x;
    } else {
        x = x - y;
    }
//    cout << "    " << x << ' ' << y << endl;
    dp[xx][yy] = ope(x, y);
    return dp[xx][yy];
}

int main() {
    ll n, m;
    cin >> n >> m;
    ll result = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
//            cout << i << ' ' << j << endl;
            if (ope(i, j) == 1) {
                result++;
            }
//            cout << dp[i][j] << endl;
        }
    }
    cout << result << endl;
}