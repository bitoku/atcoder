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
    ll n, m;
    cin >> n >> m;
    vector<ll> inconv(m+1);
    inconv[m] = n * (n - 1) / 2;
    UnionFind uf(n);
    vector<pair<int, int>> bridge(m);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        bridge[i] = make_pair(a, b);
    }
    for (int i = m-1; i >= 0 ; --i) {
        int a = bridge[i].first;
        int b = bridge[i].second;
        if (uf.same(a, b)) {
            inconv[i] = inconv[i+1];
        } else {
            inconv[i] = inconv[i+1] - uf.count(a) * uf.count(b);
        }
        uf.unite(a, b);
    }
    for (int i = 1; i <= m; ++i) {
        cout << inconv[i] << endl;
    }
}
