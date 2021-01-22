#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> dp(n, 2000000007);
    map<int, set<int>> route;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        route[x-1].insert(y-1);
    }
    for (int i = 0; i < n; ++i) {
        for (const auto p: route[i]) {
            dp[p] = min({dp[p], dp[i], a[i]});
        }
    }
    int result = -2000000007;
    for (int i = 0; i < n; ++i) {
        result = max(result, a[i] - dp[i]);
    }
    cout << result << endl;
}