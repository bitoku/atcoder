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
    ll n, k, l;
    cin >> n >> k >> l;
    UnionFind rail(n);
    UnionFind road(n);
    for (int i = 0; i < k; ++i) {
        int p, q;
        cin >> p >> q;
        p--; q--;
        rail.unite(p, q);
    }
    for (int i = 0; i < l; ++i) {
        int r, s;
        cin >> r >> s;
        r--; s--;
        road.unite(r, s);
    }
    map<pair<ll, ll>, ll> m;
    for (int i = 0; i < n; ++i) {
        m[make_pair(rail.root(i), road.root(i))]++;
    }
    for (int i = 0; i < n; ++i) {
        cout << m[make_pair(rail.root(i), road.root(i))] << endl;
    }
}
