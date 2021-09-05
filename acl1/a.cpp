#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// TODO: 09/05(stack)

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
    vector<tuple<int, int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        v[i] = {x, y, i};
    }
    sort(v.begin(), v.end());
    UnionFind uf(n);
    stack<pair<int, int>> st;
    for (int i = 0; i < n; ++i) {
        auto [x, y, idx] = v[i];
        if (st.empty() || st.top().first > y) {
            st.push({y, idx});
            continue;
        }
        auto t = st.top();
        while (!st.empty() && st.top().first < y) {
            uf.unite(st.top().second, idx);
            st.pop();
        }
        st.push(t);
    }
    for (int i = 0; i < n; ++i) {
        cout << uf.count(i) << endl;
    }
}