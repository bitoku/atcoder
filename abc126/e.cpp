#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;
public:
    UnionFind(unsigned long n): parent(n), rank(n, 0), size(n, 1) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int count(int x) {
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

        if (rank[x] < rank[y]) {
            size[y] += count(x);
            parent[x] = y;
        } else {
            size[x] += count(y);
            parent[y] = x;
            if (rank[x] == rank[y]) rank[x]++;
        }
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        x--; y--;
        uf.unite(x, y);
    }
    set<int> parent;
    for (int i = 0; i < n; ++i) {
        parent.insert(uf.root(i));
    }
    cout << parent.size() << endl;
}
