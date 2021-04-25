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

int main() {
    ll n, m;
    cin >> n >> m;
    UnionFind uf(n + m);
    for (int i = 0; i < n; ++i) {
        ll k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            ll l;
            cin >> l;
            uf.unite(i, n + l - 1);
        }
    }
    ll root = uf.root(0);
    for (int i = 1; i < n; ++i) {
        if (root != uf.root(i)) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}