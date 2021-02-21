#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

struct Edge {
    int to;
    int cost;
};
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> edges(n);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        edges[a].push_back(Edge {b, c});
    }
    vector<vector<int>> dist(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
        bool loop = false;
        pq.push(make_pair(0, i));
        while (!pq.empty()) {
            auto x = pq.top(); pq.pop();
            ll cur_cost = x.first;
            int cur = x.second;
            if (cur == i && cur_cost > 0) {
                cout << cur_cost << endl;
                loop = true;
                break;
            }
            if (dist[i][cur] != 0) continue;
            dist[i][cur] = cur_cost;
            for (const auto& e : edges[cur]) {
                ll next_cost = e.cost + cur_cost;
                if (dist[i][e.to] != 0 && next_cost >= dist[i][e.to]) continue;
                pq.push(make_pair(next_cost, e.to));
            }
        }
        if (!loop) cout << -1 << endl;
    }
}
