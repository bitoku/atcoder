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
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<ll> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    UnionFind uf(n);
    for (int i = 0; i < m; ++i) {
        int c, d;
        cin >> c >> d;
        c--; d--;
        uf.unite(c, d);
    }
    map<ll, ll> asum, bsum;
    for (int i = 0; i < n; ++i) {
        asum[uf.root(i)] += a[i];
        bsum[uf.root(i)] += b[i];
    }
    for (const auto [k, x]: asum) {
        if (bsum[k] != x) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
