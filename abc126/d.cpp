#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

struct edge {
    ll w;
    int to;
};

int main() {
    int n;
    cin >> n;
    vector<vector<edge>> tree(n);
    vector<int> color(n, -1);
    for (int i = 0; i < n-1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        tree[u].push_back(edge{w, v});
        tree[v].push_back(edge{w, u});
    }
    deque<pair<int, ll>> q;
    color[0] = 0;
    q.emplace_back(0, 0ll);
    while (!q.empty()) {
        auto x = q.front(); q.pop_front();
        int cur = x.first;
        ll cost = x.second;
        if (cost % 2 == 0) {
            color[cur] = 0;
        } else {
            color[cur] = 1;
        }
        for (const auto & e : tree[cur]) {
            if (color[e.to] != -1) continue;
            q.emplace_back(e.to, cost + e.w);
        }
    }
    for (const auto c : color) {
        cout << c << endl;
    }
}
