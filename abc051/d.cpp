#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> dist(n, vector<ll>(n, LONG_LONG_MAX / 3));
    vector<tuple<ll, ll, ll>> edges(m);
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        dist[a][b] = c;
        dist[b][a] = c;
        edges[i] = make_tuple(a, b, c);
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    ll result = 0;
    for (int k = 0; k < m; ++k) {
        bool unused = true;
        auto [a, b, c] = edges[k];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][j] == dist[i][a] + c + dist[b][j] ||
                    dist[i][j] == dist[i][b] + c + dist[a][j]) {
                    unused = false;
                    break;
                }
            }
        }
        if (unused) result++;
    }
    cout << result << endl;
}
