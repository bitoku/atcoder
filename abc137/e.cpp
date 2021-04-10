#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: solve without editorial

struct Edge {
    int from;
    int to;
    ll cost;
};

int main() {
    ll n, m, p;
    cin >> n >> m >> p;
    vector<ll> dist(n+1, LONG_LONG_MAX);
    vector<Edge> edges;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back(Edge {a, b, p - c});
    }
    dist[1] = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            auto e = edges[j];
            if (dist[e.from] == LONG_LONG_MAX) continue;
            if ((dist[e.from] + e.cost) < dist[e.to]) {
                dist[e.to] = dist[e.from] + e.cost;
            }
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            auto e = edges[j];
            if (dist[e.from] == LONG_LONG_MAX) continue;
            if (dist[e.from] == LONG_LONG_MIN || (dist[e.from] + e.cost) < dist[e.to]) {
                dist[e.to] = LONG_LONG_MIN;
            }
        }
    }
    if (dist[n] != LONG_LONG_MIN) {
         cout << max(0ll, -dist[n]) << endl;
    } else {
        cout << -1 << endl;
    }
}
