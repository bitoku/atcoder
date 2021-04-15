#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: solve

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
    vector<pair<ll, ll>> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i].first >> x[i].second;
        x[i].first--; x[i].second--;
    }
    vector<int> ids(n);
    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(), [&](int i, int j) { return x[i] < x[j]; });
    UnionFind uf(n);
    set<pair<int, int>> s;
    for (auto i: ids) {
        if (s.empty() || s.begin()->first > x[i].second) s.insert(make_pair(x[i].second, i));
        else {
            auto it = s.begin();
            uf.unite(i, it->second);
            ++it;
            for (; it != s.end() && it->first < x[i].second ;) {
                uf.unite(i, it->second);
                it = s.erase(it);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << uf.count(i) << endl;
    }
}
