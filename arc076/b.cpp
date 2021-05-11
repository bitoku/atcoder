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
    vector<ll> x(n);
    vector<ll> y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    vector<ll> xi(n);
    vector<ll> yi(n);
    iota(xi.begin(), xi.end(), 0);
    iota(yi.begin(), yi.end(), 0);
    sort(xi.begin(), xi.end(), [&](ll i, ll j) {return x[i] < x[j];});
    sort(yi.begin(), yi.end(), [&](ll i, ll j) {return y[i] < y[j];});
    UnionFind uf(n);
    multiset<tuple<ll, int, int>> s;
    for (int i = 0; i < n-1; ++i) {
        s.insert(make_tuple(x[xi[i+1]] - x[xi[i]], xi[i], xi[i+1]));
        s.insert(make_tuple(y[yi[i+1]] - y[yi[i]], yi[i], yi[i+1]));
    }
    ll result = 0;
    for (auto [k, i, j]: s) {
        if (uf.same(i, j)) continue;
        result += k;
        uf.unite(i, j);
    }
    cout << result << endl;
}