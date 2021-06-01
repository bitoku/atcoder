#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

struct Edge {
    int id;
    int to;
    ll cost;
};

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> dist(n, vector<ll>(n, -1));
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }
    vector<int> neighbor;
    for (int i = 0; i < m; ++i) {
        int u, v, l;
        cin >> u >> v >> l;
        u--; v--;
        if (u == 0) neighbor.push_back(v);
        dist[u][v] = l;
        dist[v][u] = l;
    }
    for (int k = 1; k < n; ++k) {
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < n; ++j) {
                if (dist[i][k] == -1 || dist[k][j] == -1) continue;
                if (dist[i][j] == -1 || dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    ll result = LONG_LONG_MAX;
    for (int i = 0; i < neighbor.size(); ++i) {
        for (int j = i+1; j < neighbor.size(); ++j) {
            int a = neighbor[i], b = neighbor[j];
            if (dist[a][b] == -1) continue;
            result = min(result, dist[0][a] + dist[a][b] + dist[b][0]);
        }
    }
    if (result == LONG_LONG_MAX) cout << -1 << endl;
    else cout << result << endl;
}