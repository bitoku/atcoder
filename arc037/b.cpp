#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    vector<int> loop;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        if (uf.root(u) == uf.root(v)) {
            loop.push_back(uf.root(u));
        } else {
            uf.unite(u, v);
        }
    }
    set<int> parent;
    for (int i = 0; i < n; ++i) {
        parent.insert(uf.root(i));
    }
    for (int i = 0; i < loop.size(); ++i) {
        parent.erase(uf.root(loop[i]));
    }
    cout << parent.size() << endl;
}
