#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: 08/30

struct Edge {
    int from;
    int to;
    ll c;
};

int main() {
    ll n, m, p;
    cin >> n >> m >> p;
    vector<Edge> edges;
    for (int i = 0; i < m; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--; b--;
        edges.push_back({a, b, c-p});
    }
    vector<ll> dist(n, LONG_LONG_MIN);
    dist[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (auto& e: edges) {
            if (dist[e.from] == LONG_LONG_MIN) continue;
            if (dist[e.to] == LONG_LONG_MIN || dist[e.to] < dist[e.from] + e.c) {
                dist[e.to] = dist[e.from] + e.c;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (auto& e: edges) {
            if (dist[e.from] == LONG_LONG_MIN) continue;
            if (dist[e.to] == LONG_LONG_MIN || dist[e.from] == LONG_LONG_MAX || dist[e.to] < dist[e.from] + e.c) {
                dist[e.to] = LONG_LONG_MAX;
            }
        }
    }
    if (dist[n-1] == LONG_LONG_MAX) cout << -1 << endl;
    else cout << max(0ll, dist[n-1]) << endl;
}