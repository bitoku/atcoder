#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

struct train {
    int t;
    int k;
    int to;
};

int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<vector<train>> cities(n+1);
    for (int i = 0; i < m; ++i) {
        int a, b, t, k;
        cin >> a >> b >> t >> k;
        cities[a].push_back(train {t, k, b});
        cities[b].push_back(train {t, k, a});
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.push(make_pair(0, x));
    vector<ll> dist(n+1, -1);
    while (!pq.empty()) {
        auto cost_city = pq.top(); pq.pop();
        ll cost = cost_city.first;
        int current = cost_city.second;
        if (dist[current] != -1) continue;
        dist[current] = cost;
        if (current == y) {
            break;
        }
        for (const auto& tr: cities[current]) {
            ll next_time;
            if (cost % tr.k == 0) next_time = cost + tr.t;
            else next_time = cost + (tr.k - cost % tr.k) + tr.t;
            if (dist[tr.to] != -1 && next_time > dist[tr.to]) continue;
            pq.push(make_pair(next_time, tr.to));
        }
    }
    cout << dist[y] << endl;
}
