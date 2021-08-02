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
    int h, w;
    cin >> h >> w;
    ll q;
    cin >> q;
    UnionFind uf(h * w);
    vector<vector<bool>> red(h + 2, vector<bool>(w + 2));
    for (int i = 0; i < q; ++i) {
        int x;
        cin >> x;
        if (x == 1) {
            int r, c;
            cin >> r >> c;
            red[r][c] = true;
            if (red[r+1][c]) uf.unite((r-1) * w + c-1, r * w + c-1);
            if (red[r][c+1]) uf.unite((r-1) * w + c-1, (r-1) * w + c);
            if (red[r-1][c]) uf.unite((r-1) * w + c-1, (r-2) * w + c-1);
            if (red[r][c-1]) uf.unite((r-1) * w + c-1, (r-1) * w + c-2);
        }
        if (x == 2) {
            int ra, ca, rb, cb;
            cin >> ra >> ca >> rb >> cb;
            if (red[ra][ca] && red[rb][cb] && uf.same((ra-1)*w + (ca-1), (rb-1)*w + (cb-1))) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
}