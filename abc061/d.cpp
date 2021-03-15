#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

struct Edge {
    ll from;
    ll to;
    ll cost;
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> nodes(n+1);
    vector<vector<Edge>> rev(n+1);
    for (int i = 0; i < m; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        nodes[a].push_back({a, b, -c});
        rev[b].push_back({b, a, c});
    }
    deque<int> dq;
    dq.push_back(n);
    vector<bool> done(n+1);
    done[n] = true;
    while (!dq.empty()) {
        int cur = dq.front(); dq.pop_front();
        for (const auto& e : rev[cur]) {
            if (done[e.to]) continue;
            dq.push_back(e.to);
            done[e.to] = true;
        }
    }
    vector<ll> dist(n+1, LONG_LONG_MAX);
    dist[1] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (const auto& e : nodes[j]) {
                if (dist[e.from] == LONG_LONG_MAX) continue;
                dist[e.to] = min(dist[e.to], dist[e.from] + e.cost);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (const auto e : nodes[i]) {
            if (dist[e.from] == LONG_LONG_MAX) continue;
            if (dist[e.to] > dist[e.from] + e.cost && done[e.to]) {
                cout << "inf" << endl;
                return 0;
            }
        }
    }
    cout << -dist[n] << endl;
}
