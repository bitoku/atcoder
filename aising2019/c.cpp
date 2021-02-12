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
    vector<int> black;
    UnionFind(unsigned long n): parent(n), rank(n, 0), size(n, 1), black(n, 0) {
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
            black[y] += count_black(x);
            parent[x] = y;
        } else {
            size[x] += count(y);
            black[x] += count_black(y);
            parent[y] = x;
            if (rank[x] == rank[y]) rank[x]++;
        }
    }

    int count_black(int x) {
        return black[root(x)];
    }

    int count_white(int x) {
        return size[root(x)] - black[root(x)];
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }
};

template<class T>
void printVector(vector<T> &a) {
    if (a.size() == 0) return;
    cout << a[0];
    for (int i = 1; i < a.size(); ++i) {
        cout << " " << a[i];
    }
    cout << endl;
}

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; ++i) {
        cin >> s[i];
    }
    UnionFind uf(h*w);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            uf.black[i * w + j] = s[i][j] == '#' ? 1 : 0;
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int dirs[4][2] = {
              {-1, 0},
              {0, -1},
              {1, 0},
              {0, 1},
            };
            for (const auto & dir : dirs) {
                int ni = i + dir[0];
                int nj = j + dir[1];
                if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
                if (s[i][j] == s[ni][nj]) continue;
//                cout << uf.count(i * w + j) << ' ' << uf.count(ni * w + nj) << endl;
                uf.unite(i * w + j, ni * w + nj);
//                printf("(%d, %d) (%d, %d)\n", i, j, ni, nj);
//                cout << uf.count(i*w + j) << endl;
            }
        }
    }
    set<int> parent;
    for (int i = 0; i < h * w; ++i) {
        parent.insert(uf.root(i));
    }
    ll result = 0;
    for (const auto p : parent) {
        result += (ll)uf.count_black(p) * uf.count_white(p);
    }
    cout << result << endl;
}
