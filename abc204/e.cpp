#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: solve without editorial˚

struct Edge {
    ll to;
    ll c;
    ll d;
};

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<Edge>> edges(n);
    for (int i = 0; i < m; ++i) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; b--;
        edges[a].push_back({b, c, d});
        edges[b].push_back({a, c, d});
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
    vector<ll> dist(n, -1);
    pq.push(make_pair(0, 0));
    while (!pq.empty()) {
        auto [c, x] = pq.top(); pq.pop();
        if (dist[x] != -1) continue;
        dist[x] = c;
        if (x == n-1) break;
        for (auto& e: edges[x]) {
            if (dist[e.to] != -1) continue;
            ll fast = round(sqrt(e.d)) - 1;
            if (c < fast) {
                pq.push(make_pair(fast + e.c + e.d / (fast + 1), e.to));
            } else {
                pq.push(make_pair(c + e.c + e.d / (c + 1), e.to));
            }
        }
    }
    cout << dist.back() << endl;
}