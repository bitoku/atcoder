#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

struct Path {
    int to;
    ll cost;
};

int main() {
    int n;
    cin >> n;
    vector<vector<Path>> v(n+1);
    for (int i = 1; i <= n; ++i) {
        ll s;
        cin >> s;
        v[i].push_back({i % n + 1, s});
    }

    for (int i = 1; i <= n; ++i) {
        ll t;
        cin >> t;
        v[0].push_back({i, t});
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.push(make_pair(0, 0));
    vector<ll> result(n+1, -1);
    while (!pq.empty()) {
        auto [cost, cur] = pq.top(); pq.pop();
        if (result[cur] != -1) continue;
        result[cur] = cost;
        for (auto p: v[cur]) {
            if (result[p.to] != -1) continue;
            pq.push(make_pair(cost + p.cost, p.to));
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << result[i+1] << endl;
    }
}