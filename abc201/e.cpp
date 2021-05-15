#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;


struct Edge {
    ll from;
    ll to;
    ll w;
};

void dfs(vector<vector<Edge>>& tree, int cur, int par, vector<ll>& dist) {
    for (auto x: tree[cur]) {
        if (x.to == par) continue;
        dist[x.to] = x.w ^ dist[cur];
        dfs(tree, x.to, cur, dist);
    }
}

int main() {
    ll n;
    cin >> n;
    vector<vector<Edge>> tree(n);
    for (int i = 0; i < n-1; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        tree[u].push_back({u, v, w});
        tree[v].push_back({v, u, w});
    }
    vector<ll> dist(n);
    dfs(tree, 0, -1, dist);
    vector<ll> bit(60);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 60; ++j) {
            if (dist[i] & (1ll << j)) {
                bit[j]++;
            }
        }
    }
    ll result = 0;
    for (int i = 0; i < 60; ++i) {
        result += (1ll << i) % mod * bit[i] % mod * (n - bit[i]) % mod;
        result %= mod;
    }
    cout << result << endl;
}