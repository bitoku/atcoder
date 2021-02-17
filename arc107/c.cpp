#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

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

struct Factorial {
    vector<ll> memo;

    Factorial(): memo(100) {
        memo[1] = 1;
    }

    ll fact(int n) {
       if (memo[n] > 0) return memo[n];
       memo[n] = n * fact(n-1) % mod;
       return memo[n];
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    UnionFind row(n);
    UnionFind col(n);
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            bool swappable = true;
            for (int l = 0; l < n; ++l) {
                if (a[i][l] + a[j][l] > k) {
                    swappable = false;
                    break;
                }
            }
            if (swappable) {
                row.unite(i, j);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            bool swappable = true;
            for (int l = 0; l < n; ++l) {
                if (a[l][i] + a[l][j] > k) {
                    swappable = false;
                    break;
                }
            }
            if (swappable) {
                col.unite(i, j);
            }
        }
    }
    ll result = 1;
    set<int> parents_row;
    set<int> parents_col;
    Factorial f;
    for (int i = 0; i < n; ++i) {
        parents_row.insert(row.root(i));
    }
    for (int i = 0; i < n; ++i) {
        parents_col.insert(col.root(i));
    }
    for (const auto& parent: parents_row) {
        result = result * f.fact(row.count(parent)) % mod;
    }
    for (const auto& parent: parents_col) {
        result = result * f.fact(col.count(parent)) % mod;
    }
    cout << result << endl;
}
