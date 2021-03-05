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

bool is_num(char c) {
    return '0' <= c && c <= '9';
}

int main() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    UnionFind uf(36);
    bool used[26] = {};
    for (int i = 0; i < n; ++i) {
        int ss = is_num(s[i]) ? s[i] - '0' : s[i] - 'A' + 10;
        int tt = is_num(t[i]) ? t[i] - '0' : t[i] - 'A' + 10;
        if (ss >= 10) used[ss-10] = true;
        if (tt >= 10) used[tt-10] = true;
        uf.unite(ss, tt);
    }
    unsigned long long result = 1;
    for (int i = 0; i < 26; ++i) {
        if (!used[i]) continue;
        bool num = false;
        for (int j = 0; j < 10; ++j) {
            if (uf.same(i + 10, j)) {
                num = true;
                break;
            }
        }
        if (!num) {
            vector<int> v(i);
            iota(v.begin(), v.end(), 0);
            if (all_of(v.begin(), v.end(), [uf, i](int j) mutable { return !uf.same(i + 10, j + 10); })) {
                if ((!is_num(s[0]) && uf.same(s[0] - 'A' + 10, i + 10)) ||
                    (!is_num(t[0]) && uf.same(t[0] - 'A' + 10, i + 10)))
                {
                    result *= 9;
                } else {
                    result *= 10;
                }
            }
        }
    }
    cout << result << endl;
}
