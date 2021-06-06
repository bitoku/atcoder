#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, m, l;
    cin >> n >> m >> l;
    vector<vector<ll>> dist(n, vector<ll>(n, LONG_LONG_MAX));
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (c > l) continue;
        a--; b--;
        dist[a][b] = c;
        dist[b][a] = c;
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] == LONG_LONG_MAX || dist[k][j] == LONG_LONG_MAX) continue;
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    vector<vector<ll>> cnt(n, vector<ll>(n, LONG_LONG_MAX));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] <= l) {
                cnt[i][j] = 1;
                cnt[j][i] = 1;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cnt[i][i] = 0;
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (cnt[i][k] == LONG_LONG_MAX || cnt[k][j] == LONG_LONG_MAX) continue;
                if (cnt[i][j] > cnt[i][k] + cnt[k][j]) {
                    cnt[i][j] = cnt[i][k] + cnt[k][j];
                }
            }
        }
    }
    ll q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int s, t;
        cin >> s >> t;
        s--; t--;
        if (cnt[s][t] == LONG_LONG_MAX) cout << -1 << endl;
        else cout << cnt[s][t] - 1 << endl;
    }
}