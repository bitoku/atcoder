#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

// SOLVED: 06/22

struct Edge {
    int to;
    int c;
};

vector<int> result;
ll n, m;

void dfs(vector<vector<Edge>>& edges, int cur) {
    for (auto& e: edges[cur]) {
        if (result[e.to] != -1) continue;
        if (result[cur] != e.c) result[e.to] = e.c;
        else result[e.to] = (result[cur] + 1) % (int)n + 1;
        dfs(edges, e.to);
    }
}

int main() {
    cin >> n >> m;
    vector<vector<Edge>> edges(n);
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        u--; v--;
        edges[u].push_back({v, c});
        edges[v].push_back({u, c});
    }
    result.resize(n, -1);
    result[0] = edges[0].front().c;
    dfs(edges, 0);
    for (int i = 0; i < n; ++i) {
        cout << result[i] << endl;
    }
}