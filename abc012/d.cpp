#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> dist(n, vector<ll>(n, -1));
    for (int i = 0; i < m; ++i) {
        int a, b;
        ll t;
        cin >> a >> b >> t;
        a--; b--;
        dist[a][b] = t;
        dist[b][a] = t;
    }
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] == -1 || dist[k][j] == -1) continue;
                if (dist[i][j] == -1 || dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    ll result = LONG_LONG_MAX;
    for (int i = 0; i < n; ++i) {
        ll temp = 0;
        for (int j = 0; j < n; ++j) {
            temp = max(temp, dist[i][j]);
        }
        result = min(result, temp);
    }
    cout << result << endl;
}