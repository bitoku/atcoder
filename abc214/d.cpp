#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

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

int main() {
    ll n;
    cin >> n;
    vector<tuple<ll, int, int>> vv(n-1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--; v--;
        vv[i] = {w, u, v};
    }
    sort(vv.begin(), vv.end());
    UnionFind uf(n);
    ll result = 0;
    for (auto [w, u, v]: vv) {
        result += w * uf.count(u) * uf.count(v);
        uf.unite(u, v);
    }
    cout << result << endl;
}