#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

// TODO: solve without editorial

struct Edge {
    int from;
    int to;
    int dist;
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> edges(n + 1);
    for (int i = 0; i < m; ++i) {
        int l, r, d;
        cin >> l >> r >> d;
        edges[l].push_back({l, r, d});
        edges[r].push_back({r, l, -d});
    }
    vector<ll> x(n+1, LONG_LONG_MAX);
    deque<int> dq;
    for (int i = 1; i <= n; ++i) {
        if (x[i] != LONG_LONG_MAX) continue;
        dq.push_back(i);
        x[i] = 0;
        while (!dq.empty()) {
            int from = dq.front(); dq.pop_front();
            for (const auto & edge : edges[from]) {
                if (x[edge.to] != LONG_LONG_MAX) {
                    if (x[edge.to] != x[from] + edge.dist) {
                        cout << "No" << endl;
                        return 0;
                    }
                    continue;
                }
                x[edge.to] = x[from] + edge.dist;
                dq.push_back(edge.to);
            }
        }
    }
    cout << "Yes" << endl;
}
