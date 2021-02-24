#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

struct Edge {
    int to;
    int cost;
};

int n, m, R;


int main() {
    cin >> n >> m >> R;
    vector<int> r(R);
    for (int i = 0; i < R; ++i) {
        cin >> r[i];
    }
    vector<vector<Edge>> edge(n+1);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back(Edge {b, c});
        edge[b].push_back(Edge {a, c});
    }
    int required[8][8] = {0};
    for (int i = 0; i < R; ++i) {
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
        vector<int> dist(n+1, -1);
        pq.push(make_pair(0, r[i]));
        while (!pq.empty()) {
            auto x = pq.top(); pq.pop();
            ll cur_c = x.first;
            int cur = x.second;
            if (dist[cur] != -1) continue;
            dist[cur] = cur_c;
            for (const auto e : edge[cur]) {
                if (dist[e.to] != -1 && e.cost + cur_c > dist[e.to]) continue;
                pq.push(make_pair(e.cost + cur_c, e.to));
            }
        }
        for (int j = 0; j < R; ++j) {
            required[i][j] = dist[r[j]];
        }
    }
    vector<vector<ll>> length(1 << R, vector<ll>(R, INT_MAX));
    for (int i = 0; i < R; ++i) {
        length[1 << i][i] = 0;
    }
    for (int i = 1; i < (1 << R); ++i) {
        for (int j = 0; j < R; ++j) {
            for (int k = 0; k < R; ++k) {
                if (i & (1 << k)) continue;
                length[i + (1 << k)][k] = min(length[i + (1 << k)][k], length[i][j] + required[j][k]);
            }
        }
    }
    ll result = INT_MAX;
    for (int i = 0; i < R; ++i) {
        result = min(result, (ll)length[(1 << R) - 1][i]);
    }
    cout << result << endl;
}

//ll dfs(vector<vector<int>>& length, const int dist[8][8], int s, int cur) {
//    if (length[s][cur] > 0) {
//        return length[s][cur];
//    }
//    if (s == (1 << R) - 1) {
//        return 0;
//    }
//    ll result = INT_MAX;
//    for (int i = 0; i < R; ++i) {
//        if (s & (1 << i)) continue;
//        result = min(result, dfs(length, dist, s + (1 << i), i) + dist[cur][i]);
//    }
//    length[s][cur] = result;
//    return result;
//}
//
//int main() {
//    cin >> n >> m >> R;
//    vector<int> r(R);
//    for (int i = 0; i < R; ++i) {
//        cin >> r[i];
//    }
//    vector<vector<Edge>> edge(n+1);
//    for (int i = 0; i < m; ++i) {
//        int a, b, c;
//        cin >> a >> b >> c;
//        edge[a].push_back(Edge {b, c});
//        edge[b].push_back(Edge {a, c});
//    }
//    int required[8][8] = {0};
//    for (int i = 0; i < R; ++i) {
//        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
//        vector<int> dist(n+1, -1);
//        pq.push(make_pair(0, r[i]));
//        while (!pq.empty()) {
//            auto x = pq.top(); pq.pop();
//            ll cur_c = x.first;
//            int cur = x.second;
//            if (dist[cur] != -1) continue;
//            dist[cur] = cur_c;
//            for (const auto e : edge[cur]) {
//                if (dist[e.to] != -1 && e.cost + cur_c > dist[e.to]) continue;
//                pq.push(make_pair(e.cost + cur_c, e.to));
//            }
//        }
//        for (int j = 0; j < R; ++j) {
//            required[i][j] = dist[r[j]];
//        }
//    }
//    ll result = INT_MAX;
//    vector<vector<int>> length(1 << R, vector<int>(R, 0));
//    for (int i = 0; i < R; ++i) {
//        result = min(result, dfs(length, required, 0 & (1 << i), i));
//    }
//    cout << result << endl;
//}
