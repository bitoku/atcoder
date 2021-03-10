#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

// TODO: solve without editorial

struct Edge {
    int from;
    int to;
    int c;
};

int n, m;

void dfs(vector<vector<Edge>>& tree, int cur, int x, vector<int>& num) {
    num[cur] = x;
    for (const auto & edge : tree[cur]) {
        if (x == edge.c) {
            dfs(tree, edge.to, (x + 1) % n + 1, num);
        } else {
            dfs(tree, edge.to, edge.c, num);
        }
    }
}

int main() {
    cin >> n >> m;
    vector<vector<Edge>> edges(n+1);
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        edges[u].push_back({u, v, c});
        edges[v].push_back({v, u, c});
    }
    vector<vector<Edge>> tree(n+1);
    vector<bool> included(n+1);
    deque<int> dq;
    dq.push_back(1);
    included[1] = true;
    while (!dq.empty()) {
        int x = dq.front(); dq.pop_front();
        for (const auto & edge: edges[x]) {
            if (included[edge.to]) continue;
            tree[x].push_back(edge);
            included[edge.to] = true;
            dq.push_back(edge.to);
        }
    }
    vector<int> num(n + 1);
    dfs(tree, 1, 1, num);
    for (int i = 1; i <= n; ++i) {
        cout << num[i] << endl;
    }
}
