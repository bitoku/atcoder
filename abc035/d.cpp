#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

struct Edge {
    int from;
    int to;
    ll c;
};

int main() {
    ll n, m, t;
    cin >> n >> m >> t;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<Edge>> edgesto(n);
    vector<vector<Edge>> edgesfrom(n);
    for (int i = 0; i < m; ++i) {
        int aa, b, c;
        cin >> aa >> b >> c;
        aa--; b--;
        edgesto[aa].push_back({aa, b, c});
        edgesfrom[b].push_back({b, aa, c});
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.push(make_pair(0, 0));
    vector<ll> distto(n, -1);
    while (!pq.empty()) {
        auto [c, x] = pq.top(); pq.pop();
        if (distto[x] != -1) continue;
        distto[x] = c;
        for (auto e: edgesto[x]) {
            if (distto[e.to] != -1) continue;
            pq.push(make_pair(c + e.c, e.to));
        }
    }
    pq.push(make_pair(0, 0));
    vector<ll> distfrom(n, -1);
    while (!pq.empty()) {
        auto [c, x] = pq.top(); pq.pop();
        if (distfrom[x] != -1) continue;
        distfrom[x] = c;
        for (auto e: edgesfrom[x]) {
            if (distfrom[e.to] != -1) continue;
            pq.push(make_pair(c + e.c, e.to));
        }
    }
    ll result = 0;
    for (int i = 0; i < n; ++i) {
        if (distto[i] == -1 || distfrom[i] == -1) continue;
        result = max(result, (t - distto[i] - distfrom[i]) * a[i]);
    }
    cout << result << endl;
}