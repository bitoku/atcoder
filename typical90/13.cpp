#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

struct Path {
    int from;
    int to;
    ll c;
};

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<Path>> v(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--; b--;
        v[a].push_back({a, b, c});
        v[b].push_back({b, a, c});
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.push(make_pair(0, 0));
    vector<ll> dist1(n, -1);
    while (!pq.empty()) {
        auto [cost, cur] = pq.top(); pq.pop();
        if (dist1[cur] != -1) continue;
        dist1[cur] = cost;
        for (auto e: v[cur]) {
            if (dist1[e.to] != -1) continue;
            pq.push(make_pair(cost + e.c, e.to));
        }
    }
    pq.push(make_pair(0, n-1));
    vector<ll> distn(n, -1);
    while (!pq.empty()) {
        auto [cost, cur] = pq.top(); pq.pop();
        if (distn[cur] != -1) continue;
        distn[cur] = cost;
        for (auto e: v[cur]) {
            if (distn[e.to] != -1) continue;
            pq.push(make_pair(cost + e.c, e.to));
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << dist1[i] + distn[i] << endl;
    }
}