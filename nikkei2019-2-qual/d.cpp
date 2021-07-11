#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: 07/11

struct Edge {
    int to;
    ll c;
};

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<Edge>> g(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].push_back({b, c});
    }
    for (int i = 0; i < n-1; ++i) {
        g[i+1].push_back({i, 0});
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.push({0, 0});
    vector<ll> dist(n, -1);
    while (!pq.empty()) {
        auto [c, cur] = pq.top(); pq.pop();
        if (dist[cur] != -1) continue;
        dist[cur] = c;
        for (auto& e: g[cur]) {
            if (dist[e.to] != -1) continue;
            pq.push({c + e.c, e.to});
        }
    }
    cout << dist[n-1] << endl;
}