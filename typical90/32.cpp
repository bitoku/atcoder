#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    ll m;
    cin >> m;
    vector<vector<bool>> b(n, vector<bool>(n));
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        b[x][y] = true;
        b[y][x] = true;
    }
    vector<int> player(n);
    iota(player.begin(), player.end(), 0);
    ll result = LONG_LONG_MAX;
    do {
        bool ng = false;
        for (int i = 0; i < n - 1; ++i) {
            ng |= b[player[i]][player[i+1]];
        }
        if (ng) continue;
        ll temp = 0;
        for (int i = 0; i < n; ++i) {
            temp += a[player[i]][i];
        }
        result = min(temp, result);
    } while (next_permutation(player.begin(), player.end()));
    if (result == LONG_LONG_MAX) cout << -1 << endl;
    else cout << result << endl;
}