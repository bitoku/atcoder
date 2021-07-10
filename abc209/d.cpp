#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

void dfs(vector<vector<int>>& edges, int cur, int par, int d, vector<vector<int>>& parent, vector<int>& depth) {
    depth[cur] = d;
    for (auto x: edges[cur]) {
        if (x == par) continue;
        parent[0][x] = cur;
        dfs(edges, x, cur, d+1, parent, depth);
    }
}

int main() {
    ll n, q;
    cin >> n >> q;
    vector<vector<int>> edge(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    vector<vector<int>> parent(20, vector<int>(n));
    vector<int> depth(n);
    dfs(edge, 0, -1, 0, parent, depth);
    for (int i = 1; i < 20; ++i) {
        for (int j = 0; j < n; ++j) {
            parent[i][j] = parent[i-1][parent[i-1][j]];
        }
    }
    for (int i = 0; i < q; ++i) {
        int c, d;
        cin >> c >> d;
        c--; d--;
        int u = c;
        int v = d;
        if (depth[c] < depth[d]) swap(c, d);
        for (int j = 0; j < 20; ++j) {
            if ((depth[c] - depth[d]) >> j & 1) {
                c = parent[j][c];
            }
        }
        ll dist = 0;
        if (c != d) {
            for (int j = 19; j >= 0; --j) {
                if (parent[j][c] != parent[j][d]) {
                    c = parent[j][c];
                    d = parent[j][d];
                }
            }
        }
        dist = depth[u] - depth[c] + depth[v] - depth[c];
        if (dist % 2 == 0) {
            cout << "Town" << endl;
        } else {
            cout << "Road" << endl;
        }
    }
}