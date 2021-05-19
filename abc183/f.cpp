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
    vector<map<int, ll>> cls;
public:
    UnionFind(unsigned long n): parent(n), size(n, 1) {
        cls.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    void init(int x, int c) {
        cls[x][c]++;
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
            for (auto [k, v]: cls[y]) cls[x][k] += v;
            parent[y] = x;
            size[x] += size[y];
        } else {
            for (auto [k, v]: cls[x]) cls[y][k] += v;
            parent[x] = y;
            size[y] += size[x];
        }
    }

    ll clscount(int x, int y) {
        return cls[root(x)][y];
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }
};


int main() {
    ll n, q;
    cin >> n >> q;
    UnionFind uf(n);
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        c--;
        uf.init(i, c);
    }
    for (int i = 0; i < q; ++i) {
        int k, a, b;
        cin >> k >> a >> b;
        a--;
        b--;
        if (k == 1) {
            uf.unite(a, b);
        } else {
            cout << uf.clscount(a, b) << endl;
        }
    }
}