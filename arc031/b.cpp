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
    vector<string> a(10);
    for (int i = 0; i < 10; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            vector<string> b = a;
            UnionFind uf(101);
            b[i][j] = 'o';
            for (int k = 0; k < 10; ++k) {
                for (int l = 0; l < 10; ++l) {
                    if (b[k][l] == 'x') {
                        uf.unite(k * 10 + l, 100);
                        continue;
                    }
                    int dirs[4][2] = {
                            {-1, 0},
                            {0, -1},
                            {1, 0},
                            {0, 1}
                    };
                    for (auto & dir : dirs) {
                        int ni = k + dir[0];
                        int nj = l + dir[1];
                        if (ni < 0 || ni >= 10 || nj < 0 || nj >= 10) continue;
                        if (b[ni][nj] == 'o') {
                            uf.unite(k * 10 + l, ni * 10 + nj);
                        }
                    }
                }
            }
            set<int> parents;
            for (int k = 0; k < 100; ++k) {
                parents.insert(uf.root(k));
            }
            if (parents.size() == 2) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
}
