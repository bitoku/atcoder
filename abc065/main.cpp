#include <bits/stdc++.h>
using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
public:
    UnionFind(unsigned long n): parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
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
            parent[x] = y;
        } else {
            parent[y] = x;
            if (rank[x] == rank[y]) rank[x]++;
        }
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }
};

struct city {
    int num;
    int x, y;
};

int main() {
    int N;
    cin >> N;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pcities;
    vector<city> cities;
    for (int i = 0; i < N; ++i) {
        city c;
        cin >> c.x >> c.y;
        c.num = i;
        cities.push_back(c);
    }
    sort(cities.begin(), cities.end(), [](const city& a, const city& b) {
        return a.x < b.x;
    });
    for (int i = 1; i < N; ++i) {
        pcities.push(make_tuple(cities[i].x - cities[i-1].x, cities[i-1].num, cities[i].num));
    }

    sort(cities.begin(), cities.end(), [](const city& a, const city& b) {
        return a.y < b.y;
    });
    for (int i = 1; i < N; ++i) {
        pcities.push(make_tuple(cities[i].y - cities[i-1].y, cities[i-1].num, cities[i].num));
    }
    UnionFind uf(N);
    int res = 0;
    while(!pcities.empty()) {
        auto cinfo = pcities.top();
        pcities.pop();
        if (uf.same(get<1>(cinfo), get<2>(cinfo))) continue;
        uf.unite(get<1>(cinfo), get<2>(cinfo));
        res += get<0>(cinfo);
    }
    cout << res << endl;
}
