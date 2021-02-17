#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

struct Edge {
    int to;
    int cost;
};

int main() {
    int n, m;
    cin >> n >> m;
    int s, t;
    cin >> s >> t;
    vector<vector<Edge>> cities(n+1);
    for (int i = 0; i < m; ++i) {
        int x, y, d;
        cin >> x >> y >> d;
        cities[x].push_back(Edge {y, d});
        cities[y].push_back(Edge {x, d});
    }
    vector<ll> dists(n+1, -1);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.push(make_pair(0ll, s));
    while (!pq.empty()) {
        auto x = pq.top(); pq.pop();
        ll cost = x.first;
        int current = x.second;
        if (dists[current] != -1) continue;
        dists[current] = cost;
        for (const auto & edge : cities[current]) {
            if (dists[edge.to] != -1 && cost + edge.cost > dists[edge.to]) continue;
            pq.push(make_pair(cost + edge.cost, edge.to));
        }
    }
    vector<ll> distt(n+1, -1);
    pq.push(make_pair(0ll, t));
    while (!pq.empty()) {
        auto x = pq.top(); pq.pop();
        ll cost = x.first;
        int current = x.second;
        if (distt[current] != -1) continue;
        distt[current] = cost;
        for (const auto & edge : cities[current]) {
            if (distt[edge.to] != -1 && cost + edge.cost > distt[edge.to]) continue;
            pq.push(make_pair(cost + edge.cost, edge.to));
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (dists[i] != -1 && distt[i] != -1 && dists[i] == distt[i]) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
