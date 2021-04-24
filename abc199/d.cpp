#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: solve without editorial

class UnionFind {
private:
    vector<int> parent;
    vector<ll> size;
public:
    UnionFind(unsigned long n): parent(n), size(n, 1) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    ll count(int x) {
        return size[root(x)];
    }

    int root(int x) {
        if (parent[x] == x) return x;
        return parent[x] = root(parent[x]);
    }

    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;

        if (size[x] > size[y]) {
            parent[y] = x;
            size[x] += size[y];
        } else {
            parent[x] = y;
            size[y] += size[x];
        }
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }
};


ll n;
ll ans = 0;
int c[21];

void dfs(vector<vector<int>>& graph, vector<int>& idx, ll cur) {
    if (cur == idx.size()) {
        ans++;
        return;
    }
    int p = idx[cur];
    for (int i = 1; i <= 3; ++i) {
        bool b = true;
        for (const auto x: graph[p]) {
            if (i == c[x]) {
                b = false;
                break;
            }
        }
        if (!b) continue;
        c[p] = i;
        dfs(graph, idx, cur+1);
        c[p] = 0;
    }
}

int main() {
    ll m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    UnionFind uf(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
        uf.unite(a, b);
    }
    for (int i = 0; i < n; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n; ++i) {
        mp[uf.root(i)].push_back(i);
    }
    ll result = 1;
    for (auto& [x, v]: mp) {
        ans = 0;
        dfs(graph, v, 0);
        result *= ans;
    }
    cout << result << endl;
}