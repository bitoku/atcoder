#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> query(n+1);
    vector<ll> dp(1 << n);
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        y--;
        query[x].emplace_back(y, z);
    }
    dp[0] = 1;
    for (int i = 0; i < dp.size(); ++i) {
        vector<int> contain(n);
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) contain[j] = true;
        }
        vector<int> sum(n);
        sum[0] = contain[0];
        for (int j = 1; j < n; ++j) {
            sum[j] += sum[j-1] + contain[j];
        }
        int s = sum.back();
        bool ok = true;
        for (auto [y, z]: query[s]) {
            ok &= sum[y] <= z;
        }
        if (!ok) {
            dp[i] = 0;
            continue;
        }
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) continue;
            dp[i | (1 << j)] += dp[i];
        }
    }
    cout << dp[(1 << n) - 1] << endl;
}