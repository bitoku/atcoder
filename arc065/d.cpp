#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// SOLVED: 08/23

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
    UnionFind uf1(n), uf2(n);
    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        uf1.unite(a, b);
    }
    for (int i = 0; i < l; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        uf2.unite(a, b);
    }
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n; ++i) {
        mp[make_pair(uf1.root(i), uf2.root(i))]++;
    }
    cout << mp[make_pair(uf1.root(0), uf2.root(0))];
    for (int i = 1; i < n; ++i) {
        cout << ' ' << mp[make_pair(uf1.root(i), uf2.root(i))];
    }
    cout << endl;
}