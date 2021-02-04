#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

struct edge {
    int to;
    ll cost;
};

int main() {
    int n;
    cin >> n;
    vector<vector<edge>> tree(n);
    vector<ll> cost(n, -1);
    for (int i = 0; i < n-1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        tree[a].push_back(edge{b, c});
        tree[b].push_back(edge{a, c});
    }
    int q, k;
    cin >> q >> k;
    deque<pair<int, ll>> dq;
    dq.emplace_back(k-1, 0ll);
    while (!dq.empty()) {
        auto x = dq.front(); dq.pop_front();
        int cur = x.first;
        ll c = x.second;
        cost[cur] = c;
        for (const auto& e : tree[cur]) {
            if (cost[e.to] != -1) continue;
            dq.emplace_back(e.to, c + e.cost);
        }
    }
    for (int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        cout << cost[x] + cost[y] << endl;
    }
}
