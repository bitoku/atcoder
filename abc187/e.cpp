#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

struct Edge {
    int from;
    int to;
    ll val;
};

int main() {
    int n;
    cin >> n;
    vector<vector<ll>> tree(n);
    vector<pair<ll, ll>> edge(n-1);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
        edge[i] = {a, b};
    }
    vector<ll> depth(n, -1);
    depth[0] = 0;
    deque<pair<ll, ll>> dq;
    dq.emplace_back(0, 0);
    while (!dq.empty()) {
        auto [i, d] = dq.front(); dq.pop_front();
        for (const auto& e : tree[i]) {
            if (depth[e] != -1) continue;
            depth[e] = d+1;
            dq.emplace_back(e, d+1);
        }
    }
    int q;
    cin >> q;
    vector<ll> s(n);
    for (int i = 0; i < q; ++i) {
        ll t, e, x;
        cin >> t >> e >> x;
        auto [a, b] = edge[--e];
        if (t == 2) swap(a, b);
        if (depth[a] < depth[b]) {
            s[0] += x;
            s[b] -= x;
        } else {
            s[a] += x;
        }
    }
    vector<ll> v;
    v.push_back(0);
    while (!v.empty()) {
        ll i = v.back();
        v.pop_back();
        for (ll j : tree[i]) {
            if (depth[i] < depth[j]) {
                s[j] += s[i];
                v.push_back(j);
            }
        }
    }
    for (auto x : s) {
        cout << x << endl;
    }
}

//ll dfs1(vector<ll>& c, vector<vector<Edge>>& nodes, int cur, int par) {
//    ll back_prop = 0;
//    for (auto & e : nodes[cur]) {
//        if (e.to == par) continue;
//        ll temp = dfs1(c, nodes, e.to, e.from);
//        e.val -= temp;
//        back_prop += temp;
//    }
//    c[cur] = back_prop;
//    for (auto & e : nodes[cur]) {
//        if (e.to == par) {
//            back_prop += e.val;
//        }
//    }
//    return back_prop;
//}
//
//void dfs2(vector<ll>& c, const vector<vector<Edge>>& nodes, int cur, int par, ll val) {
//    c[cur] += val;
//    for (auto & e : nodes[cur]) {
//        if (e.to == par) continue;
//        dfs2(c, nodes, e.to, e.from, c[cur] + e.val);
//    }
//}
//
//int main() {
//    int n;
//    cin >> n;
//    vector<vector<Edge>> nodes(n);
//    vector<Edge> edges[2];
//    for (int i = 0; i < n - 1; ++i) {
//        int a, b;
//        cin >> a >> b;
//        a--; b--;
//        edges[0].push_back(Edge {a, b, 0});
//        edges[1].push_back(Edge {b, a, 0});
//    }
//    int q;
//    cin >> q;
//    for (int i = 0; i < q; ++i) {
//        ll t, e, x;
//        cin >> t >> e >> x;
//        edges[2 - t][--e].val += x;
//    }
//    for (int i = 0; i < n - 1; ++i) {
//        auto e = edges[0][i];
//        nodes[e.from].push_back(e);
//        e = edges[1][i];
//        nodes[e.from].push_back(e);
//    }
//    vector<ll> c(n);
//    int start = 0;
//    while (nodes[start].size() != 1) {
//        start++;
//    }
//    dfs1(c, nodes, start, -1);
//    dfs2(c, nodes, start, -1, 0);
//    for (int i = 0; i < n; ++i) {
//        cout << c[i] << endl;
//    }
//}
