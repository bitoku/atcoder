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
    ll n, m;
    cin >> n >> m;
    UnionFind uf(n);
    vector<vector<pair<int, ll>>> v(n);
    vector<int> rightcnt(n);
    for (int i = 0; i < m; ++i) {
        int l, r;
        ll d;
        cin >> l >> r >> d;
        l--; r--;
        v[l].emplace_back(r, d);
        uf.unite(l, r);
        rightcnt[r]++;
    }
    vector<ll> dist(n, -1);
    vector<bool> done(n);
    int group = 0;
    for (int i = 0; i < n; ++i) {
        if (rightcnt[i] > 0) continue;
        group++;
        dist[i] = 0;
        deque<int> dq;
        dq.push_back(i);
        while (!dq.empty()) {
            int k = dq.front(); dq.pop_front();
            done[k] = true;
            for (auto [x, d]: v[k]) {
                if (dist[x] != -1 && dist[x] != dist[k] + d) {
                    cout << "No" << endl;
                    return 0;
                }
                dist[x] = dist[k] + d;
                if (done[x]) continue;
                dq.push_back(x);
                done[x] = true;
            }
        }
    }
    set<int> s;
    for (int i = 0; i < n; ++i) {
        s.insert(uf.root(i));
    }
    if (group == s.size()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}