#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

bool is_tree(const vector<vector<int>>& graph, vector<bool>& visited, int root, int parent) {
    if (visited[root]) return false;
    visited[root] = true;
    bool result = true;
    for (const int & i : graph[root]) {
        if (i == parent) continue;
        result = result && is_tree(graph, visited, i, root);
    }
    return result;
}

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
    int n;
    cin >> n;
    UnionFind uf(400001);
    vector<vector<int>> v(400001);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        uf.unite(a, b);
    }
    set<int> parents;
    for (int i = 1; i <= 400000; ++i) {
        parents.insert(uf.root(i));
    }
    vector<bool> visited(400001);
    ll result = 0;
    for (const int& parent : parents) {
        if (v[parent].empty()) continue;
        if (is_tree(v, visited, parent, -1)){
            result += uf.count(parent)-1;
        } else {
            result += uf.count(parent);
        }
    }
    cout << result << endl;
}

//int main() {
//    int n;
//    cin >> n;
//    vector<multiset<int>> v(400001);
//    for (int i = 0; i < n; ++i) {
//        int a, b;
//        cin >> a >> b;
//        v[a].insert(b);
//        v[b].insert(a);
//    }
//    deque<int> one;
//    for (int i = 0; i < 400001; ++i) {
//        if (v[i].empty()) continue;
//        if (v[i].size() == 1) one.push_back(i);
//    }
//    ll result = 0;
//    while (!one.empty()) {
//        int x = one.front(); one.pop_front();
//        if (v[x].empty()) continue;
//        result++;
//        int y = *v[x].begin();
//        auto itx = v[y].find(x);
//        v[y].erase(itx);
//        if (v[y].size() == 1) one.push_back(y);
//    }
//    for (int i = 0; i < 400001; ++i) {
//        if (v[i].size() >= 2) result++;
//    }
//    cout << result << endl;
//}
