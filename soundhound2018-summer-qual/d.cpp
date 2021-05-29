#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

struct Edge {
    int from;
    int to;
    ll yen;
    ll snuke;
};

int main() {
    ll n, m, s, t;
    cin >> n >> m >> s >> t;
    s--; t--;
    vector<vector<Edge>> edges(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll a, b;
        cin >> u >> v >> a >> b;
        u--; v--;
        edges[u].push_back({u, v, a, b});
        edges[v].push_back({v, u, a, b});
    }
    deque<ll> cost_yen(n, -1);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.push(make_pair(0, s));
    while (!pq.empty()) {
        auto [cost, cur] = pq.top(); pq.pop();
        if (cost_yen[cur] != -1) continue;
        cost_yen[cur] = cost;
        for (auto e: edges[cur]) {
            if (cost_yen[e.to] != -1) continue;
            pq.push(make_pair(cost + e.yen, e.to));
        }
    }
    deque<ll> cost_snuke(n, -1);
    pq.push(make_pair(0, t));
    while (!pq.empty()) {
        auto [cost, cur] = pq.top(); pq.pop();
        if (cost_snuke[cur] != -1) continue;
        cost_snuke[cur] = cost;
        for (auto e: edges[cur]) {
            if (cost_snuke[e.to] != -1) continue;
            pq.push(make_pair(cost + e.snuke, e.to));
        }
    }
    set<pair<ll, int>> cost;
    for (int i = 0; i < n; ++i) {
        cost.insert(make_pair(cost_yen[i] + cost_snuke[i], i));
    }
    for (int i = 0; i < n; ++i) {
        while (cost.begin()->second < i) {
            cost.erase(cost.begin());
        }
        cout << 1000000000000000ll - cost.begin()->first << endl;
    }
}