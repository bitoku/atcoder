#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

template<class Condition>
ld binsearch(ld ng, ld ok, Condition func) {
    while (abs(ok - ng) > 0.01) {
        ld mid = (ng + ok) / 2;
        if (func(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}

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
            pq.push(make_pair(c + e.c + e.d / (c + 1), e.to));
        }
    }
    if (dist.back() == -1) {
        cout << -1 << endl;
        return 0;
    }
    auto func = [&](ld t) {
        priority_queue<pair<ld, ll>, vector<pair<ld, ll>>, greater<>> pq;
        vector<ld> dist(n, -1);
        pq.push(make_pair(t, 0));
        while (!pq.empty()) {
            auto [c, x] = pq.top(); pq.pop();
            if (dist[x] != -1) continue;
            dist[x] = c;
            if (x == n-1) break;
            for (auto& e: edges[x]) {
                if (dist[e.to] != -1) continue;
                pq.push(make_pair(c + e.c + e.d / (c + 1), e.to));
            }
        }
        vector<ld> dist2(n, -1);
        pq.push(make_pair(t+0.1, 0));
        while (!pq.empty()) {
            auto [c, x] = pq.top(); pq.pop();
            if (dist2[x] != -1) continue;
            dist2[x] = c;
            if (x == n-1) break;
            for (auto& e: edges[x]) {
                if (dist2[e.to] != -1) continue;
                pq.push(make_pair(c + e.c + e.d / (c + 1), e.to));
            }
        }
//        cout << t << ' ' << dist.back() << ' ' << dist.back() << endl;
        return dist.back() > dist2.back();
    };
    ll t = floor(binsearch(1000000005, -1, func));
    dist.resize(n, -1);
    pq.push(make_pair(t, 0));
    while (!pq.empty()) {
        auto [c, x] = pq.top(); pq.pop();
        if (dist[x] != -1) continue;
        dist[x] = c;
        if (x == n-1) break;
        for (auto& e: edges[x]) {
            if (dist[e.to] != -1) continue;
            pq.push(make_pair(c + e.c + e.d / (c + 1), e.to));
        }
    }
    vector<ll> dist2(n, -1);
    pq.push(make_pair(t+1, 0));
    while (!pq.empty()) {
        auto [c, x] = pq.top(); pq.pop();
        if (dist2[x] != -1) continue;
        dist2[x] = c;
        if (x == n-1) break;
        for (auto& e: edges[x]) {
            if (dist2[e.to] != -1) continue;
            pq.push(make_pair(c + e.c + e.d / (c + 1), e.to));
        }
    }
    cout << min(dist.back(), dist2.back()) << endl;
}